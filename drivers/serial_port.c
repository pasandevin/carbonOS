#include "io.h"
#include "serial_port.h"
 
  
enum BaudRate { Baud_115200 = 1, Baud_57600, Baud_19200, Baud_9600 };
enum BaudRate divisor = Baud_115200;

void serial_configure_baud_rate(unsigned short com, unsigned short divisor) {
	outb(SERIAL_LINE_COMMAND_PORT(com),
	     SERIAL_LINE_ENABLE_DLAB);
	outb(SERIAL_DATA_PORT(com),
	     (divisor >> 8) & 0x00FF);
	outb(SERIAL_DATA_PORT(com),
	     divisor & 0x00FF);
}
    
void serial_configure_line(unsigned short com) {
	outb(SERIAL_LINE_COMMAND_PORT(com), 0x03);
}
    
    
void serial_configure_fifo_buffer(unsigned short com) {
	outb(SERIAL_FIFO_COMMAND_PORT(com), 0xC7);
}



void serial_configure_modem(unsigned short com) {
	outb(SERIAL_MODEM_COMMAND_PORT(com), 0x03);
}
    
    
int serial_is_transmit_fifo_empty(unsigned int com) {
	return inb(SERIAL_LINE_STATUS_PORT(com)) & 0x20;
}
    
    
void serial_write_byte(unsigned short port, char byteData) {
	outb(port, byteData);
}  
    
    
void serial_configure(unsigned short port, unsigned short baudRate) {
	serial_configure_baud_rate(port, baudRate );
	serial_configure_line(port);
	serial_configure_fifo_buffer(port);
	serial_configure_modem(port);
}
    
    
int serial_write(unsigned short com, char *buf, unsigned int len) {
	serial_configure(com , 4);
	unsigned int indexToBuffer = 0;
  	while (indexToBuffer < len) {
    		if (serial_is_transmit_fifo_empty(com)) {
      			serial_write_byte(com, buf[indexToBuffer]);
      			indexToBuffer++;
    		}
  	}
  return 0;
}
