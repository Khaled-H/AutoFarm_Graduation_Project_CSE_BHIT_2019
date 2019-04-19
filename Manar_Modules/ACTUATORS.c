/*
 * ACTUATORS.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: manar
 */
#include "ACTUATORS.h"
typedef struct {
	HWREG32 CR;
	HWREG32 CFGR;
	HWREG32 CIR;
	HWREG32 APB2RSTR;
	HWREG32 APB1RTSR;
	HWREG32 AHBENR;
	HWREG32 APB2ENR;
	HWREG32 APB1ENR;
	HWREG32 BDCR;
	HWREG32 CSR;
}RCC_typedef;
#define RCC   (*(( volatile RCC_typedef* const )(0x40021000)))
typedef struct {
	HWREG32 CRL ;	// Control Low (Configuration Register)
	HWREG32 CRH ;	// Control High (Configuration Register)
	HWREG32 IDR ;	//Input Data Register
	HWREG32 ODR ;	// Output Data Register
	HWREG32 BSR ;	// B  index of the pin to Set output to 1
	HWREG32 BRR ;	// Bit Reset Register, Write 1 to the index of the pin to Reset output to 0
	HWREG32 LCKR ;	// Lock Bit Register to disable the Bit Configuration Changes
}GPIO_typedef;
#define GPIOA (*((volatile GPIO_typedef*const )(0x40010800)))
#define GPIOB (*((volatile GPIO_typedef*const )(0x40010C00)))
#define GPIOC (*((volatile GPIO_typedef*const )(0x40011000)))
void HAL_FAN_Init(void){
	//**enable clock to GPIO B and set pin PB6 , PB7 as output pins **//
    RCC.APB2ENR.Bit03=1;
    //pits output in openDrain mode and max speed 10MHZ init PB7&PB6 as output //
    GPIOB.CRL.REG_FULL_32=(u32)0x66000000;
    //not access output data reg//

 }
void HAL_FAN_On(u8 FanNumber){
	 if (FanNumber == 1)
	       {
	    	  //set bit PB6
	    	  GPIOB.BSR.REG_FULL_32 =(u32)0x00000040;
	      }
	      else {
	    	  //set bit PB6
	    	  GPIOB.BSR.REG_FULL_32 = (u32)0x00000080;
	      }

 }
void HAL_FAN_Off(u8 FanNumber){
       if (FanNumber == 1){
    	  //reset bit PB6
    	  GPIOB.BRR.REG_FULL_32 = (u32)0x00000040;
      }
      else {
    	  //reset bit PB6
    	  GPIOB.BRR.REG_FULL_32 = (u32)0x00000080;
      }
}


