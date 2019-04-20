/*
 * SW.h
 *
 *  Created on: Apr 13, 2019
 *      Author: Mostafa Samir Nawar		Mostafa.nwar@yahoo.com
 */

#ifndef SWITCHES_H_
#define SWITCHES_H_
#include "STD_TYPES.h"
#include "PORT.h"
#include "DIO.h"
/*************      REVIEWED by HARDWARE Man >> Khaled      ***************/
typedef enum{
  SWITCHES_RELEASED,
  SWITCHES_PREPRESSED,
  SWITCHES_PRESSED,
  SWITCHES_PRERELEASED
}HAL_SWITCHES_tStates;
/*************      REVIEWED by HARDWARE Man >> Khaled      ***************/
typedef enum{
  SWITCHES_MODESW,
  SWITCHES_OKSW,
  SWITCHES_PLUSSW,
  SWITCHES_MINUSSW
}HAL_SWITCHES_tTypes;


extern void HAL_SWITCHES_Init(void);
extern HAL_SWITCHES_tStates HAL_SWITCHES_GetState(HAL_SWITCHES_tTypes Switch);
extern void HAL_SWITCHES_TaskStateUpdate(void);


#endif /* SWITCHES_H_ */
