/*
 * FAN(1).c
 *
 *  Created on: ??þ/??þ/????
 *      Author: manar
 */
#include "FAN(1).h"
void HAL_FAN_Init(void){
	//**enable clock to GPIO B and set pin PB6 , PB7 as output pins **//
    RCC.APB2ENR.Bit03=1;
    //pits output in openDrain mode and max speed 10MHZ init PB7&PB6 as output //
    GPIOB.CRL.REG_FULL_32=(u32)0x66000000;
    //not access output data reg//

 }
void HAL_FAN_FanOn(u8 FanNumber){
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
void HAL_FAN_FanOff(u8 FanNumber){
       if (FanNumber == 1){
    	  //reset bit PB6
    	  GPIOB.BRR.REG_FULL_32 = (u32)0x00000040;
      }
      else {
    	  //reset bit PB6
    	  GPIOB.BRR.REG_FULL_32 = (u32)0x00000080;
      }
}
