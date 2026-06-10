#pragma once
#include "../stdint.hpp"

static constexpr auto clamp = [](uint8_t x, uint8_t lbound, uint8_t rbound) {
	uint y = (x>=lbound)?x:lbound;
	y = (y<=rbound)?y:rbound;
	return y;
}

constexpr uint obj_pos(uint8_t obj, uint8_t attribute) {
	// clamp arguments
	uint8_t objc = clamp(obj, 0, 127);
	uint8_t attributec = clamp(attribute, 0, 2);
	
	return 0x07000000 + 8*objc + 2*attributec;
}

constexpr uint rot_scale_param_pos(uint8_t group, uint8_t param) {
	// param : 0 = A, 1 = B, 2 = C, 3 = D

	// clamp arguments
	uint8_t groupc = clamp(group, 0, 3);
	uint8_t paramc = clamp(param, 0, 31);

	uint8_t index = 4*group + param;

	// map index to address
	return 0x07000000 + 6 + 8*index;
}

typedef union {
	struct data {
		uint8_t y_coordinate : 8;
		bool rot_scale : 1;
		bool visible : 1;
		uint8_t obj_mode : 2;
		bool obj_mosaic : 1;
		uint8_t color_mode : 1;
		uint8_t obj_shape : 2;
	};
	uint16_t val;
} obj_attribute_0_normal;
typedef union {
	struct data {
		uint8_t y_coordinate : 8;
		bool rot_scale : 1;
		bool double_size : 1;
		uint8_t obj_mode : 2;
		bool obj_mosaic : 1;
		uint8_t color_mode : 1;
		uint8_t obj_shape : 2;
	};
	uint16_t val;
} obj_attribute_0_rot_scale;
#define OBJ_MODE_NORMAL 0
#define OBJ_MODE_SEMI_TRANSPARENT 1
#define OBJ_MODE_OBJ_WINDOW 2
#define OBJ_COLOR_MODE_16X16 0
#define OBJ_COLOR_MODE_256 1
#define OBJ_SHAPE_SQUARE 0
#define OBJ_SHAPE_HORIZONTAL 1
#define OBJ_SHAPE_VERTICAL 2
#define OBJ_DOUBLE_SIZE true
#define OBJ_VISIBLE true

typedef union {
	struct data {
		uint16_t x_coordinate : 9;
		uint8_t none : 3;
		bool horizontal_flip : 1;
		bool vertical_flip : 1;
		uint8_t size : 2;
	};
	uint16_t val;
} obj_attribute_1_normal;
typedef union {
	struct data {
		uint16_t x_coordinate : 9;
		uint8_t rot_scale_param_select : 5;
		uint8_t size : 2;
	};
	uint16_t val;
} obj_attribute_1_rot_scale;

typedef union {
	struct data {
		uint16_t character_name : 10;
		uint8_t priority : 2;
		uint8_t palette_number : 4;
	};
	uint16_t val;
} obj_attribute_2;
