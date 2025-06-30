#include "ad7779.h"
#include "linux_spi.h"
#include "no_os_delay.h"
#include <stdio.h>
#include <stdint.h>

#define AD7779_REG_CHIP_ID 0x00

int main(void)
{
	ad7779_dev *dev;
	ad7779_init_param init_param;
	int ret;
	uint8_t chip_id;

	// SPI config only
	init_param.spi_init.device_id = 0;
	init_param.spi_init.max_speed_hz = 1000000;
	init_param.spi_init.mode = NO_OS_SPI_MODE_0;
	init_param.spi_init.bit_order = NO_OS_SPI_BIT_ORDER_MSB_FIRST;
	init_param.spi_init.chip_select = 0;
	init_param.spi_init.platform_ops = &linux_spi_ops;

	// Ignore GPIOs completely — not needed
	// Set minimum required init config for AD7779
	init_param.ctrl_mode = AD7779_SPI_CTRL;
	init_param.spi_crc_en = AD7779_DISABLE;
	init_param.ref_type = AD7779_INT_REF;
	init_param.pwr_mode = AD7779_LOW_PWR;
	init_param.dclk_div = AD7779_DCLK_DIV_1;
	init_param.read_from_cache = false;

	for (int i = 0; i < 8; i++) {
		init_param.state[i] = AD7779_ENABLE;
		init_param.gain[i] = AD7779_GAIN_1;
		init_param.offset_corr[i] = 0;
		init_param.gain_corr[i] = 0;
		init_param.sync_offset[i] = 0;
	}
	init_param.dec_rate_int = 0;
	init_param.dec_rate_dec = 0;
	init_param.ref_buf_op_mode[0] = AD7779_REF_BUF_ENABLED;
	init_param.ref_buf_op_mode[1] = AD7779_REF_BUF_ENABLED;
	init_param.sinc5_state = AD7779_ENABLE;

	// Initialize device
	ret = ad7779_init(&dev, init_param);
	if (ret) {
		printf("AD7779 init failed: %d\n", ret);
		return ret;
	}
	printf("AD7779 initialized successfully.\n");

	// Read CHIP ID register
	ret = ad7779_spi_int_reg_read(dev, AD7779_REG_CHIP_ID, &chip_id);
	if (ret == 0)
		printf("AD7779 CHIP ID (0x00): 0x%02X\n", chip_id);
	else
		printf("Failed to read CHIP ID: %d\n", ret);

	ad7779_remove(dev);
	return 0;
}

