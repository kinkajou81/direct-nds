#pragma once

// 40001A0h - NDS7/NDS9 - AUXSPICNT - Gamecard ROM and SPI Control (R/W)
typedef union {
	struct data {
		uint8_t spi_baudrate : 2;
		uint8_t none : 4;
		uint8_t spi_hold_chipselect : 1;
		uint8_t spi_busy : 1;
		uint8_t none2 : 5;
		uint8_t nds_slot_mode : 1;
		bool transfer_ready_irq : 1;
		bool nds_slot_enable : 1;
	};
	uint16_t val;
} AUXSPICNT;
#define REG_AUXSPICNT 0x40001A0

// 40001A2h - NDS7/NDS9 - AUXSPIDATA - Gamecard SPI Bus Data/Strobe (R/W)
typedef union {
	uint8_t data;
	uint16_t val;
} AUXSPIDATA;
#define REG_AUXSPIDATA 0x40001A2

// 40001A4h - NDS7/NDS9 - ROMCTRL - Gamecard Bus ROMCTRL (R/W)
typedef union {
	struct data {
		uint16_t key1_gap1_length : 13;
		bool key2_encrypt_data : 2;
		bool key2_apply_seed : 1;
		uint8_t key1_gap2_length : 6;
		bool key2_encrypt_cmd : 1;
		bool data_word_status : 1;
		uint8_t data_block_size : 3;
		uint8_t transfer_clk_rate : 1;
		uint8_t key1_gap_clks : 1;
		bool resb_release_reset : 1;
		uint8_t data_direction_wr : 1;
		uint8_t block_status : 1;
	};
	uint32_t val;
} ROMCTRL;
#define REG_ROMCTRL 0x40001A4

// 40001A8h - NDS7/NDS9 - Gamecard bus 8-byte Command Out
typedef union {
	struct data {
		uint8_t 1st_cmd_byte;
		uint8_t 2nd_cmd_byte;
		uint8_t 3rd_cmd_byte;
		uint8_t 4th_cmd_byte;
		uint8_t 5th_cmd_byte;
		uint8_t 6th_cmd_byte;
		uint8_t 7th_cmd_byte;
		uint8_t 8th_cmd_byte;
	};
	uint64_t val;
} GC8CMDOUT;
#define REG_GC8CMDOUT 0x40001A8

// 4100010h - NDS7/NDS9 - Gamecard bus 4-byte Data In (R/W)
typedef union {
	struct data {
		uint8_t 1st_cmd_byte;
		uint8_t 2nd_cmd_byte;
		uint8_t 3rd_cmd_byte;
		uint8_t 4th_cmd_byte;
	};
	uint32_t val;
} GC4CMDIN;
#define REG_GC4CMDIN 0x4100010

// 40001B0h - 32bit - NDS7/NDS9 - Encryption Seed 0 Lower 32bit (W)
// 40001B4h - 32bit - NDS7/NDS9 - Encryption Seed 1 Lower 32bit (W)
typedef union {
	uint32_t data;
	uint32_t val;
} ESEEDL;
typedef ESEEDL ESEED0L;
typedef ESEEDL ESEED1L;
#define REG_ESEED0L 0x40001B0
#define REG_ESEED1L 0x40001B4

// 40001B8h - 16bit - NDS7/NDS9 - Encryption Seed 0 Upper 7bit (bit7-15 unused)
// 40001BAh - 16bit - NDS7/NDS9 - Encryption Seed 1 Upper 7bit (bit7-15 unused)
typedef union {
	uint8_t data;
	uint16_t val;
} ESEEDH;
typedef ESEEDH ESEED0H;
typedef ESEEDH ESEED1H;
#define REG_ESEED0H 0x40001B8
#define REG_ESEED1H 0x40001BA
