/*****************************************************************************
* | File        : tests
* | Author      : Waveshare team
* |             : moved into separate file
*----------------
* | This version:   V1.0
* | Date        :   2018-01-11
* | Info        :   Basic version
*
******************************************************************************/

#include "image.h"

  unsigned long time1, time2;
  double dif;
  char duration[10];

// This test was written by Waveshare and does a quick test of most of the features of the LCD module.

void basicValidationTest()
{
  Paint_NewImage(LCD_WIDTH, LCD_HEIGHT, 0, WHITE);
  Paint_Clear(WHITE);
  time1=micros();
  Paint_DrawString_EN(30, 10, "123", &Font24, YELLOW, RED);
  Paint_DrawString_EN(30, 34, "ABC", &Font24, BLUE, CYAN);
  
  Paint_DrawString_CN(50,180, "微雪电子",  &Font24CN, WHITE, RED);
  
  Paint_DrawRectangle(125, 10, 225, 58, RED,  DOT_PIXEL_2X2,DRAW_FILL_EMPTY);
  Paint_DrawLine(125, 10, 225, 58, MAGENTA,   DOT_PIXEL_2X2,LINE_STYLE_SOLID);
  Paint_DrawLine(225, 10, 125, 58, MAGENTA,   DOT_PIXEL_2X2,LINE_STYLE_SOLID);
  Paint_DrawCircle(150,100, 25, BLUE,   DOT_PIXEL_2X2,   DRAW_FILL_EMPTY);
  Paint_DrawCircle(180,100, 25, BLACK,  DOT_PIXEL_2X2,   DRAW_FILL_EMPTY);
  Paint_DrawCircle(210,100, 25, RED,    DOT_PIXEL_2X2,   DRAW_FILL_EMPTY);
  Paint_DrawCircle(165,125, 25, YELLOW, DOT_PIXEL_2X2,   DRAW_FILL_EMPTY);
  Paint_DrawCircle(195,125, 25, GREEN,  DOT_PIXEL_2X2,   DRAW_FILL_EMPTY);
 
  Paint_DrawImage(gImage_70X70, 20, 80, 70, 70); 
  Paint_DrawFloatNum (5, 150 ,987.654321,4,  &Font20,    WHITE,   LIGHTGREEN);
  time2=micros();
  dif=time2-time1;
  dif=dif/1000000;   // convert to seconds
  sprintf(duration,"%-7.3f",dif);
  Serial.print("duration=");
  Serial.print(duration);
  Serial.println(" sec");
}

extern PROGMEM const unsigned char gImage_Gbw[];

void drawBlackAndWhiteImage()
{
  Paint_NewImage(LCD_WIDTH, LCD_HEIGHT, 0, WHITE);
  time1=micros();

  Paint_DrawImage(gImage_Gbw, 20, 80, 100, 50); 

  time2=micros();
  dif=time2-time1;
  dif=dif/1000000;   // convert to seconds
  sprintf(duration,"%-7.3f",dif);
  Serial.print("duration=");
  Serial.print(duration);
  Serial.println(" sec");
}

void drawWaveshareLogo()
{
  Paint_NewImage(LCD_WIDTH, LCD_HEIGHT, 0, WHITE);
  time1=micros();

  Paint_DrawImage(gImage_70X70, 20, 80, 70, 70); 

  time2=micros();
  dif=time2-time1;
  dif=dif/1000000;   // convert to seconds
  sprintf(duration,"%-7.3f",dif);
  Serial.print("duration=");
  Serial.print(duration);
  Serial.println(" sec");
}

void moveWaveshareLogo()
{
  uint8_t i;
  
  Paint_NewImage(LCD_WIDTH, LCD_HEIGHT, 0, WHITE);
  time1=micros();

  for (i=1; i<=100; i++)
  {
    Paint_DrawImage(gImage_70X70, i, 60+2*i, 70, 70);
  }

  time2=micros();
  dif=time2-time1;
  dif=dif/1000000;   // convert to seconds
  sprintf(duration,"%-7.3f",dif);
  Serial.print("duration=");
  Serial.print(duration);
  Serial.println(" sec");
}

#include "ConvertTo16bit.h"


extern PROGMEM RGB888 gImageG24bitColorG[100 * 100 * 3];

PROGMEM RGB565 gImageG16bitColorG[100 * 100 * 2];

  //  Paint_DrawImage(gImage_Gbw, 20, 80, 100, 100); 

boolean convertedG = false;

void drawG100x100()
{

  // Convert the 24-bit logo data to 16-bit logo data
  // so that we can draw it using the Paint_DrawImage routine.

  if (!convertedG)
  {
  convert24bitTo16bit(gImageG24bitColorG, gImageG16bitColorG, G_WIDTH, G_HEIGHT);
  convertedG=true;
  }
  
//  Paint_NewImage(LCD_WIDTH, LCD_HEIGHT, 0, WHITE);
  Paint_NewImage(G_WIDTH+20, G_HEIGHT+80, 0, WHITE);
  time1=micros();

  Paint_DrawImage((const unsigned char *)gImageG16bitColorG, 20, 80, G_WIDTH, G_HEIGHT); 

  time2=micros();
  dif=time2-time1;
  dif=dif/1000000;   // convert to seconds
  sprintf(duration,"%-7.3f",dif);
  Serial.print("duration=");
  Serial.print(duration);
  Serial.println(" sec");
}

void move100x100G()
{
  uint8_t i;
  
  // Convert the 24-bit logo data to 16-bit logo data
  // so that we can draw it using the Paint_DrawImage routine.
  
  if (!convertedG)
  {
  convert24bitTo16bit(gImageG24bitColorG, gImageG16bitColorG, G_WIDTH, G_HEIGHT);
  convertedG=true;
  }

  Paint_NewImage(LCD_WIDTH, LCD_HEIGHT, 0, WHITE);
  time1=micros();

  for (i=1; i<=100; i++)
  {
    Paint_DrawImage((const unsigned char *)gImageG16bitColorG, i, 20+2*i, G_WIDTH, G_HEIGHT);
  }

  time2=micros();
  dif=time2-time1;
  dif=dif/1000000;   // convert to seconds
  sprintf(duration,"%-7.3f",dif);
  Serial.print("duration=");
  Serial.print(duration);
  Serial.println(" sec");
}

void slideG()
{
  uint8_t i;
  
  // Convert the 24-bit logo data to 16-bit logo data
  // so that we can draw it using the Paint_DrawImage routine.
  
  if (!convertedG)
  {
  convert24bitTo16bit(gImageG24bitColorG, gImageG16bitColorG, G_WIDTH, G_HEIGHT);
  convertedG=true;
  }

  Paint_NewImage(LCD_WIDTH, LCD_HEIGHT, 0, WHITE);
  time1=micros();

  for (i=1; i<=100; i++)
  {
    Paint_DrawImage((const unsigned char *)gImageG16bitColorG, 10+i, 10, G_WIDTH, G_HEIGHT);
  }

  time2=micros();
  dif=time2-time1;
  dif=dif/1000000;   // convert to seconds
  sprintf(duration,"%-7.3f",dif);
  Serial.print("duration=");
  Serial.print(duration);
  Serial.println(" sec");
}

void checkTiming()
{
  unsigned long i;
  unsigned long dur;
  unsigned long fps;

  time1=micros();

  for (i=0; i<70*70*2; i++)
  {
    SPI.transfer(0x11);
  }

  time2=micros();
  dur=time2-time1;
  fps=dur/1000;
  Serial.print("duration=");
  Serial.print(dur);
  Serial.print(" microsec");
  Serial.print("  (");
  Serial.print(fps);
  Serial.println(") fps");

}

void drawG70x70()
{
  Paint_NewImage(LCD_WIDTH, LCD_HEIGHT, 0, WHITE);
  time1=micros();

  Paint_DrawImage((const unsigned char *)G_70x70, 20, 80, G70x70_WIDTH, G70x70_HEIGHT); 

  time2=micros();
  dif=time2-time1;
  dif=dif/1000000;   // convert to seconds
  sprintf(duration,"%-7.3f",dif);
  Serial.print("duration=");
  Serial.print(duration);
  Serial.println(" sec");
}

void move70x70G()
{
  uint8_t i;
  
  Paint_NewImage(LCD_WIDTH, LCD_HEIGHT, 0, WHITE);
  time1=micros();

  for (i=1; i<=100; i++)
  {
    Paint_DrawImage((const unsigned char *)G_70x70, i, 20+2*i, G70x70_WIDTH, G70x70_HEIGHT);
  }

  time2=micros();
  dif=time2-time1;
  dif=dif/1000000;   // convert to seconds
  sprintf(duration,"%-7.3f",dif);
  Serial.print("duration=");
  Serial.print(duration);
  Serial.print(" sec   (");
  sprintf(duration,"%-4.1f",100/dif);
  Serial.print(duration);
  Serial.print(" FPS)\n");
}

void my_WriteCommand(UBYTE data)   
{ 
  DEV_Digital_Write(DEV_CS_PIN, 0);
  DEV_Digital_Write(DEV_DC_PIN, 0);
  DEV_SPI_WRITE(data);
}

static void my_WriteData_Byte(UBYTE data) 
{ 
  DEV_Digital_Write(DEV_CS_PIN, 0);
  DEV_Digital_Write(DEV_DC_PIN, 1);
  DEV_SPI_WRITE(data);  
  DEV_Digital_Write(DEV_CS_PIN,1);
}  

static void my_WriteData_Word(UWORD data)
{
  DEV_Digital_Write(DEV_CS_PIN, 0);
  DEV_Digital_Write(DEV_DC_PIN, 1);
  DEV_SPI_WRITE((data>>8) & 0xff);
  DEV_SPI_WRITE(data);
  DEV_Digital_Write(DEV_CS_PIN, 1);
}   


void turnOnPartialDisplayMode()
{
  my_WriteCommand(TurnOnPartialDisplayMode);
}

void turnOnNormalDisplayMode()
{
  my_WriteCommand(TurnOnNormalDisplayMode);
}

void setPartialArea(uint16_t x, uint16_t y)
{
    my_WriteCommand(SetPartialArea);
    LCD_WriteData_Word(x);
    LCD_WriteData_Word(y);
}

void setColumnAddress(uint16_t firstCol, uint16_t lastCol)
{
    my_WriteCommand(SetColumnAddress);
    LCD_WriteData_Word(firstCol);
    LCD_WriteData_Word(lastCol);
}

void setPageAddress(uint16_t firstRow, uint16_t lastRow)
{
    my_WriteCommand(SetPageAddress);
    LCD_WriteData_Word(firstRow);
    LCD_WriteData_Word(lastRow);
}

void writeFrameMemory()
{
    my_WriteCommand(WriteFrameMemory);
}


void drawPartialArea()
{
  unsigned long row, col;
  unsigned long dur;
  int i;
  int width = 70;
  int height = 70;
  int startX = 10;
  int startY = 80;
  int numberOfFrames = 100;

  time1=micros();

// Draw a 70x70 filled rectangle 100 times
  for (i=1; i<=numberOfFrames; i++)
  {
    LCD_SetCursor(startX, startY);
    
    //turnOnPartialDisplayMode();
    //setPartialArea(startY, startY+height-1);
    setColumnAddress(startX, startX+width-1);
    setPageAddress(startY, startY+height-1);
    writeFrameMemory();

    for (col=1; col<=width; col++)
    {
      for (row=1; row<=height; row++)
      {
        LCD_WriteData_Word(RED);      
      }
    }
  }

  time2=micros();
  dur=time2-time1;
  dif=dur/1000000.0;   // convert to seconds
  sprintf(duration,"%-7.3f",dif);
  Serial.print("duration=");
  Serial.print(duration);
  Serial.print(" sec  (");
  sprintf(duration,"%-4.1f",numberOfFrames/dif);
  Serial.print(duration);
  Serial.print(" FPS)\n");

  turnOnNormalDisplayMode();
}



void quickDrawG()
{
  const unsigned short *logo = G_70x70;
  unsigned short *logoPtr;
  unsigned long row, col;
  unsigned long dur;
  int i;
  unsigned long j;
  int numberOfFrames = 120;
  int startX = 100;
  int startY = 30;
  int width = G70x70_WIDTH;
  int height = G70x70_HEIGHT;

  time1=micros();

  // Draw a 70x70 Stylized colored G 100 times

  for (i=1; i<=numberOfFrames; i++)
  {
    logoPtr = (unsigned short *)logo;
    LCD_SetCursor(100, 30);
    //turnOnPartialDisplayMode();
    //setPartialArea(startY, startY+height-1);
    setColumnAddress(startX, startX+width-1);
    setPageAddress(startY+i, startY+i+height-1);
    writeFrameMemory();
    for (j=1; j<=width*height; j++)
    {
        LCD_WriteData_Word(*logoPtr++);      
    }
  }

  time2=micros();
  dur=time2-time1;
  dif=dur/1000000.0;   // convert to seconds
  sprintf(duration,"%-7.3f",dif);
  Serial.print("duration=");
  Serial.print(duration);
  Serial.print(" sec  (");
  sprintf(duration,"%-4.1f",numberOfFrames/dif);
  Serial.print(duration);
  Serial.print(" FPS)\n");

  turnOnNormalDisplayMode();
}

void draw45degreeLineFromOrigin()
{
  Paint_NewImage(LCD_WIDTH, LCD_HEIGHT, 0, WHITE);
  Paint_Clear(WHITE);
  time1=micros();

  Paint_DrawLine(0, 0, LCD_WIDTH, LCD_WIDTH, RED, DOT_PIXEL_3X3, LINE_STYLE_SOLID);
  Paint_DrawLine(0, 200, 240, 200, BLUE, DOT_PIXEL_3X3, LINE_STYLE_DOTTED);

  time2=micros();
  dif=time2-time1;
  dif=dif/1000000;   // convert to seconds
  sprintf(duration,"%-7.3f",dif);
  Serial.print("duration=");
  Serial.print(duration);
  Serial.println(" sec");
}
