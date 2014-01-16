
#include "color.h"



#define R   0
#define G   1
#define B   2

#define H   0
#define S   1
#define V   2


/******************************************************************************
  Tis function converts HSV values to RGB values, scaled from 0 to maxBrightness

   The ranges for the input variables are:
   hue: 0-360
   sat: 0-255
   lig: 0-255

   The ranges for the output variables are:
   r: 0-maxBrightness
   g: 0-maxBrightness
   b: 0-maxBrightness
                     
   r,g, and b are passed as pointers, because a function cannot have 3 return variables
   Use it like this:
   int hue, sat, val; 
   unsigned char red, green, blue;
   // set hue, sat and val
   hsv2rgb(hue, sat, val, &red, &green, &blue, maxBrightness); //pass r, g, and b as the location where the result should be stored
   // use r, b and g.
                              
   (c) Elco Jacobs, E-atelier Industrial Design TU/e, July 2011.
*****************************************************************************/
void color_hsv2rgb(uint16_t *hsv, uint8_t *rgb)
{
    uint8_t accent = hsv[H] / 60;
    uint8_t bottom = ((255 - hsv[S]) * hsv[V]) >> 8;
    uint8_t top = hsv[V];
    uint8_t rising = ((top - bottom) * (hsv[H] % 60)) / 60 + bottom;
    uint8_t falling = ((top - bottom) * (60 - (hsv[H] % 60))) / 60 + bottom;
    
    switch(accent) {
        case 0:
            rgb[R] = top;
            rgb[G] = rising;
            rgb[B] = bottom;
        break;
        case 1:
            rgb[R] = falling;
            rgb[G] = top;
            rgb[B] = bottom;
        break;
        case 2:
            rgb[R] = bottom;
            rgb[G] = top;
            rgb[B] = rising;
        break;
        case 3:
            rgb[R] = bottom;
            rgb[G] = falling;
            rgb[B] = top;
        break;
        case 4:
            rgb[R] = rising;
            rgb[G] = bottom;
            rgb[B] = top;
        break;
        case 5:
            rgb[R] = top;
            rgb[G] = bottom;
            rgb[B] = falling;
        break;
    }

    // scale values to max brightness
    // rgb[R] = rgb[R] * maxBrightness / 255;
    // ...
}

void color_rgb2hsv(uint8_t *rgb, uint8_t *hsv)
{

}

