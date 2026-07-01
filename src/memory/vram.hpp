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

// 4000240h - NDS9 - VRAMCNT_A - VRAM-A (128K) Bank Control (W)
// 4000241h - NDS9 - VRAMCNT_B - VRAM-B (128K) Bank Control (W)
// 4000242h - NDS9 - VRAMCNT_C - VRAM-C (128K) Bank Control (W)
// 4000243h - NDS9 - VRAMCNT_D - VRAM-D (128K) Bank Control (W)
// 4000244h - NDS9 - VRAMCNT_E - VRAM-E (64K) Bank Control (W)
// 4000245h - NDS9 - VRAMCNT_F - VRAM-F (16K) Bank Control (W)
// 4000246h - NDS9 - VRAMCNT_G - VRAM-G (16K) Bank Control (W)
// 4000248h - NDS9 - VRAMCNT_H - VRAM-H (32K) Bank Control (W)
// 4000249h - NDS9 - VRAMCNT_I - VRAM-I (16K) Bank Control (W)
typedef union {
	struct data {
		uint8_t vram_mst : 3;
		uint8_t vram_offset : 4; // last 2 bits unused
		bool enable : 1;
	};
	uint8_t val;
} VRAMCNT;
typedef VRAMCNT VRAMCNT_A;
typedef VRAMCNT VRAMCNT_B;
typedef VRAMCNT VRAMCNT_C;
typedef VRAMCNT VRAMCNT_D;
typedef VRAMCNT VRAMCNT_E;
typedef VRAMCNT VRAMCNT_F;
typedef VRAMCNT VRAMCNT_G;
typedef VRAMCNT VRAMCNT_H;
typedef VRAMCNT VRAMCNT_I;
#define REG_VRAMCNT_A 0x4000240
#define REG_VRAMCNT_B 0x4000241
#define REG_VRAMCNT_C 0x4000242
#define REG_VRAMCNT_D 0x4000243
#define REG_VRAMCNT_E 0x4000244
#define REG_VRAMCNT_F 0x4000245
#define REG_VRAMCNT_G 0x4000246
#define REG_VRAMCNT_H 0x4000248
#define REG_VRAMCNT_I 0x4000249
