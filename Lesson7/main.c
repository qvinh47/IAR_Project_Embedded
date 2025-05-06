#include "tm4c.h"

#define LED_RED   (1u << 1)
#define LED_BLUE  (1u << 2)
#define LED_GREEN (1u << 3)

int main() { 

  
  SYSCTL_RCGCGPIO_R |= (1U << 5) ; //ENABLE clock for GPIO F
  SYSCTL_GPIOHBCTL_R |= (1U <<5); //ENABLE AHB for GPIOF
  GPIO_PORTF_AHB_DIR_R  |= (LED_RED | LED_BLUE | LED_GREEN); //set pin 1,2,3 as ouput
  GPIO_PORTF_AHB_DEN_R  |= (LED_RED | LED_BLUE | LED_GREEN); // enable digital
  
 GPIO_PORTF_AHB_DATA_BITS_R[LED_BLUE]= LED_BLUE; //turn the blue  LED on
  
  while(1) {
    //GPIO_PORTF_DATA_R |= LED_RED; //red 0x02U
    //*((unsigned long volatile *)(0x40025000 + (LED_RED << 2))) = LED_RED;
    //*(GPIO_PORTF_DATA_BITS_R + LED_RED) = LED_RED;
    GPIO_PORTF_AHB_DATA_BITS_R[LED_RED] = LED_RED;
    
//all three implementation options write to the same address stored in the(STR)R1
    int volatile counter[2] = {0,0 };
    while(counter[0] <1000000) { //delay looop
      ++counter[0];
    } 
    GPIO_PORTF_AHB_DATA_BITS_R[LED_RED] = 0;
     //counter = 0;
    while (*(counter+1) <1000000) { //delay loop
      ++counter[1];
    }
  }
 return 0;
}
