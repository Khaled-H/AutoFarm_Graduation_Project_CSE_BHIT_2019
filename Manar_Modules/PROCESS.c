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
  HAL_SENSORS_tAmoniaLvl Amonia = APP_SENSORREADER_GetAmoniaLvl() ;
  HAL_SENSORS_tCo2Lvl   Co = APP_SENSORREADER_GetCo2Lvl();
	if(((Temp>TempSaveLevel1)&&(Temp<TempSaveLevel2))||((Hum>HumSaveLevel1)&&(Hum<HumSaveLevel2))||((Amonia>AmoniaSaveLevel1)&&(Amonia<AmoniaSaveLevel2))||((Co>CoSaveLevel1)&&(Co<CoSaveLevel2)))
	{
		HAL_ACTUATOR_Off(UPPERFAN);
		HAL_ACTUATOR_Off(LOWERFAN);
		HAL_ACTUATOR_Off(HEATER);
	}
	else if ((Temp>TempSaveLevel2)||(Hum>HumSaveLevel2)){
		HAL_ACTUATOR_On(UPPERFAN);
	}
	else if ((Amonia>AmoniaSaveLevel2)||(Co>CoSaveLevel2)){
		HAL_ACTUATOR_On(LOWERFAN);
	}
	else if ((Temp<TempSaveLevel1)||(Hum<HumSaveLevel1)){
		HAL_ACTUATOR_On(HEATER);
	}
}
