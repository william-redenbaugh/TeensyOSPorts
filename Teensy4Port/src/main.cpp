#include <Arduino.h>
#include "OS/OSThreadKernel.h"
#include "MAX7219_Dot_Matrix.h"
#include "LiquidCrystal_I2C.h"

/* Set the CS digital pin number*/
#define CS 10

/* Set the number of 8*8 module */
#define modules 4     // 4 units of 8*8 module is connected to serial bus
//#define modules 1   // only one moudle is connected to serial bus

MAX7219_Dot_Matrix myDisplay (modules, CS);  // Initialise with no. of module and CS pi

// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 20, 4);


void setup() {
  os_init(); 
  // initialize the LCD
	lcd.begin();

	// Turn on the blacklight and print a message.
	lcd.backlight();
	lcd.print("Hello, world!");
}

void loop() {
  
}