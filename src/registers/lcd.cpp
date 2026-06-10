#include "lcd.hpp" // exposed here

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
