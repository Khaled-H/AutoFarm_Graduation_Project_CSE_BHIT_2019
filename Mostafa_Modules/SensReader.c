/*
 * SensValues.c
 *
 *  Created on: Apr 3, 2019
 *      Author: Mostafa Samir Nawar		Mostafa.nwar@yahoo.com
 */
#include "SNSRDR.h"
#include "BUFFER.h"


static HAL_SENSORS_tTempLvl       LastTempValue;
static HAL_SENSORS_tHumLvl        LastHumValue;
static HAL_SENSORS_tAmoniaLvl     LastAmoniaValue;
static HAL_SENSORS_tCo2Lvl        LastCo2Value;

extern void APP_SENSORREADER_Init(){
  HAL_SENSORS_Init();
}

extern HAL_SENSORS_tTempLvl APP_SENSORREADER_GetTempLvl(){
return (LastTempValue);
}

extern HAL_SENSORS_tHumLvl APP_SENSORREADER_GetHumLvl(){
  return (LastHumValue);

}

extern HAL_SENSORS_tAmoniaLvl APP_SENSORREADER_GetAmoniaLvl(){
  return (LastAmoniaValue);

}
extern HAL_SENSORS_tCo2Lvl APP_SENSORREADER_GetCo2Lvl(){
  return (LastCo2Value);

}

/*Task, 15 sec period, Update an existing buffer with last updates, Execution time Less than 500us */
extern void APP_SENSORREADER_TaskLvlsUpdate(){
  LastAmoniaValue=HAL_SENSORS_GetAmoniaLvl();
  //Amonia_Buffer_Push(LastAmoniaValue);
  LastTempValue = HAL_SENSORS_GetTempLvl();
  //Temp_Buffer_Push(LastTempValue);
  LastHumValue=HAL_SENSORS_GetHumLvl();
  //Hum_Buffer_Push(LastHumValue);
  LastCo2Value = HAL_SENSORS_GetCo2Lvl();
  //Co2_Buffer_Push(LastCo2Value);
}

