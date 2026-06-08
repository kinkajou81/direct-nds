#pragma once

// ----- ldr variants -----

sainline uint8_t ldrb(ptr addr) {
	return *(uint8_t*)address;
}

sainline uint16_t ldrh(ptr addr) {
	return *(uint16_t*)address;
}

sainline int32_t ldrsb(ptr addr) {
	return (int32_t)(*(uint8_t*)address);
}

sainline int32_t ldrsh(ptr addr) {
	return (int32_t)(*(uint16_t*)address);
}

sainline uint32_t ldr(ptr addr) {
	return *(uint32_t*)address;
}

sainline uint64_t ldrd(ptr addr) {
	return *(uint64_t*)address;
}

// ----- str variants -----

sainline void strb(uint8_t data, ptr addr) {
	*(uint8_t*)r = data;
}

sainline void strh(uint16_t data, ptr addr) {
	*(uint16_t*)r = data;
}

sainline void str(uint32_t data, ptr addr) {
	*(uint32_t*)r = data;
}

sainline void strd(uint64_t data, ptr addr) {
	*(uint64_t*)r = data;
}
