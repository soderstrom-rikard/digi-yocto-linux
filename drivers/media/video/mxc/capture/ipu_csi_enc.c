/*
 * Copyright 2009-2011 Freescale Semiconductor, Inc. All Rights Reserved.
 */

/*
 * The code contained herein is licensed under the GNU General Public
 * License. You may obtain a copy of the GNU General Public License
 * Version 2 or later at the following locations:
 *
 * http://www.opensource.org/licenses/gpl-license.html
 * http://www.gnu.org/copyleft/gpl.html
 */

/*!
 * @file ipu_csi_enc.c
 *
 * @brief CSI Use case for video capture
 *
 * @ingroup IPU
 */

#include <linux/dma-mapping.h>
#include <linux/ipu.h>
#include "mxc_v4l2_capture.h"
#include "ipu_prp_sw.h"

#ifdef CAMERA_DBG
	extern void ipu_dump_registers(void);
	#define CAMERA_TRACE(x) printk(x)
#else
	#define CAMERA_TRACE(x)
#endif

/*
 * Function definitions
 */

/*!
 * csi ENC callback function.
 *
 * @param irq       int irq line
 * @param dev_id    void * device id
 *
 * @return status   IRQ_HANDLED for handled
 */
static irqreturn_t csi_enc_callback(int irq, void *dev_id)
{
	cam_data *cam = (cam_data *) dev_id;

	if (cam->enc_callback == NULL)
		return IRQ_HANDLED;

	cam->enc_callback(irq, dev_id);
	return IRQ_HANDLED;
}

/*!
 * CSI ENC enable channel setup function
 *
 * @param cam       struct cam_data * mxc capture instance
 *
 * @return  status
 */
static int csi_enc_setup(cam_data *cam)
{
	ipu_channel_params_t params;
	u32 pixel_fmt;
	int err = 0, sensor_protocol = 0;
	dma_addr_t dummy = cam->dummy_frame.buffer.m.offset;
	ipu_channel_t channel;

	CAMERA_TRACE("In csi_enc_setup\n");
	if (!cam) {
		printk(KERN_ERR "cam private is NULL\n");
		return -ENXIO;
	}

	memset(&params, 0, sizeof(ipu_channel_params_t));
	params.csi_mem.csi = cam->csi;

	sensor_protocol = ipu_csi_get_sensor_protocol(cam->csi);
	switch (sensor_protocol) {
	case IPU_CSI_CLK_MODE_GATED_CLK:
	case IPU_CSI_CLK_MODE_NONGATED_CLK:
	case IPU_CSI_CLK_MODE_CCIR656_PROGRESSIVE:
	case IPU_CSI_CLK_MODE_CCIR1120_PROGRESSIVE_DDR:
	case IPU_CSI_CLK_MODE_CCIR1120_PROGRESSIVE_SDR:
		params.csi_mem.interlaced = false;
		break;
	case IPU_CSI_CLK_MODE_CCIR656_INTERLACED:
	case IPU_CSI_CLK_MODE_CCIR1120_INTERLACED_DDR:
	case IPU_CSI_CLK_MODE_CCIR1120_INTERLACED_SDR:
		params.csi_mem.interlaced = true;
		break;
	default:
		printk(KERN_ERR "sensor protocol unsupported\n");
		return -EINVAL;
	}

	if (cam->v2f.fmt.pix.pixelformat == V4L2_PIX_FMT_YUV420)
		pixel_fmt = IPU_PIX_FMT_YUV420P;
	else if (cam->v2f.fmt.pix.pixelformat == V4L2_PIX_FMT_YUV422P)
		pixel_fmt = IPU_PIX_FMT_YUV422P;
	else if (cam->v2f.fmt.pix.pixelformat == V4L2_PIX_FMT_UYVY)
		pixel_fmt = IPU_PIX_FMT_UYVY;
	else if (cam->v2f.fmt.pix.pixelformat == V4L2_PIX_FMT_YUYV)
		pixel_fmt = IPU_PIX_FMT_YUYV;
	else if (cam->v2f.fmt.pix.pixelformat == V4L2_PIX_FMT_NV12)
		pixel_fmt = IPU_PIX_FMT_NV12;
	else if (cam->v2f.fmt.pix.pixelformat == V4L2_PIX_FMT_BGR24)
		pixel_fmt = IPU_PIX_FMT_BGR24;
	else if (cam->v2f.fmt.pix.pixelformat == V4L2_PIX_FMT_RGB24)
		pixel_fmt = IPU_PIX_FMT_RGB24;
	else if (cam->v2f.fmt.pix.pixelformat == V4L2_PIX_FMT_RGB565)
		pixel_fmt = IPU_PIX_FMT_RGB565;
	else if (cam->v2f.fmt.pix.pixelformat == V4L2_PIX_FMT_BGR32)
		pixel_fmt = IPU_PIX_FMT_BGR32;
	else if (cam->v2f.fmt.pix.pixelformat == V4L2_PIX_FMT_RGB32)
		pixel_fmt = IPU_PIX_FMT_RGB32;
	else {
		printk(KERN_ERR "format not supported\n");
		return -EINVAL;
	}

	ipu_csi_enable_mclk_if(CSI_MCLK_ENC, cam->csi, true, true);

	if (cam->csi == 0)
		channel = CSI_MEM0;
	else
		channel = CSI_MEM1;

	err = ipu_init_channel(channel, &params);
	if (err != 0) {
		printk(KERN_ERR "ipu_init_channel %d\n", err);
		return err;
	}

	err = ipu_init_channel_buffer(channel, IPU_OUTPUT_BUFFER,
				      pixel_fmt, cam->v2f.fmt.pix.width,
				      cam->v2f.fmt.pix.height,
				      cam->v2f.fmt.pix.width, cam->rotation,
				      dummy, dummy, 0,
				      cam->offset.u_offset,
				      cam->offset.v_offset);
	if (err != 0) {
		printk(KERN_ERR "CSI_MEM%d output buffer\n",cam->csi);
		return err;
	}
	err = ipu_enable_channel(channel);
	if (err < 0) {
		printk(KERN_ERR "ipu_enable_channel CSI_MEM%d\n",cam->csi);
		return err;
	}

	return err;
}

/*!
 * function to update physical buffer address for encorder IDMA channel
 *
 * @param eba         physical buffer address for encorder IDMA channel
 * @param buffer_num  int buffer 0 or buffer 1
 *
 * @return  status
 */
static int csi_enc_eba_update(int csi, dma_addr_t eba, int *buffer_num)
{
	int err = 0;
	ipu_channel_t channel;

	if (csi == 0)
		channel = CSI_MEM0;
	else
		channel = CSI_MEM1;

	err = ipu_update_channel_buffer(channel, IPU_OUTPUT_BUFFER,
					*buffer_num, eba);

	if (err != 0) {
		ipu_clear_buffer_ready(channel, IPU_OUTPUT_BUFFER,
				       *buffer_num);
		printk(KERN_ERR "err %d buffer_num %d\n", err, *buffer_num);
		return err;
	}

	ipu_select_buffer(channel, IPU_OUTPUT_BUFFER, *buffer_num);

	*buffer_num = (*buffer_num == 0) ? 1 : 0;

#ifdef CAMERA_DBG
	ipu_dump_registers ();
#endif

	return 0;
}

/*!
 * Enable encoder task
 * @param private       struct cam_data * mxc capture instance
 *
 * @return  status
 */
static int csi_enc_enabling_tasks(void *private)
{
	cam_data *cam = (cam_data *) private;
	int err = 0;
	int ipu_irq_csi_out_eof;
	CAMERA_TRACE("IPU:In csi_enc_enabling_tasks\n");

	cam->dummy_frame.vaddress = dma_alloc_coherent(0,
			       PAGE_ALIGN(cam->v2f.fmt.pix.sizeimage),
			       &cam->dummy_frame.paddress,
			       GFP_DMA | GFP_KERNEL);
	if (cam->dummy_frame.vaddress == 0) {
		pr_err("ERROR: v4l2 capture: Allocate dummy frame "
		       "failed.\n");
		return -ENOBUFS;
	}
	cam->dummy_frame.buffer.type = V4L2_BUF_TYPE_PRIVATE;
	cam->dummy_frame.buffer.length =
	    PAGE_ALIGN(cam->v2f.fmt.pix.sizeimage);
	cam->dummy_frame.buffer.m.offset = cam->dummy_frame.paddress;

	if (cam->csi == 0)
		ipu_irq_csi_out_eof = IPU_IRQ_CSI0_OUT_EOF;
	else
		ipu_irq_csi_out_eof = IPU_IRQ_CSI1_OUT_EOF;
	ipu_clear_irq(ipu_irq_csi_out_eof);
	err = ipu_request_irq(ipu_irq_csi_out_eof,
				csi_enc_callback, 0, "Mxc Camera", cam);

	if (err != 0) {
		printk(KERN_ERR "Error registering eot irq for csi %d\n",cam->csi);
		return err;
	}

	err = csi_enc_setup(cam);
	if (err != 0) {
		printk(KERN_ERR "csi_enc_setup %d\n", err);
		return err;
	}

	return err;
}

/*!
 * Disable encoder task
 * @param private       struct cam_data * mxc capture instance
 *
 * @return  int
 */
static int csi_enc_disabling_tasks(void *private)
{
	cam_data *cam = (cam_data *) private;
	int err = 0;
	ipu_channel_t channel;
	int ipu_irq_csi_out_eof;

	if (cam->csi == 0)
	{
		channel = CSI_MEM0;
		ipu_irq_csi_out_eof = IPU_IRQ_CSI0_OUT_EOF;
	}
	else
	{
		channel = CSI_MEM1;
		ipu_irq_csi_out_eof = IPU_IRQ_CSI1_OUT_EOF;
	}

	ipu_free_irq(ipu_irq_csi_out_eof, cam);
	err = ipu_disable_channel(channel, true);

	ipu_uninit_channel(channel);

	if (cam->dummy_frame.vaddress != 0) {
		dma_free_coherent(0, cam->dummy_frame.buffer.length,
				  cam->dummy_frame.vaddress,
				  cam->dummy_frame.paddress);
		cam->dummy_frame.vaddress = 0;
	}
	ipu_csi_enable_mclk_if(CSI_MCLK_ENC, cam->csi, false, false);

	return err;
}

/*!
 * Enable csi
 * @param private       struct cam_data * mxc capture instance
 *
 * @return  status
 */
static int csi_enc_enable_csi(void *private)
{
	cam_data *cam = (cam_data *) private;

	return ipu_enable_csi(cam->csi);
}

/*!
 * Disable csi
 * @param private       struct cam_data * mxc capture instance
 *
 * @return  status
 */
static int csi_enc_disable_csi(void *private)
{
	cam_data *cam = (cam_data *) private;

	return ipu_disable_csi(cam->csi);
}

/*!
 * function to select CSI ENC as the working path
 *
 * @param private       struct cam_data * mxc capture instance
 *
 * @return  int
 */
int csi_enc_select(void *private)
{
	cam_data *cam = (cam_data *) private;
	int err = 0;

	if (cam) {
		cam->enc_update_eba = csi_enc_eba_update;
		cam->enc_enable = csi_enc_enabling_tasks;
		cam->enc_disable = csi_enc_disabling_tasks;
		cam->enc_enable_csi = csi_enc_enable_csi;
		cam->enc_disable_csi = csi_enc_disable_csi;
	} else {
		err = -EIO;
	}

	return err;
}

/*!
 * function to de-select CSI ENC as the working path
 *
 * @param private       struct cam_data * mxc capture instance
 *
 * @return  int
 */
int csi_enc_deselect(void *private)
{
	cam_data *cam = (cam_data *) private;
	int err = 0;

	if (cam) {
		cam->enc_update_eba = NULL;
		cam->enc_enable = NULL;
		cam->enc_disable = NULL;
		cam->enc_enable_csi = NULL;
		cam->enc_disable_csi = NULL;
	}

	return err;
}

/*!
 * Init the Encorder channels
 *
 * @return  Error code indicating success or failure
 */
__init int csi_enc_init(void)
{
	return 0;
}

/*!
 * Deinit the Encorder channels
 *
 */
void __exit csi_enc_exit(void)
{
}

module_init(csi_enc_init);
module_exit(csi_enc_exit);

EXPORT_SYMBOL(csi_enc_select);
EXPORT_SYMBOL(csi_enc_deselect);

MODULE_AUTHOR("Freescale Semiconductor, Inc.");
MODULE_DESCRIPTION("CSI ENC Driver");
MODULE_LICENSE("GPL");
