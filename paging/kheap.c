
#include "kheap.h"

// kernel_end is defined in the linker script.
extern u32int kernel_virtual_end;
u32int placement_address = (u32int)&kernel_virtual_end;

u32int kmalloc(u32int size) {
	u32int mem =  placement_address;
	placement_address += size;
	return mem;
}

u32int kmalloc_page() {
	if (placement_address & 0xFFFFF000) { // not alligned 
        	// Align the placement address;
		placement_address &= 0xFFFFF000;
		placement_address += 0x1000;
    	}
	return kmalloc(0x1000);
}


