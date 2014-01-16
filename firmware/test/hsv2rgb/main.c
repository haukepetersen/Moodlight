
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "color.h"



int main(int argc, char **argv)
{
    puts("Hello Testme");

    if (argc != 4) {
        puts("Wrong number of parameters");
        printf("Usage: %s red green blue\n", argv[0]);
    }
    
    uint16_t hsv[3];
    uint8_t rgb[3];
    // parse cmd-line parameters
    hsv[0] = atoi(argv[1]);
    hsv[1] = atoi(argv[2]);
    hsv[2] = atoi(argv[3]);

    printf("Input values:\n H: %i\n S: %i\n V: %i\n", hsv[0], hsv[1], hsv[2]);

    color_hsv2rgb(hsv, rgb);

    printf("\nConverted values:\n");
    printf(" R: %i\n G: %i\n B: %i\n", rgb[0], rgb[1], rgb[2]);




    
    return 0;
}
