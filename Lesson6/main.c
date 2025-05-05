#include "tm4c.h"
/*
    GPIO_PORTF_DATA_R  = 0x02U; //red
    GPIO_PORTF_DATA_R  = 0x04U; //blue
    GPIO_PORTF_DATA_R  = 0x08U; //green
*/
#define LED_RED   (1u << 1)
#define LED_BLUE  (1u << 2)
#define LED_GREEN (1u << 3)

int main() { 
  /*
  unsigned int a = 0x5A5A5A5A;
  unsigned int b = 0xDEADBEEF;
  unsigned int c ;
  
  c = a | b; //or 1 0 , 1 1 = 1 ; 0 0 = 0
  c = a & b; //and  nhu (phep nhan bth)
  c = a ^ b; //exclusive OR ( NOR)
  c = ~b;   //not
  c = b >> 1; // right - shift
  c = b << 3; // left - shift

  int x =  1024;
  int y = -1024;
  int z;
  
  z = x >> 3;
  z = y >> 3;
  */
  
  SYSCTL_RCGCGPIO_R |= (1U << 5) ; //ENABLE clock for GPIO F
  GPIO_PORTF_DIR_R  |= (LED_RED | LED_BLUE | LED_GREEN); //set pin 1,2,3 as ouput
  GPIO_PORTF_DEN_R  |= (LED_RED | LED_BLUE | LED_GREEN); // enable digital
  
  GPIO_PORTF_DATA_R  |= LED_BLUE; //turn the blue  LED on
  
  while(1) {
    GPIO_PORTF_DATA_R |= LED_RED; //red 0x02U
    //GPIO_PORTF_DATA_R  = 0x04U; //blue
    //GPIO_PORTF_DATA_R  = 0x08U; //green
    int volatile counter = 0;
    while(counter <1000000) { //delay looop
      ++counter;
    }
    
    GPIO_PORTF_DATA_R &= ~LED_RED;
    counter = 0;
    while(counter <1000000) { //delay loop
      ++counter;
    }
  }
 return 0;
}
