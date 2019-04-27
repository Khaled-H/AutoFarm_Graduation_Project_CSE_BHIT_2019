/*
 * SENSORS.h
 *
 *  Created on: Apr 12, 2019
 *      Author: Mostafa Samir Nawar		Mostafa.nwar@yahoo.com
 */

#ifndef SENSORS_H_
#define SENSORS_H_
#include "ADC.h"
#include "DH22.h"
/************ TYPES SIZES NEED TO BE REVIEWED BY HARDWARE MAN >> Khaled      ***************/

typedef u8 HAL_SENSORS_tTempLvl;
typedef u8 HAL_SENSORS_tAmoniaLvl;
typedef u8 HAL_SENSORS_tCo2Lvl;
/************** TYPES OF OUTPUT BY DH22 SENSOR*************************/
#define GetTempreture (1)
#define GetHumdity    (2)
/************ TYPES SIZES NEED TO BE REVIEWED BY HARDWARE MAN >> Khaled      ***************/

void HAL_SENSORS_Init(void);
HAL_SENSORS_tAmoniaLvl HAL_SENSORS_GetAmoniaLvl(void);
HAL_SENSORS_tTempLvl HAL_SENSORS_GetDH22Lvl(HAL_SENSORS_tTempLvl HAL_SENSOR_OutputType);
HAL_SENSORS_tCo2Lvl HAL_SENSORS_GetCo2Lvl(void);



#endif /* SENSORS_H_ */
