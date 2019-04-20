/*
 * PROCESS.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: manar
 */

#ifndef PROCESS_H_
#define PROCESS_H_
#include "ACTUATORS.h"
#include "SENSORSREADER.h"
HAL_SENSORS_tTempLvl Temp = APP_SENSORREADER_GetTempLvl();
HAL_SENSORS_tHumLvl  Hum= APP_SENSORREADER_GetHumLvl();
HAL_SENSORS_tAmoniaLvl Amonia = APP_SENSORREADER_GetAmoniaLvl() ;
HAL_SENSORS_tCo2Lvl   Co = APP_SENSORREADER_GetCo2Lvl();
void APP_PROCESS_Init(void);
void APP_PROCESS_Process(void);

#endif /* PROCESS_H_ */
