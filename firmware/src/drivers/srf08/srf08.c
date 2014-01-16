

#include "drivers/srf08.h"


void srf08_init(void)
{
    uint8_t a = 14;
    --a;
    printf("Say hello to my new driver: %i\n", a);
}
