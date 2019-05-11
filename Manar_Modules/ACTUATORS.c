/*
 * ACTUATORS.c
 *
 *  Created on: ??�/??�/????
 *      Author: manar
 */
#include "ACTUATORS.h"
//*void HAL_ACTUATOR_Init(void){
	//**enable clock to GPIO A  **//
	//pits output in openDrain mode and max speed 10MHZ init PB7&PB6 as output //
//	MCAL_PORT_Init();
	//not access output data reg */
extern void HAL_ACTUATOR_On(u8 HAL_ACTUATORS_ActuatorName){
	switch ( HAL_ACTUATORS_ActuatorName ){
	case UPPERFAN:
		MCAL_DIO_WritePin (HAL_ACTUATORS_UPPERFAN_PORT  , HAL_ACTUATORS_UPPERFAN_PIN,STD_HIGH  );
		break;
	case LOWERFAN:

		MCAL_DIO_WritePin (HAL_ACTUATORS_LOWERFAN_PORT  , HAL_ACTUATORS_LOWERFAN_PIN,STD_HIGH  );
		break;
	case HEATER:
		MCAL_DIO_WritePin (HAL_ACTUATORS_HEATER_PORT  , HAL_ACTUATORS_HEATER_PIN,STD_HIGH );
		break;
	}

}
extern void HAL_ACTUATOR_Off(u8 HAL_ACTUATORS_ActuatorName){
	switch ( HAL_ACTUATORS_ActuatorName ){
	case UPPERFAN:
		MCAL_DIO_WritePin (HAL_ACTUATORS_UPPERFAN_PORT  , HAL_ACTUATORS_UPPERFAN_PIN,STD_LOW   );
		break;
	case LOWERFAN:

		MCAL_DIO_WritePin (HAL_ACTUATORS_LOWERFAN_PORT  , HAL_ACTUATORS_LOWERFAN_PIN,STD_LOW   );
		break;
	case HEATER:
		MCAL_DIO_WritePin (HAL_ACTUATORS_HEATER_PORT  , HAL_ACTUATORS_HEATER_PIN,STD_LOW  );
		break;
	}
}


