#include <Arduino.h>
#include "OS/OSThreadKernel.h"

void setup() {
	os_init(); 
	pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
	os_thread_delay_ms(1000);
	digitalWrite(LED_BUILTIN, HIGH);
	os_thread_delay_ms(1000);
	digitalWrite(LED_BUILTIN, LOW);
}