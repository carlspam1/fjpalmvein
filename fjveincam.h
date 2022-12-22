/*
 * USB PalmSecure Sensor driver (kernel-2.6)
 *
 * Copyright (C) 2012 FUJITSU FRONTECH LIMITED
 *
 *	This program is free software; you can redistribute it and/or
 *	modify it under the terms of the GNU General Public License version
 *	2 as published by the Free Software Foundation.
 *
 * Notes:
 *
 * History:
 *
 * 2012-07-06 - V31L01
 *	 - first version
 *
 */
#ifndef _FJVEINCAM_
#define _FJVEINCAM_

/*----------------------------------------------------------------------*/
/* ioctl																*/
/*----------------------------------------------------------------------*/
// Berore V30 Authentication Library use.
#define USB_FJVEINCAMV30_IOCTL_CTRLMSG 	0x01
#define USB_FJVEINCAMV30_IOCTL_CHECK	0x02
#define USB_FJVEINCAMV30_IOCTL_INFO		0x03
#define USB_FJVEINCAMV30_IOCTL_CONFIRM 	0x04
// V31 Authentication Library or later version use.
#define USB_FJVEINCAM_IOCTL_CTRLMSG 	_IOWR(0xB4,0x01,struct fjveincam_cmsg)
#define USB_FJVEINCAM_IOCTL_CHECK		_IO(0xB4,0x02)
#define USB_FJVEINCAM_IOCTL_INFO		_IOR(0xB4,0x03,struct fjveincam_info)
#define USB_FJVEINCAM_IOCTL_CONFIRM 	_IO(0xB4,0x04)

/* for USB_FJVEINCAM_IOCTL_CTRLMSG */

struct fjveincam_cmsg {
	struct {
		unsigned char bRequestType;
		unsigned char bRequest;
		unsigned short wValue;
		unsigned short wIndex;
		unsigned short wLength;
	} req;						/* USB device control request data */
	void *data; 				/* response data area pointer */
};

/* for USB_FJVEINCAM_IOCTL_CHECK */

	/* no structure */

/* for USB_FJVEINCAM_IOCTL_INFO */

/* Magic number for Fujitsu Palmsecure sensor driver. */
#define FJPV_MAGIC	0x464A5056

struct fjveincam_info {
	int magic;					/* Magic number for indicating Fujitsu Palmsecure sensor driver. */
	int minor;					/* minor number */
	int o_timeout;				/* counter of open time out */
	int r_error;				/* counter of read error */
	int r_lasterr;				/* read last error */
	int w_error;				/* counter of write error */
	int w_lasterr;				/* write last error */
	unsigned char version[8];	/* device driver version string */
};

#endif	/* _FJVEINCAM_ */
