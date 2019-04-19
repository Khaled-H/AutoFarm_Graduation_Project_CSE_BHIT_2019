/*
 * SNSRDR.h
 *
 *  Created on: Apr 13, 2019
 *      Author: Mostafa Samir Nawar		Mostafa.nwar@yahoo.com
 */

#ifndef SNSRDR_H_
#define SNSRDR_H_
#include "STD_Types.h"
#include "SENSORS.h"

extern void APP_SENSORREADER_Init();
extern HAL_SENSORS_tTempLvl APP_SENSORREADER_GetTempLvl();

extern HAL_SENSORS_tHumLvl APP_SENSORREADER_GetHumLvl();
extern HAL_SENSORS_tAmoniaLvl APP_SENSORREADER_GetAmoniaLvl();
extern HAL_SENSORS_tCo2Lvl APP_SENSORREADER_GetCo2Lvl();
/*Task, 1 sec period, Update an existing buffer with last updates*/
extern void APP_SENSORREADER_TaskLvlsUpdate();
#endif /* SNSRDR_H_ */
