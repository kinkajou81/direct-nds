#pragma once

typedef union {
	struct data {
		uint16_t tile_number : 10;
		bool horizonal_flip : 1;
		bool vertical_flip : 1;
		uint8_t palette_number : 4;
	};
	uint16_t val;
} text_tile;

typedef union {
	uint8_t data;
	uint8_t val;
} rot_scale_tile;

typedef union {
	struct data {
		uint8_t red : 5;
		uint8_t green : 5;
		uint8_t blue : 5;
		uint8_t alpha : 1;
	};
	uint16_t val;
} bg_15bit_color;

typedef union {
	uint8_t data;
	uint8_t val;
} bg_8bit_color;
