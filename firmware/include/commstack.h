

#include "uart.h"


#define COMM_CMD_RGB_SET        0x43  // 'C'


void commstack_init(uart_t dev, uint32_t baudrate);