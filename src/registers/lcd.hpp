#pragma once

// background rotations/scaling parameters A-D
consteval bg_transforms bg_rot_scale_a(float xmag, float angle) {
	float y = __builtin_cosf(angle)/xmag*256; // *256 to get fractional bits
	uint16_t r = (bg_transforms.val){(uint16_t)__builtin_truncatef(r)};
	return r;
}

consteval bg_transforms bg_rot_scale_b(float xmag, float angle) {
	float y = __builtin_sinf(angle)/xmag*256; // *256 to get fractional bits
	uint16_t r = (bg_transforms.val){(uint16_t)__builtin_truncatef(r)};
	return r;
}

consteval bg_transforms bg_rot_scale_c(float ymag, float angle) {
	float y = __builtin_sinf(angle)/ymag*256; // *256 to get fractional bits
	uint16_t r = (bg_transforms.val){(uint16_t)__builtin_truncatef(r)};
	return r;
}

consteval bg_transforms bg_rot_scale_d(float ymag, float angle) {
	float y = __builtin_cosf(angle)/ymag*256; // *256 to get fractional bits
	uint16_t r = (bg_transforms.val){(uint16_t)__builtin_truncatef(r)};
	return r;
}


// brightness coefficent
consteval uint8_t brightness_coef(float percentage) {
	float y = (percentage<=100)?pencentage:100f; // cap under 100
	float y = (percentage>=0)?pencentage:0f; // cap over 0
	return 0b11111&(uint8_t)__builtin_truncatef(percentage);
}



// 4000000h - DISPCNT - LCD Control (R/W)
typedef union {
	struct data {
		uint8_t bg_mode : 3;
		uint8_t BG0_selection : 1;
		uint8_t tile_obj_mapping : 1;
		uint8_t bitmap_obj_2d_dimension : 1;
		uint8_t bitmap_obj_mapping : 1;
		bool forced_blank : 1;
		bool screen_display_bg0 : 1;
		bool screen_display_bg1 : 1;
		bool screen_display_bg2 : 1;
		bool screen_display_bg3 : 1;
		bool screen_display_obj : 1;
		bool display_window0 : 1;
		bool display_window1 : 1;
		bool display_obj_window : 1;
		uint8_t display_mode : 2;
		uint8_t vram_block : 2;
		uint8_t tile_obj_1d_boundary : 2;
		uint8_t bitmap_obj_1d_boundary : 1;
		uint8_t obj_processing_during_hblank : 1;
		uint8_t character_base : 3;
		bool bg_extended_palettes : 1;
		bool obj_extended_palettes : 1;
	};
	uint32_t val;
} DISPCNT;
#define REG_DISPCNT_A 0x4000000
#define REG_DISPCNT_B 0x4001000
#define 2D_BG0 0
#define 3D_BG0 1
#define 2D_VRAM_MAP 0
#define 1D_VRAM_MAP 1
#define DISP_MODE_GRAPHICS_OFF 0
#define DISP_MODE_GRAPHICS_DISPLAY 1
#define DISP_MODE_ENGINE_A 2
#define DISP_MODE_ENGINE_B 3

// 4000004h - DISPSTAT - Genel LCD Status (R/W)
typedef union {
	struct data {
		bool vblank_flag : 1;
		bool hblank_flag : 1;
		bool vcounter_flag : 1;
		bool vblank_irq : 1;
		bool hblank_irq : 1;
		bool vcounter_irq : 1;
		bool lcd_init ready : 1;
		uint8_t msb_vcount_setting : 1;
		uint8_t vcount_setting : 8;
	};
	uint16_t val;
} DISPSTAT;
#define REG_DISPSTAT_A 0x4000004
#define REG_DISPSTAT_B 0x4001004

// 4000006h - VCOUNT - Vertical Counter (R)
typedef union {
	struct data {
		uint8_t scanline : 8;
		uint8_t msb_scanline : 1;
	};
	uint16_t val;
} VCOUNT;
#define REG_VCOUNT_A 0x4000006
#define REG_VCOUNT_B 0x4001006


// 4000008h - BG0CNT - BG0 Control (R/W) (BG Modes 0,1 only)
// 400000Ah - BG1CNT - BG1 Control (R/W) (BG Modes 0,1 only)
typedef union {
	struct data {
		uint8_t priority : 2;
		uint8_t char_base_box : 2;
		uint8_t msb_base_char : 2;
		bool mosaic : 1;
		uint8_t color_mode : 1;
		uint8_t screen_base_block : 5;
		uint8_t ext_palatte_slot : 1;
		uint8_t screen_size : 2;
	};
	uint16_t val;
} BGCNT1;
typedef BGCNT1 BG0CNT;
typedef BGCNT1 BG1CNT;
#define REG_BG0CNT_A 0x4000008
#define REG_BG0CNT_B 0x4001008
#define REG_BG1CNT_A 0x400000A
#define REG_BG1CNT_B 0x400100A

// 400000Ch - BG2CNT - BG2 Control (R/W) (BG Modes 0,1,2 only)
// 400000Eh - BG3CNT - BG3 Control (R/W) (BG Modes 0,2 only)
typedef union {
	struct data {
		uint8_t priority : 2;
		uint8_t char_base_box : 2;
		uint8_t msb_base_char : 2;
		bool mosaic : 1;
		uint8_t color_mode : 1;
		uint8_t screen_base_block : 5;
		uint8_t display_area_overflow : 1;
		uint8_t screen_size : 2;
	};
	uint16_t val;
} BGCNT2;
typedef BGCNT2 BG2CNT;
typedef BGCNT2 BG3CNT;
#define REG_BG2CNT_A 0x400000C
#define REG_BG2CNT_B 0x400100C
#define REG_BG3CNT_A 0x400000E
#define REG_BG3CNT_B 0x400100E
#define DISP_AREA_TRANSPARENT 0
#define DISP_AREA_WRAPAROUND 1

// 4000010h - BG0HOFS - BG0 X-Offset (W)
// 4000012h - BG0VOFS - BG0 Y-Offset (W)
// 4000014h - BG1HOFS - BG1 X-Offset (W)
// 4000016h - BG1VOFS - BG1 Y-Offset (W)
// 4000018h - BG2HOFS - BG2 X-Offset (W)
// 400001Ah - BG2VOFS - BG2 Y-Offset (W)
// 400001Ch - BG3HOFS - BG3 X-Offset (W)
// 400001Eh - BG3VOFS - BG3 Y-Offset (W)
typedef uint16_t BGOFS;
typedef uint16_t BG0HOFS;
typedef uint16_t BG0VOFS;
typedef uint16_t BG1HOFS;
typedef uint16_t BG1VOFS;
typedef uint16_t BG2HOFS;
typedef uint16_t BG2VOFS;
typedef uint16_t BG3HOFS;
typedef uint16_t BG3VOFS;
#define REG_BG0HOFS_A 0x4000010
#define REG_BG0HOFS_B 0x4001010
#define REG_BG0VOFS_A 0x4000012
#define REG_BG0VOFS_B 0x4001012
#define REG_BG1HOFS_A 0x4000014
#define REG_BG1HOFS_B 0x4001014
#define REG_BG1VOFS_A 0x4000016
#define REG_BG1VOFS_B 0x4001016
#define REG_BG2HOFS_A 0x4000018
#define REG_BG2HOFS_B 0x4001018
#define REG_BG2VOFS_A 0x400001A
#define REG_BG2VOFS_B 0x400101A
#define REG_BG3HOFS_A 0x400001C
#define REG_BG3HOFS_B 0x400101C
#define REG_BG3VOFS_A 0x400001E
#define REG_BG3VOFS_B 0x400101E

// 4000028h - BG2X - BG2 Reference Point X-Coordinate
// 400002Ch - BG2Y - BG2 Reference Point Y-Coordinate
// 4000038h - BG3X - BG3 Reference Point X-Coordinate
// 400003Ch - BG3Y - BG3 Reference Point Y-Coordinate
typedef union {
	struct data {
		uint8_t fractional : 8;
		uint8_t integer : 19;
		uint8_t sign : 1;
	};
	uint32 val;
} BGREF;
typedef BGREF BG2X;
typedef BGREF BG2Y;
typedef BGREF BG3X;
typedef BGREF BG3Y;
#define REG_BG2X_A 0x4000028
#define REG_BG2X_B 0x4001028
#define REG_BG2Y_A 0x400002C
#define REG_BG2Y_B 0x400102C
#define REG_BG3X_A 0x4000038
#define REG_BG3X_B 0x4001038
#define REG_BG3Y_A 0x400003C
#define REG_BG3Y_B 0x400103C

// 4000020h - BG2PA - BG2 Rotation/Scaling Parameter A (alias dx) (W)
// 4000022h - BG2PB - BG2 Rotation/Scaling Parameter B (alias dmx) (W)
// 4000024h - BG2PC - BG2 Rotation/Scaling Parameter C (alias dy) (W)
// 4000026h - BG2PD - BG2 Rotation/Scaling Parameter D (alias dmy) (W)
// 4000030h - BG3PA - BG3 Rotation/Scaling Parameter A (alias dx) (W)
// 4000032h - BG3PB - BG3 Rotation/Scaling Parameter B (alias dmx) (W)
// 4000034h - BG3PC - BG3 Rotation/Scaling Parameter C (alias dy) (W)
// 4000036h - BG3PD - BG3 Rotation/Scaling Parameter D (alias dmy) (W)
typedef union {
	struct data {
		uint8_t fractional : 8;
		uint8_t integer : 7;
		uint8_t sign : 1;
	};
	uint16_t val;
} BGRSP;
typedef BGRSP BG2PA;
typedef BGRSP BG2PB;
typedef BGRSP BG2PC;
typedef BGRSP BG2PD;
typedef BGRSP BG3PA;
typedef BGRSP BG3PB;
typedef BGRSP BG3PC;
typedef BGRSP BG3PD;
#define REG_BG2PA_A 0x4000020
#define REG_BG2PA_B 0x4001020
#define REG_BG2PB_A 0x4000022
#define REG_BG2PB_B 0x4001022
#define REG_BG2PC_A 0x4000024
#define REG_BG2PC_B 0x4001024
#define REG_BG2PD_A 0x4000026
#define REG_BG2PD_B 0x4001026
#define REG_BG3PA_A 0x4000030
#define REG_BG3PA_B 0x4001030
#define REG_BG3PB_A 0x4000032
#define REG_BG3PB_B 0x4001032
#define REG_BG3PC_A 0x4000034
#define REG_BG3PC_B 0x4001034
#define REG_BG3PD_A 0x4000036
#define REG_BG3PD_B 0x4001036

// 4000040h - WIN0H - Window 0 Horizontal Dimensions (W)
// 4000044h - WIN0V - Window 0 Vertical Dimensions (W)
// 4000042h - WIN1H - Window 1 Horizontal Dimensions (W)
// 4000046h - WIN1V - Window 1 Vertical Dimensions (W)
typedef union {
	struct data {
		uint8_t c2 : 8;
		uint8_t c1 : 8;
	};
	uint16_t val;
} WIND;
typedef WIND WIN0H;
typedef WIND WIN0V;
typedef WIND WIN1H;
typedef WIND WIN1V;
#define REG_WIN0H_A 0x4000040
#define REG_WIN0H_B 0x4001040
#define REG_WIN0V_A 0x4000044
#define REG_WIN0V_B 0x4001044
#define REG_WIN1H_A 0x4000042
#define REG_WIN1H_B 0x4001042
#define REG_WIN1V_A 0x4000046
#define REG_WIN1V_B 0x4001046

// 4000048h - WININ - Control of Inside of Window(s) (R/W)
typedef union {
	struct data {
		uint8_t win0_bg_bits : 4;
		bool win0_obj_bits : 1;
		bool win0_special : 1;
		uint8_t none1 : 2;
		uint8_t win1_bg_bits : 4;
		bool win1_obj_bits : 1;
		bool win1_special : 1;
		uint8_t none2 : 2;
	};
	uint16_t val;
} WININ;
#define REG_WININ_A 0x4000048
#define REG_WININ_B 0x4001048

// 400004Ah - WINOUT - Control of Outside of Windows & Inside of OBJ Window (R/W)
typedef union {
	struct data {
		uint8_t win_out_bg_bits : 4;
		bool win_out_obj_bits : 1;
		bool win_out_special : 1;
		uint8_t none1 : 2;
		uint8_t win_obj_bg_bits : 4;
		bool win_obj_obj_bits : 1;
		bool win_obj_special : 1;
		uint8_t none2 : 2;
	};
	uint16_t val;
} WINOUT;
#define REG_WINOUT_A 0x400004A
#define REG_WINOUT_B 0x400104A

// 400004Ch - MOSAIC - Mosaic Size (W)
typedef union {
	struct data {
		uint8_t bg_hsize : 4;
		uint8_t bg_vsize : 4;
		uint8_t obj_hsize : 4;
		uint8_t obj_vsize : 4;
	};
	uint16_t val;
} MOSAIC;
#define REG_MOSAIC_A 0x400004C
#define REG_MOSAIC_B 0x400104C

// 4000050h - BLDCNT - Color Special Effects Selection (R/W)
typedef union {
	struct data {
		bool BG0_target_px_1st : 1;
		bool BG1_target_px_1st : 1;
		bool BG2_target_px_1st : 1;
		bool BG3_target_px_1st : 1;
		bool OBJ_target_px_1st : 1;
		bool BD_target_px_1st : 1;
		uint8_t effect : 2;
		bool BG0_target_px_2nd : 1;
		bool BG1_target_px_2nd : 1;
		bool BG2_target_px_2nd : 1;
		bool BG3_target_px_2nd : 1;
		bool OBJ_target_px_2nd : 1;
		bool BD_target_px_2nd : 1;
	};
	uint16_t val;
} BLDCNT;
#define REG_BLDCNT_A 0x4000050
#define REG_BLDCNT_B 0x4001050

// 4000052h - BLDALPHA - Alpha Blending Coefficients (R/W)
typedef union {
	struct data {
		uint8_t EVA_coeff : 5; (1st target)
		uint8_t none : 3;
		uint8_t EVB_coeff : 5; (2nd target)
	};
	uint16_t val;
} BLDALPHA;
#define REG_BLDALPHA_A 0x4000052
#define REG_BLDALPHA_B 0x4001052

// 4000054h - BLDY - Brightness (Fade-In/Out) Coefficient (W)
typedef union {
	struct data {
		uint8_t EBY_coeff : 5; (Brightness)
	};
	uint32 val;
} BLDY;
#define REG_BLDY_A 0x4000054
#define REG_BLDY_B 0x4001054

// 400006Ch - NDS9 - MASTER_BRIGHT - Master Brightness Up/Down
typedef union {
	struct data {
		uint8_t brightness_factor : 5;
		uint16_t none : 9;
		uint8_t mode : 2;
	};
	uint16_t val;
} MASTER_BRIGHT;
#define REG_MASTER_BRIGHT_A 0x400006C
#define REG_MASTER_BRIGHT_B 0x400106C
