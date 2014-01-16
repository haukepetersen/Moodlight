
#include <stdint.h>


#ifndef __UARTBRIDGE_H
#define __UARTBRIDGE_H

void uartbridge_init(void);

void uartbridge_send1(char *data, uint16_t size);
void uartbridge_send2(char *data, uint16_t size);

#endif /* __UARTBRIDGE_H */