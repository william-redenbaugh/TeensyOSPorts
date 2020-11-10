#include <Arduino.h>
#include "OS/OSThreadKernel.h"
#include "DS_HELPER/priority_queue.hpp"

void led_blink_thread(void *parameters){

  for(;;){
    digitalWrite(LED_BUILTIN, HIGH); 
    os_thread_sleep_ms(1000); 
    digitalWrite(LED_BUILTIN, LOW); 
    os_thread_sleep_ms(1000); 
  }
}

void led_blink_thread_two(void *parameters){
  pinMode(LED_D3, OUTPUT); 

  for(;;){
    digitalWrite(LED_D3, HIGH); 
    os_thread_sleep_ms(200); 
    digitalWrite(LED_D3, LOW); 
    os_thread_sleep_ms(200); 
  }
}

uint32_t thread_stack[128]; 
uint32_t thread_stack_two[128]; 
uint32_t thread_stack_three[128]; 

void setup() {

  os_init(); 
  // put your setup code here, to run once:
  pinMode(LED_BUILTIN, OUTPUT); 
  os_add_thread(led_blink_thread, NULL, sizeof(thread_stack), thread_stack);  
  os_add_thread(led_blink_thread_two, NULL, sizeof(thread_stack_two), thread_stack_two);  

  stm32_os_start(); 
}


void loop() {}