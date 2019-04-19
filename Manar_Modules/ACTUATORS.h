/*
 * ACTUATORS.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: manar
 */

#ifndef ACTUATORS_H_
#define ACTUATORS_H_
#include "STD_TYPES.h"

#define FAN_UPPERFAN (1)  //PB6
#define FAN_LOWERFAN (2)  //PB7
//**fan will connect to pin PB6.. ..PB7 **//
void HAL_FAN_Init(void);
void HAL_FAN_On(u8 FanNumber);
void HAL_FAN_Off(u8 FanNumber);

#endif /* ACTUATORS_H_ */
