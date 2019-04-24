/*
 * App.c
 *
 *  Created on: Apr 24, 2019
 *      Author: Mostafa Samir Nawar		Mostafa.nwar@yahoo.com
 */

#include "App.h"

extern void APP_TaskAppAlgorithm(void){
  /*Read Sensor Values*/
  APP_SENSORREADER_TaskLvlsUpdate();
  /*Control Motors*/
  APP_PROCESS_Process();
  /*update display */
  APP_DISPLAY_Task();
  /*Send Data to cloud*/
  HAL_WIFI_SendByte(APP_SENSORREADER_GetTempLvl());
  HAL_WIFI_SendByte(APP_SENSORREADER_GetHumLvl());
  HAL_WIFI_SendByte(APP_SENSORREADER_GetAmoniaLvl());
  HAL_WIFI_SendByte(APP_SENSORREADER_GetCo2Lvl());
}
