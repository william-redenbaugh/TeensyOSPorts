#include <Arduino.h>
#include "OS/OSThreadKernel.h"
#include "DS_HELPER/priority_queue.hpp"


void led_blink_thread(void *parameters){

  for(;;){
    digitalWrite(LED_BUILTIN, HIGH); 
    os_thread_delay_s(1); 
    digitalWrite(LED_BUILTIN, LOW); 
    os_thread_delay_s(1); 
  }
}

void led_blink_thread_two(void *parameters){
  pinMode(LED_BLUE, OUTPUT); 

  for(;;){
    digitalWrite(LED_BLUE, HIGH); 
    os_thread_delay_ms(100); 
    digitalWrite(LED_BLUE, LOW); 
    os_thread_delay_ms(100); 
  }
}

void led_blink_thread_three(void *parameters){

  for(;;){
    _os_yield(); 
  }
}

uint32_t thread_stack[4096]; 
uint32_t thread_stack_two[4096]; 
uint32_t thread_stack_three[4096]; 

void setup() {

  os_init(); 
  // put your setup code here, to run once:
  pinMode(LED_BUILTIN, OUTPUT); 
  os_add_thread(led_blink_thread, NULL, sizeof(thread_stack), thread_stack);  
  os_add_thread(led_blink_thread_two, NULL, sizeof(thread_stack_two), thread_stack_two);  
  os_add_thread(led_blink_thread_three, NULL, sizeof(thread_stack_three), thread_stack_three);  
  
  // With the stm32, we don't currently use the primary thread. 
  stm32_os_start(); 
}

void loop() {  
  // No point in putting anything here, since the program only runs on normal threads. 
}