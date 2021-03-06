/*
 * dbmdx-spi.h  --  DBMDX SPI interface common functions
 *
 * Copyright (C) 2014 DSP Group
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */

#ifndef _DBMDX_SPI_H
#define _DBMDX_SPI_H

#define RETRY_COUNT				5

struct dbmdx_spi_private;

struct dbmdx_spi_data {
	u32		spi_speed;
	u32		read_chunk_size;
	u32		write_chunk_size;
	u32		dma_min_buffer_size;
	u8		read_buf[MAX_REQ_SIZE];
};



struct dbmdx_spi_private {
	struct device			*dev;
	struct dbmdx_spi_data		*pdata;
	struct spi_device		*client;
	struct chip_interface		chip;
	u16				post_pll_div;
};



ssize_t read_spi_data(struct dbmdx_private *p, void *buf, size_t len);
ssize_t send_spi_data(struct dbmdx_private *p, const void *buf,
			      size_t len);
ssize_t write_spi_data(struct dbmdx_private *p, const u8 *buf,
			      size_t len);
int send_spi_cmd_boot(struct dbmdx_spi_private *spi_p, u32 command);
ssize_t send_spi_cmd_va(struct dbmdx_private *p, u32 command,
				   u16 *response);
ssize_t send_spi_cmd_vqe(struct dbmdx_private *p,
	u32 command, u16 *response);
int spi_common_probe(struct spi_device *client);
int spi_common_remove(struct spi_device *client);

#endif
