#include "drivers/framebuffer.h"
#include "drivers/serial_port.h"
#include "segmentation/memory_segments.h"
#include "interrupts/keyboard.h"
#include "interrupts/interrupts.h"
#include "user_mode/multiboot.h"

void init_segments_interrupts(){
	segments_install_gdt();
	interrupts_install_idt();

}

void kmain(unsigned int ebx){
	init_segments_interrupts();
	    multiboot_info_t *mbinfo = (multiboot_info_t *) ebx;

    
  


    	if(mbinfo->mods_count == 0){
    		char msg[]="Error: no module loaded";
    		fb_write(msg, sizeof(msg));
    	
    	}
    	    	else if(mbinfo->mods_count == 1){
    		char msg[]="One module successfully loaded";
    		fb_write(msg, sizeof(msg));
    		    multiboot_module_t* modules = (multiboot_module_t*) mbinfo->mods_addr;
        unsigned int address_of_module = modules->mod_start;
    	    	typedef void (*call_module_t)(void);
    	    	/* ... */
	    	call_module_t start_program = (call_module_t) address_of_module;
	    	start_program();
	    	/* we'll never get here, unless the module code returns */
	    	
    	}
    	else{
    	char msg[]="Error: multiplt modules loaded";
    	fb_write(msg, sizeof(msg));
    	 }
    	


	

}
