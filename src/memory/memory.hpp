#pragma once

// memory sections (ARM9)
#define MEMSEC_ARM9_INSTRUCTION_TCM 0x00000000
#define MEMSEC_ARM9_MAIN_MEMORY 0x02000000
#define MEMSEC_ARM9_SHARED_WRAM 0x03000000
#define MEMSEC_ARM9_IO_PORTS 0x04000000
#define MEMSEC_ARM9_STD_PALETTES 0x05000000
#define MEMSEC_ARM9_VRAM_ENGINE_A_BG 0x06000000
#define MEMSEC_ARM9_VRAM_ENGINE_B_BG 0x06200000
#define MEMSEC_ARM9_VRAM_ENGINE_A_OBJ 0x06400000
#define MEMSEC_ARM9_VRAM_ENGINE_B_OBJ 0x06600000
#define MEMSEC_ARM9_VRAM_LCDC 0x06800000
#define MEMSEC_ARM9_OAM 0x07000000
#define MEMSEC_ARM9_GBA_SLOT_ROM 0x08000000
#define MEMSEC_ARM9_GBA_SLOT_RAM 0x0A000000
#define MEMSEC_ARM9_BIOS 0xFFFF0000

// memory sections (ARM7)
#define MEMSEC_ARM7_BIOS 0x00000000
#define MEMSEC_ARM7_MAIN_MEMOR 0x02000000
#define MEMSEC_ARM7_SHARED_WRAM 0x03000000
#define MEMSEC_ARM7_WRAM 0x03800000
#define MEMSEC_ARM7_IO 0x04000000
#define MEMSEC_ARM7_WIRELESS_COM_WAIT_STATE_0 0x04800000
#define MEMSEC_ARM7_WIRELESS_COM_WAIT_STATE_1 0x04808000
#define MEMSEC_ARM7_VRAM 0x06000000
#define MEMSEC_ARM7_GBA_SLOT_ROM 0x08000000
#define MEMSEC_ARM7_GBA_SLOT_RAM 0x0A000000

// 4000204h - NDS9 - EXMEMCNT - External Memory Control (R/W)
// 4000204h - NDS7 - EXMEMSTAT - External Memory Status (R/W)
typedef union { // WORD
	struct data {
		uint8_t 32_pin_gba_slot_sram_access_time : 2;
		uint8_t 32_pin_gba_slot_rom_1st_access_time : 2;
		uint8_t 32_pin_gba_slot_rom_2nd_access_time : 1;
		uint8_t 32_pin_gba_slot_phi_pin_out : 2;
		uint8_t 32_pin_gba_slot_access_rights : 1;
		uint8_t none : 3;
		uint8_t 17_pin_nds_slot_access_rights : 1;
		uint8_t none2 : 2;
		uint8_t main_memory_interface_mode_switch : 1;
		uint8_t main_memory_access_priority : 1;
	};
	uint16_t val;
} EXMEMCNT;
#define REG_EXMEMCNT 0x4000204;
#define REG_EXMEMSTAT 0x4000204;
typedef EXMEMCNT EXMEMSTAT;
#define MEM_ARM9 0
#define MEM_ARM7 1

// 4000247h - NDS9 - WRAMCNT - WRAM Bank Control (R/W)
// 4000241h - NDS7 - WRAMSTAT - WRAM Bank Status (R)
typedef union { // HWORD
	uint8_t data;
	uint8_t val;
} WRAMCNT;
#define REG_WRAMCNT 0x4000247
#define REG_WRAMSTAT 0x4000241
typedef WRAMWNT WRAMSTAT;
