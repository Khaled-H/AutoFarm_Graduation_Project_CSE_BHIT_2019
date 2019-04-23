/*
 * ACTUATORS.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: manar
 */
#include "ACTUATORS.h"


void HAL_ACTUATOR_Init(void){
	//**enable clock to GPIO A  **//
	MCAL_RCC_PortEnable(PORTA);
    //pits output in openDrain mode and max speed 10MHZ init PB7&PB6 as output //
    MCAL_PORT_Init();
    //not access output data reg//

 }
void HAL_ACTUATOR_On(u8 MotorNumber){
	 if (MotorNumber == 1)
	       {
		 MCAL_DIO_WritePin (HAL_ACTUATORS_UPPERFAN_PORT  , HAL_ACTUATORS_UPPERFAN_PIN,1 );
	      }
	 else if  (MotorNumber == 2)
	       {
	    	  //set bit PB6
		 MCAL_DIO_WritePin (HAL_ACTUATORS_LOWERFAN_PORT  , HAL_ACTUATORS_LOWERFAN_PIN,1 );
	       }
	 else {
		 MCAL_DIO_WritePin (HAL_ACTUATORS_HEATER_PORT  , HAL_ACTUATORS_LOWERFAN_PIN,1 );
	 }

 }
void HAL_ACTUATOR_Off(u8 MotorNumber){
	 if (MotorNumber == 1)
	       {
		 MCAL_DIO_WritePin (HAL_ACTUATORS_UPPERFAN_PORT  , HAL_ACTUATORS_UPPERFAN_PIN,0);
	      }
	 else if  (MotorNumber == 2)
	       {

		 MCAL_DIO_WritePin (HAL_ACTUATORS_LOWERFAN_PORT  , HAL_ACTUATORS_LOWERFAN_PIN,0 );
	       }
	 else {
		 MCAL_DIO_WritePin (HAL_ACTUATORS_HEATER_PORT  , HAL_ACTUATORS_LOWERFAN_PIN,0 );
	 }
}


