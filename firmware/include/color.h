
#include <stdint.h>


/**
 * @brief Convert a hsv color values to rgb values
 *
 * @param [in]  hsv     array containing the HSV values of the given color
 * @param [out] rgb     the results will be written in this array
 */
void color_hsv2rgb(uint16_t *hsv, uint8_t *rgb);


/**
 * @brief Convert rgb color values to hsv values
 *
 * @param [in]  rgb     array with the rgb values
 * @param [out] hsv     resulting hsv values
 */
void color_rgb2hsv(uint8_t *rgb, uint8_t *hsv);
