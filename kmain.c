#include "drivers/framebuffer.h"
#include "drivers/serial_port.h"
#include "segmentation/memory_segments.h"
#include "interrupts/keyboard.h"
#include "interrupts/interrupts.h"

void init_segments_interrupts(){
	segments_install_gdt();
	interrupts_install_idt();

}

int kmain(){
	init_segments_interrupts();
	char ptr2[] = "Welcome to CarbonOS!     ";


	serial_write(0x3F8, ptr2, 25);
	fb_write(ptr2, 25);


	return 0;

}
