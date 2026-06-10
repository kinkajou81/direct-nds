#pragma once

typedef union {
	struct data {
		uint8_t red : 5;
		uint8_t green : 5;
		uint8_t blue : 5;
	};
	uint16_t val;
} palette_color;
