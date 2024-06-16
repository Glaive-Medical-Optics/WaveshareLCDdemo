#ifndef _DEV_CONVERT_H_
#define _DEV_CONVERT_H_

// Define the width and height of the image
#define GLAIVE_WIDTH 100
#define GLAIVE_HEIGHT 100

#include <stdint.h>


// Define a structure to hold a pixel in 16-bit RGB565 format
typedef struct yyy{
  uint16_t value;
} RGB565;

// Define a structure to hold a pixel in 24-bit RGB format
typedef struct xxx{
  uint8_t r;
  uint8_t g;
  uint8_t b;
} RGB888;


void convert24bitTo16bit(RGB888 *bmp24, RGB565 *bmp16,int width, int height);


#endif
