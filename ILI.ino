#define SetColumnAddress          0x2A // Column Address Set
#define SetPageAddress            0x2B // Page Address Set
#define WriteFrameMemory          0x2C // Memory Write
#define SetPartialArea            0x30 // SetPartialArea (ILI page 118) also known as PLTAR
#define TurnOnPartialDisplayMode  0x12 // Partial Mode ON
#define TurnOnNormalDisplayMode   0x13 // Normal Display Mode ON (NORON), turns off partial display mode
#define RAMRD                     0x2E // Memory Read (unused)
#define MADCTL                    0x36 // Memory Access Control


/**************************************************************************/
/*!
    @brief   Set the "address window" - the rectangle we will write to RAM with
   the next chunk of      SPI data writes. The ILI9341 will automatically wrap
   the data as each row is filled
    @param   x1  TFT memory 'x' origin
    @param   y1  TFT memory 'y' origin
    @param   w   Width of rectangle
    @param   h   Height of rectangle
*/


//void setAddrWindow(uint16_t x1, uint16_t y1, uint16_t w, uint16_t h) {
//  static uint16_t old_x1 = 0xffff, old_x2 = 0xffff;
//  static uint16_t old_y1 = 0xffff, old_y2 = 0xffff;
//
//  uint16_t x2 = (x1 + w - 1), y2 = (y1 + h - 1);
//  if (x1 != old_x1 || x2 != old_x2) {
//    writeCommand(ILI9341_ColumnAddressSet); // Column address set
//    SPI_WRITE16(x1);
//    SPI_WRITE16(x2);
//    old_x1 = x1;
//    old_x2 = x2;
//  }
//  if (y1 != old_y1 || y2 != old_y2) {
//    writeCommand(ILI9341_PageAddressSet); // Row address set
//    SPI_WRITE16(y1);
//    SPI_WRITE16(y2);
//    old_y1 = y1;
//    old_y2 = y2;
//  }
//  writeCommand(ILI9341_WriteFrameMemory); // Write to RAM
//}
