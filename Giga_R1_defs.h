/*****************************************************************************
* | File        :   Giga_R1_defs.h
* | Author      :   Stanley Rabinowitz and Dana Kelley
* | Function    :   Routines specific to the Giga R1 board
*----------------
* | This version:   V1.0
* | Date        :   5/21/2024

# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documnetation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to  whom the Software is
# furished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in
# all copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS OR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
# THE SOFTWARE.
#
******************************************************************************/

/*
 *  General Notes about this project
 */

// 5/22/24 SR/DK: fixed compiler error by allocating 4 bytes to hold character strings
//  since some Chinese characters need 3 bytes for their UTF-encoding, plus a null byte at the end.

#include <stdio.h>

// Define function dtostrf that normally appears in the stdlib.h for AVR boards

// This function converts a float or a double to a string, putting it in the specified buffer.

void dtostrf(double value, signed char width, unsigned char prec, char *buffer);
