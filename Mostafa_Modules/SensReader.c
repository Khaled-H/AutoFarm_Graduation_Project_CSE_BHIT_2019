/*
 * SensValues.c
 *
 *  Created on: Apr 3, 2019
 *      Author: Mostafa Samir Nawar		Mostafa.nwar@yahoo.com
 */
#include "SENSORSREADER.h"


static HAL_SENSORS_tDH22ReturnType      LastDH22Value;
static HAL_SENSORS_tAmoniaLvl     LastAmoniaValue;
static HAL_SENSORS_tCo2Lvl        LastCo2Value;

extern void APP_SENSORREADER_Init(){
  HAL_SENSORS_Init();
}

extern HAL_SENSORS_tTempLvl APP_SENSORREADER_GetTempLvl(){
return ((HAL_SENSORS_tTempLvl)LastDH22Value.Temp);
}

extern HAL_SENSORS_tHumLvl APP_SENSORREADER_GetHumLvl(){
  return ((HAL_SENSORS_tHumLvl)LastDH22Value.Hum);

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
  LastDH22Value =HAL_SENSORS_GetDH22Lvl();
  //Temp_Buffer_Push(LastTempValue);
  //Hum_Buffer_Push(LastHumValue);
  LastCo2Value = HAL_SENSORS_GetCo2Lvl();
  //Co2_Buffer_Push(LastCo2Value);
}

