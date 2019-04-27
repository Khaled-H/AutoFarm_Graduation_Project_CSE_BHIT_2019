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
HAL_SENSORS_tTempLvl HAL_SENSORS_GetDH22Lvl(HAL_SENSORS_tTempLvl HAL_SENSOR_OutputType){
	HAL_SENSORS_tTempLvl Rh_byte1,Rh_byte2,Temp_byte1,Temp_byte2,tempDC,RhDC;
	u16 tempBI,RhBI,sum;
	HAL_SENSORS_tTempLvl rem ,base=1;
	HAL_DHT22_Start();
	HAL_DHT22_CheckResponse();
	Rh_byte1 = read_data ();
	Rh_byte2 = read_data ();
	Temp_byte1 = read_data ();
	Temp_byte2 = read_data ();
	sum = read_data();
	if(sum==(Rh_byte1+Rh_byte2+Temp_byte1+Temp_byte2)){
		tempBI= ((Temp_byte1<<8)|Temp_byte2);
		RhBI = ((Rh_byte1<<8)|Rh_byte2);
	}
	while (tempBI> 0)
	{
		rem = tempBI % 10;
		tempDC = tempDC + rem * base;
		tempBI = tempBI / 10 ;
		base = base * 2;
	}
	while (RhBI> 0)
	{
		rem = RhBI % 10;
		RhDC = RhDC + rem * base;
		RhBI = RhBI / 10 ;
		base = base * 2;
	}
	switch (HAL_SENSOR_OutputType){
	case GetTempreture :
		return (tempDC/10);
		break;
	case GetHumdity :
		return (RhDC / 10);
		break;
	}
}

HAL_SENSORS_tCo2Lvl HAL_SENSORS_GetCo2Lvl(void){
	HAL_SENSORS_tCo2Lvl temp ;
	temp = MCAL_ADC_ReadChannel(HAL_SENSORS_COCHANNEL);
	return temp ;
}

