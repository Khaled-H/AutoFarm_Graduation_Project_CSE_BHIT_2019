/*
 * Sensors.c
 *
 *  Created on: Apr 12, 2019
 *      Author: Mostafa Samir Nawar		Mostafa.nwar@yahoo.com
 */

/************ NEED TO BE DEFINED BY HARDWARE MAN >> Khaled      ***************/
#include "SENSORS.h"
enum {
  AMONIASENSORCHANNEL=1,
  TEMPSENSORCHANNEL,
  CO2SENSORCHANNEL,
  HUMSENSORCHANNEL,
};


void HAL_SENSORS_Init(void){
 MCAL_ADC_Init();
}
HAL_SENSORS_tAmoniaLvl HAL_SENSORS_GetAmoniaLvl(void){
  HAL_SENSORS_tAmoniaLvl temp ;
  temp = MCAL_ADC_ReadChannel(AMONIASENSORCHANNEL);
  return temp ;
}
HAL_SENSORS_tTempLvl HAL_SENSORS_GetTempLvl(void){
  HAL_SENSORS_tTempLvl temp ;
  temp = MCAL_ADC_ReadChannel(TEMPSENSORCHANNEL);
  return temp ;
}
HAL_SENSORS_tHumLvl HAL_SENSORS_GetHumLvl(void){
  HAL_SENSORS_tHumLvl temp ;
  temp = MCAL_ADC_ReadChannel(HUMSENSORCHANNEL);
  return temp ;
}
HAL_SENSORS_tCo2Lvl HAL_SENSORS_GetCo2Lvl(void){
  HAL_SENSORS_tCo2Lvl temp ;
  temp = MCAL_ADC_ReadChannel(CO2SENSORCHANNEL);
  return temp ;
}

