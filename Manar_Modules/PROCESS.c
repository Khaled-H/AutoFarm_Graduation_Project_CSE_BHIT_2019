/*
 * PROCESS.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: manar
 */
#include "PROCESS.h"
void APP_PROCESS_Init(void)
    {
	HAL_ACTUATOR_Init();
	APP_SENSORREADER_Init();
   }
APP_PROCESS_Process(void){

	if((Temp>20)&&(Temp<24)){
		 HAL_ACTUATOR_Off(HAL_ACTUATORS_UPPERFAN_PIN);
		 HAL_ACTUATOR_Off(HAL_ACTUATORS_LOWERFAN_PIN);
		 HAL_ACTUATOR_Off(HAL_ACTUATORS_HEATER_PIN);
	 }
	else if (Temp>27){
		 HAL_ACTUATOR_On(HAL_ACTUATORS_UPPERFAN_PIN);
	}
	else if (Temp<20){
		HAL_ACTUATOR_On(HAL_ACTUATORS_HEATER_PIN);
	}
}
