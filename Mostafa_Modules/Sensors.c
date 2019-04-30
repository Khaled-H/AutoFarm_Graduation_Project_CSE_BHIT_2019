/*
 * Sensors.c
 *
 *  Created on: Apr 12, 2019
 *      Author: Mostafa Samir Nawar		Mostafa.nwar@yahoo.com
 */

/************ NEED TO BE DEFINED BY HARDWARE MAN >> Khaled      ***************/
#include "SENSORS.h"


extern void HAL_SENSORS_Init(void){
	MCAL_ADC_Init();
}
extern HAL_SENSORS_tAmoniaLvl HAL_SENSORS_GetAmoniaLvl(void){
	HAL_SENSORS_tAmoniaLvl temp ;
	temp = MCAL_ADC_ReadChannel(HAL_SENSORS_AMONIACHANNEL);
	return temp ;
}
extern HAL_SENSORS_tDH22ReturnType HAL_SENSORS_GetDH22Lvls(void){
  return (HAL_DHT22_Read());

}
extern HAL_SENSORS_tCo2Lvl HAL_SENSORS_GetCo2Lvl(void){
	HAL_SENSORS_tCo2Lvl temp ;
	temp = MCAL_ADC_ReadChannel(HAL_SENSORS_COCHANNEL);
	return temp ;
}

