#include "memory/memory.hpp"
#include "mem.hpp"

// include this file after main function

__attribute__((noreturn))
void _start(void) {
	volatile asm(
		"ldr  r0, =0x3003E80\n"
		"mov  sp, r0\n"
		:::"memory", "r0"
	);

	main();
}
