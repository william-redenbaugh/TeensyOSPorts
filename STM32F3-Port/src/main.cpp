#include <Arduino.h>
#include "OS/OSThreadKernel.h"

void setup() {
  os_init(); 
  // put your setup code here, to run once:

  _os_yield(); 
}

void loop() {
  // put your main code here, to run repeatedly:
}