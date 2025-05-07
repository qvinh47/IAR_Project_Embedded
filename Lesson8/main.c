#include "tm4c.h"

#define LED_RED   (1u << 1)
#define LED_BLUE  (1u << 2)
#define LED_GREEN (1u << 3)

void delay(int iter);

void delay(int iter){
    int volatile counter;
    counter = 0;
    while(counter <iter) { //delay looop
      ++counter;
    } 
}

int main() {   
  SYSCTL_RCGCGPIO_R |= (1U << 5) ; //ENABLE clock for GPIO F
  SYSCTL_GPIOHBCTL_R |= (1U <<5); //ENABLE AHB for GPIOF
  GPIO_PORTF_AHB_DIR_R  |= (LED_RED | LED_BLUE | LED_GREEN); //set pin 1,2,3 as ouput
  GPIO_PORTF_AHB_DEN_R  |= (LED_RED | LED_BLUE | LED_GREEN); // enable digital
  
 GPIO_PORTF_AHB_DATA_BITS_R[LED_BLUE]= LED_BLUE; //turn the blue  LED on
  while(1) {
    GPIO_PORTF_AHB_DATA_BITS_R[LED_RED] = LED_RED;   
    delay(1000000);
    GPIO_PORTF_AHB_DATA_BITS_R[LED_RED] = 0;
    delay(500000);
  }
 return 0;
}
