#include "tm4c.h"
/*
#define RCGCGPIO (*((unsigned int*)0x400FE608U)) //clock gating clock
#define GPIOF_BASE 0x40025000u
#define GPIOF_DIR (*((unsigned int*) (GPIOF_BASE + 0x400U)))
#define GPIOF_DEN (*((unsigned int*) (GPIOF_BASE + 0x51CU)))
#define GPIOF_DATA (*((unsigned int*) (GPIOF_BASE + 0x3FCU)))

//#define GPIO_PORTF_DATA_BITS_R  ((volatile unsigned long *)0x40025000)
#define GPIO_PORTF_DATA_R       (*((volatile unsigned long *)0x400253FC))
*/
int main() { 
  SYSCTL_RCGCGPIO_R  = 0x20U; //ENABLE clock for GPIO F
  GPIO_PORTF_DIR_R  = 0x0EU; //set pin 1,2,3 as ouput
  GPIO_PORTF_DEN_R  = 0x0EU; // enable digital
  
  while(1) {
    GPIO_PORTF_DATA_R  = 0x08U;
    int volatile counter = 0;
    while(counter <1000000) { //delay looop
      ++counter;
    }
    
    GPIO_PORTF_DATA_R  = 0x00U;
    counter = 0;
    while(counter <1000000) { //delay loop
      ++counter;
    }
  }
 // return 0;
}
/*
 main_1 : Lenh LDR.N tai truc tiep dia chi 0x4002'53FC dia chi port F vao R0 ma ko thuc hien phep cong nao
 Lenh STR bat den led. Theo quan diem cua CPU giao tiep voi ben ngoai chi can
 ghi 1 value vao 1 address.
*/