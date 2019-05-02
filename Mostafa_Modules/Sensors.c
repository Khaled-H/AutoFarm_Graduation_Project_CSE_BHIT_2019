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

	HAL_SENSORS_tAmoniaLvl SesonrOutputVoltage ;            // sensor output voltage in volts
	HAL_SENSORS_tAmoniaLvl RS = 0;                          // MQ135 sensor surface resistance in gas high concentration
    HAL_SENSORS_tAmoniaLvl RO = 0;                          // MQ135 sensor surface resistance in pure air
	HAL_SENSORS_tAmoniaLvl SurfaceResistanceRatio = 0;      //surface resistance ratio (RS/RO)
	HAL_SENSORS_tAmoniaLvl AmmoniaLvl;

	// get the sensor output voltage
	SesonrOutputVoltage = MCAL_ADC_ReadChannel(HAL_SENSORS_AMONIACHANNEL);

	// AMMONIA Level Calculation
	RS = ((ADC_REFERANCE_VOLTAGE - SesonrOutputVoltage )/ADC_REFERANCE_VOLTAGE);
	RO = RS / 3.6;                                                   //3.6 is the  (RS/SO) ratio at 100 PPM of NH3 gas
    SurfaceResistanceRatio = RS / RO;
    AmmoniaLvl = SurfaceResistanceRatio * MAXIMUM_AMMONIIA_LVL;      // AMMONIA gas level in PPM
	return AmmoniaLvl ;
}
extern HAL_SENSORS_tDH22ReturnType HAL_SENSORS_GetDH22Lvls(void){
  return (HAL_DHT22_Read());

}
extern HAL_SENSORS_tCo2Lvl HAL_SENSORS_GetCo2Lvl(void){

	HAL_SENSORS_tCo2Lvl SesonrOutputVoltage ;            // sensor output voltage in volts
	HAL_SENSORS_tCo2Lvl RS = 0;                          // MQ9 sensor surface resistance in gas high concentration
	HAL_SENSORS_tCo2Lvl RO = 0;                          // MQ9 sensor surface resistance in pure air
	HAL_SENSORS_tCo2Lvl SurfaceResistanceRatio = 0;      //surface resistance ratio (RS/RO)
	HAL_SENSORS_tCo2Lvl CoLvl;

	// get the sensor output voltage
	SesonrOutputVoltage = MCAL_ADC_ReadChannel(HAL_SENSORS_COCHANNEL);

	// CO Level Calculation
	RS = ((ADC_REFERANCE_VOLTAGE - SesonrOutputVoltage )/ADC_REFERANCE_VOLTAGE);
	RO = RS / 9.9;                                          //9.9 is the  (RS/SO) ratio at 1000 PPM of LPG gas
    SurfaceResistanceRatio = RS / RO;
    CoLvl = SurfaceResistanceRatio * MAXIMUM_CO_LVL;        // CO gas level in PPM
	return CoLvl ;
}


 /*
  * for MQ9 calibration follow the steps:
  * ***************************************
  * 1)power up the sensor for 48 hours at least.
  * 2)connect the load resistor RL and adjust it for 200 PPM for CO level.
  * 3)then,Calculate the surface resistance(RO)for clean air,and make it constant.
  *
  * for MQ135 calibration follow the steps:
  * ***************************************
  * --> is the same of MQ9 sensor but;
  *  calibrate the sensor at 100ppm for ammonia level.
  */
