/*
 * PROCESS.c
 *
 *  Created on: ??�/??�/????
 *      Author: manar
 */
#include "PROCESS.h"


void APP_PROCESS_Init(void)
{
	HAL_ACTUATOR_Init();
}
APP_PROCESS_Process(void){
  HAL_SENSORS_tTempLvl Temp = APP_SENSORREADER_GetTempLvl();
  HAL_SENSORS_tHumLvl  Hum= APP_SENSORREADER_GetHumLvl();
//  HAL_SENSORS_tAmoniaLvl Amonia = APP_SENSORREADER_GetAmoniaLvl() ;
//  HAL_SENSORS_tCo2Lvl   Co = APP_SENSORREADER_GetCo2Lvl();
/*
	if(((Temp>20)&&(Temp<24))||((Hum>50)&&(Hum<70))||((Amonia>20)&&(Amonia<25))||((Co>50)&&(Co<100)))
	{
		HAL_ACTUATOR_Off(UPPERFAN);
		HAL_ACTUATOR_Off(LOWERFAN);
		HAL_ACTUATOR_Off(HEATER);
	}
	else if ((Temp>24)||(Hum>70)){
		HAL_ACTUATOR_On(UPPERFAN);
	}
	else if ((Amonia>25)||(Co>100)){
		HAL_ACTUATOR_On(LOWERFAN);=
	}
	else if ((Temp<20)||(Hum<50)){
		HAL_ACTUATOR_On(HEATER);
	}*/
  if((Temp>20
}
