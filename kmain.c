    #include "drivers/framebuffer.h"
    #include "drivers/serial_port.h"
    #include "segmentation/memory_segments.h"
    #include "interrupts/keyboard.h"
    #include "interrupts/interrupts.h"


    
    int main(){

           char ptr2[] = "Welcome to CarbonOS";
   
    
    serial_write(0x3F8, ptr2, 19);
    fb_write(ptr2, 19);

    segments_install_gdt();
    interrupts_install_idt();
    
    }
