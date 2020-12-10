#include <Arduino.h>
#include "OS/OSThreadKernel.h"
#include "TeensyDebug.h"

//
// Either set debugging to O0 or mark the function
// as DEBUGRUN. If you don't do this, the optimizer will
// inline the function and you won't be able to set a
// breakpoint.
//
#pragma GCC optimize ("O0")

void setup() {
  delay(2000);
  debug.begin(Serial); 
}

void loop() {
  delay(1000);
}