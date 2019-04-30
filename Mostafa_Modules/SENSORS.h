/*
 * SENSORS.h
 *
 *  Created on: Apr 12, 2019
 *      Author: Mostafa Samir Nawar		Mostafa.nwar@yahoo.com
 */

#ifndef SENSORS_H_
#define SENSORS_H_
#include "STD_TYPES.h"
#include "ADC.h"
#include "DH22.h"
/************ TYPES SIZES NEED TO BE REVIEWED BY HARDWARE MAN >> Khaled      ***************/
typedef u8 HAL_SENSORS_tAmoniaLvl;
typedef u8 HAL_SENSORS_tCo2Lvl;

extern void HAL_SENSORS_Init(void);
extern HAL_SENSORS_tAmoniaLvl HAL_SENSORS_GetAmoniaLvl(void);
extern HAL_SENSORS_tDH22ReturnType HAL_SENSORS_GetDH22Lvls(void);
extern HAL_SENSORS_tCo2Lvl HAL_SENSORS_GetCo2Lvl(void);

/************ TYPES SIZES NEED TO BE REVIEWED BY HARDWARE MAN >> Khaled      ***************/
