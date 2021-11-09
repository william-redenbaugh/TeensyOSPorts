#include <Arduino.h>
#include "OS/OSThreadKernel.h"
#include "DS_HELPER/priority_queue.hpp"

#include <Adafruit_NeoPixel.h>


uint32_t thread_stack[4096]; 

// Which pin on the Arduino is connected to the NeoPixels?
#define PIN        PD7 // On Trinket or Gemma, suggest changing this to 1

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS 64 // Popular NeoPixel ring size

// When setting up the NeoPixel library, we tell it how many pixels,
// and which pin to use to send signals. Note that for older NeoPixel
// strips you might need to change the third parameter -- see the
// strandtest example for more information on possible values.
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);


void led_blink_thread(void *parameters){
  
  pixels.begin();

  while(1){
    for(int i=0; i<NUMPIXELS; i++) { // For each pixel...

      // pixels.Color() takes RGB values, from 0,0,0 up to 255,255,255
      // Here we're using a moderately bright green color:
      pixels.setPixelColor(i, pixels.Color(0, 5, 0));

      pixels.show();   // Send the updated pixel colors to the hardware.

      os_thread_delay_ms(10);
    } 

    for(int i=0; i<NUMPIXELS; i++) { // For each pixel...

      // pixels.Color() takes RGB values, from 0,0,0 up to 255,255,255
      // Here we're using a moderately bright green color:
      pixels.setPixelColor(i, pixels.Color(0, 0, 0));

      pixels.show();   // Send the updated pixel colors to the hardware.

      os_thread_delay_ms(10);
    } 

  }
}

void setup() {
  os_init(); 
  os_add_thread(led_blink_thread, NULL, sizeof(thread_stack), thread_stack);
  // With the stm32, we don't currently use the primary thread. 
  stm32_os_start();  
}

void loop() {  
 
}