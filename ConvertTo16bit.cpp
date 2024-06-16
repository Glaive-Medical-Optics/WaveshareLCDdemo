#include "ConvertTo16bit.h"

// Function to convert 24-bit RGB888 to 16-bit RGB565
RGB565 convertToRGB565(RGB888 pixel)
{
  RGB565 result;
  result.value = ((pixel.r & 0xF8) << 8) | ((pixel.g & 0xFC) << 3) | (pixel.b >> 3);
  return result;
} 

void convert24bitTo16bit(RGB888 bmp24[], RGB565 bmp16[],int width, int height)
{

  // Convert the image
  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {
      int index = y * width + x;
      bmp16[index] = convertToRGB565(bmp24[index]);
    }
  }

}
