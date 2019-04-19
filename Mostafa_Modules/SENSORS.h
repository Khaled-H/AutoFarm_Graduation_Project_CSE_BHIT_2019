/*
 * SENSORS.h
 *
 *  Created on: Apr 12, 2019
 *      Author: Mostafa Samir Nawar		Mostafa.nwar@yahoo.com
 */

#ifndef SENSORS_H_
#define SENSORS_H_
#include "STD_Types.h"
#include "ADC.h"

/************ TYPES SIZES NEED TO BE REVIEWED BY HARDWARE MAN >> Khaled      ***************/

typedef u8 HAL_SENSORS_tTempLvl;
typedef u8 HAL_SENSORS_tHumLvl;
typedef u8 HAL_SENSORS_tAmoniaLvl;
typedef u8 HAL_SENSORS_tCo2Lvl;
/************ TYPES SIZES NEED TO BE REVIEWED BY HARDWARE MAN >> Khaled      ***************/

void HAL_SENSORS_Init(void);
HAL_SENSORS_tAmoniaLvl HAL_SENSORS_GetAmoniaLvl(void);
HAL_SENSORS_tTempLvl HAL_SENSORS_GetTempLvl(void);
HAL_SENSORS_tHumLvl HAL_SENSORS_GetHumLvl(void);
HAL_SENSORS_tCo2Lvl HAL_SENSORS_GetCo2Lvl(void);



#endif /* SENSORS_H_ */
