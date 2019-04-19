/*
 * FAN(1).h
 *
 *  Created on: ??þ/??þ/????
 *      Author: manar
 */

#ifndef INCLUDE_FAN_1__H_
#define INCLUDE_FAN_1__H_
#include "STD_Type.h"
#include "st32myReg.h"
#define FAN_UPPERFAN (1)  //PB6
#define FAN_LOWERFAN (2)  //PB7
//**fan will connect to pin PB6.. ..PB7 **//
void HAL_FAN_Init(void);
void HAL_FAN_FanOn(u8 FanNumber);
void HAL_FAN_FanOff(u8 FanNumber);


#endif /* INCLUDE_FAN_1__H_ */
