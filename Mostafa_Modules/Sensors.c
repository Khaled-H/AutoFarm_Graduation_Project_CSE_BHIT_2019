/*
 * Sensors.c
 *
 *  Created on: Apr 12, 2019
 *      Author: Mostafa Samir Nawar		Mostafa.nwar@yahoo.com
 */

/************ NEED TO BE DEFINED BY HARDWARE MAN >> Khaled      ***************/
#include "SENSORS.h"


void HAL_SENSORS_Init(void){
	MCAL_ADC_Init();
}
HAL_SENSORS_tAmoniaLvl HAL_SENSORS_GetAmoniaLvl(void){
	HAL_SENSORS_tAmoniaLvl temp ;
	temp = MCAL_ADC_ReadChannel(HAL_SENSORS_AMONIACHANNEL);
	return temp ;
}
HAL_SENSORS_tTempLvl HAL_SENSORS_GetTempLvl(void){
	HAL_SENSORS_tTempLvl  tempDC=0 , tempBI;
	 u8 rem ,base=1;
	tempBI = (MCAL_ADC_ReadChannel(HAL_SENSORS_TEMPCHANNEL)&&((u32)0b00000000000000001111111111111111));
	 while (tempBI> 0)
	    {
	        rem = tempBI % 10;
	        tempDC = tempDC + rem * base;
	        tempBI = tempBI / 10 ;
	        base = base * 2;
	    }
	return (tempDC / 10);
}
HAL_SENSORS_tHumLvl HAL_SENSORS_GetHumLvl(void){
	HAL_SENSORS_tTempLvl  humDC=0 , humBI;
		 u8 rem ,base=1;
		humBI = (MCAL_ADC_ReadChannel(HAL_SENSORS_HUMCHANNEL)&&((u32)0b11111111111111110000000000000000));
		humBI = (humBI>>16);
		 while (humBI> 0)
		    {
		        rem = humBI % 10;
		        humDC = humDC + rem * base;
		        humBI = humBI / 10 ;
		        base = base * 2;
		    }
		return (humDC / 10);
}
HAL_SENSORS_tCo2Lvl HAL_SENSORS_GetCo2Lvl(void){
	HAL_SENSORS_tCo2Lvl temp ;
	temp = MCAL_ADC_ReadChannel(HAL_SENSORS_COCHANNEL);
	return temp ;
}

