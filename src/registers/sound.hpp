#pragma once

static constexpr auto clampf = [](float x, float lbound, float rbound) {
	float y = (x>=lbound)?x:lbound;
	y = (y<=rbound)?y:rbound;
	return y;
}

static constexpr auto clamp = [](uint8_t x, uint8_t lbound, uint8_t rbound) {
	uint8_t y = (x>=lbound)?x:lbound;
	y = (y<=rbound)?y:rbound;
	return y;
}

constexpr uint8_t calc_volume(float percentage) { 
	// percentage 0-100
	float y1 = clampf(percentage, 0f, 100f);
	uint y2 = (uint)__builin_truncf(y1/100f * 127f);
	return clamp( (uint8_t)y2, 0, 127);
}

constexpr uint8_t calc_volume_x(float percentage, float panning) { // handles panning
	// percentage 0..100; panning -100..100
	float y1 = clampf(percentage, 0f, 100f);
	float pan = clampf(panning, -100f, 100f);
	float max_panned_volume = __builtin_fmaxf(100f-panning, panning)/2f;
	uint y2 = (uint)__builin_truncf( (y1/100f)/(max_panned_volume/100f) * 127f);
	return clamp( (uint8_t)y2, 0, 127);
}

constexpr uint8_t calc_pan(float panning) {
	// panning -100..100
	float y1 = clampf(panning, -100f, 100f);
	uint y2 = (int)__builtin_truncf(-0.00005 * y1 * y1 + 127 * y1/200) + 64; // quadratic due to funky mapping
	return clamp( (uint8_t)y2, 0, 127);
}

// 40004x0h - NDS7 - SOUNDxCNT - Sound Channel X Control Register (R/W)
typedef union {
	struct data {
		uint8_t volume_mul : 7;
		uint8_t none : 1;
		uint8_t volume_div : 2;
		uint8_t none2 : 5;
		bool hold : 1;
		uint8_t pan : 7;
		uint8_t none3 : 1;
		uint8_t wave_duty : 3;
		uint8_t repeat_mode : 2;
		uint8_t format : 2;
		bool status : 1;
	};
	uint32_t val;
} SOUNDxCNT;
