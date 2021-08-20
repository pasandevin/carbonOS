    #ifndef INCLUDE_FRAMEBUFFER_H
    #define INCLUDE_FRAMEBUFFER_H
    #include "io.h"

    /* The I/O ports */
    #define FB_COMMAND_PORT         0x3D4
    #define FB_DATA_PORT            0x3D5

    /* The I/O port commands */
    #define FB_HIGH_BYTE_COMMAND    14
    #define FB_LOW_BYTE_COMMAND     15

    
    #define FB_GREEN     2
    #define FB_DARK_GREY 8
    #define FB_BLACK     0
    #define FB_BLUE      1
    #define FB_GREEN     2
    #define FB_RED       4
    #define FB_DARK_GREY 8
    #define FB_WHITE     15

    
     void fb_write_cell(unsigned int i, char c, unsigned char fg, unsigned char bg);
    
     void fb_move_cursor(unsigned short pos);
    
     int fb_write(char *buf, unsigned int len);
    
    #endif
    
