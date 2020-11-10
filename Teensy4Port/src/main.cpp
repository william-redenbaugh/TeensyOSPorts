#include <Arduino.h>
#include "OS/OSThreadKernel.h"

void led_thread(void *parameters){
	for(;;){
		os_thread_sleep_ms(1000);
		digitalWrite(LED_BUILTIN, HIGH);
		os_thread_sleep_ms(1000);
		digitalWrite(LED_BUILTIN, LOW);
	}
}

void another_led_thread(void *parameters){
	for(;;){
		
	}
}

void setup() {
	delay(2000);
	os_init(); 
	pinMode(LED_BUILTIN, OUTPUT);
	os_add_thread(&another_led_thread, NULL, -1, NULL);
	os_add_thread(&led_thread, NULL, -1, NULL); 
	_os_yield();
}

void loop() {
}