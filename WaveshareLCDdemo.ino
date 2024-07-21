/* 
 *    This demo program shows how to display graphics, including images, on a Waveshare 2.4 inch LCD Module
 *    from an Arduino Giga R1 board.
 *    Author: Glaive Software Group
 *    Revised: 7/18/2024.
 *    Based on the LCD_2inch4.ino sample program from the Waveshare Wiki,
 *    https://www.waveshare.com/wiki/2.4inch_LCD_Module#Arduino_software_description.
 *    
 *    To run this sketch, you will need to specify that you are using the Arduino Giga R1 board
 *    in the IDE's board manager (under Arduino Mbed OS Giga boards).
 *    This sketch uses the Waveshare 2.4 inch LCD Module which uses the ILI9341 controller.
 *    The display is 240x320 pixels.
 *    
 *    This sketch displays various demo figures on the Waveshare LCD module using the SPI interface.
 *    
 *    The pin connections must be set up as follows:
 *    
 *    LCD pin     wire color    Arduino pin
 *    -------     ----------    -----------
 *    VCC         purple        5V            required
 *    GND         white         GND           required
 *    DIN         green         D90 (COPI)    required  (on SPI 6-pin connector)
 *    CLK         orange        D91 (SCK)     required  (on SPI 6-pin connector)
 *    CS          yellow        D10           optional
 *    DC          blue          D7            optional
 *    RST         brown         D8            optional
 *    BL          gray          D9            optional
 *    
 *    This demo is set up to use pins D7, D8, D9, and D10 as shown in the table above.
 *    You can replace these pins by any digital pins.
 *    To do that, specify the pins you are using in the file DEV_Config.h.
 *    
 *    This program is Free Software and has ABSOLUTELY NO WARRANTY.
 */

#include <SPI.h>
#include "LCD_Driver.h"
#include "GUI_Paint.h"
#include <avr/dtostrf.h>

/*
 *    Set COUNT_UP to true if you want to count in the Serial Monitor each time through your main loop.
 *    Set BLINK_LIGHT if you want the green LED to blink each time through your main loop
 *    Set WAIT_FOR_CHARACTER if you want to have to type a character in the serial monitor before the program will start.
 */

#define COUNT_UP            false
#define BLINK_LIGHT         true
#define WAIT_FOR_CHARACTER  false

int count=0;

void waitForCharacter()
{
  Serial.print("Type any character to begin: ");
  delay(2000);

  // Wait for data to be available to read
  
  while (!Serial.available()) {} 

  char receivedChar = Serial.read(); // Read the incoming byte
  Serial.write(receivedChar);
  Serial.print("\n");
  
  delay(2000);
}

void setup()
{

  Serial.begin(9600);   // for print debugging
  delay(4000);          //delay 4 seconds to give the serial port enough time to initialize
  Serial.print("\nStarting...\n");
  Config_Init();
  Serial.print("Config succeeded.\n");

  #if WAIT_FOR_CHARACTER
  waitForCharacter();
  #endif
  
  LCD_Init();
  Serial.print("LCD_Init succeeded.\n");
  delay(2000);
  LCD_Clear(WHITE);

/*
 *    Select which test(s) you want to run by uncommenting one of the following lines of code.
 */

//  basicValidationTest();    // runs simple test provided by Waveshare
//  drawBlackAndWhiteImage();
//  drawWaveshareLogo();
//  moveWaveshareLogo();
//  drawG100x100();
//  move100x100G();
//  slideG();
//  drawG70x70();
//  move70x70G();
//  checkTiming();
//  drawPartialArea();
    quickDrawG();
//  draw45degreeLineFromOrigin();
  
  Serial.print("exiting setup.\n");
}

#define builtinLED D87

void loop()
{
#if BLINK_LIGHT
  digitalWrite(builtinLED, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(2000);                     // wait for 2 seconds
  digitalWrite(builtinLED, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);              // wait for a second
#endif

#if COUNT_UP
  count++;    // bump iteration count
  Serial.print(count);
  Serial.print("\n");
#endif

}



/*********************************************************************************************************
  END FILE
*********************************************************************************************************/
