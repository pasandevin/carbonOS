    #include "frame_buffer.h"
    #include "serial_port.h"


    
    int main(){

           char ptr2[] = "Welcome to CarbonOS";
   
    
    serial_write(0x3F8, ptr2, 19);
    fb_write(ptr2, 19);
    
    }
