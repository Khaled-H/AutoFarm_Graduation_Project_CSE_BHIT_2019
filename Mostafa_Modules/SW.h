/*
 * SW.h
 *
 *  Created on: Apr 13, 2019
 *      Author: Mostafa Samir Nawar		Mostafa.nwar@yahoo.com
 */

#ifndef SW_H_
#define SW_H_
#include "STD_Types.h"
#include "DIO.h"
/*************      REVIEWED by HARDWARE Man >> Khaled      ***************/
typedef enum{
  SW_RELEASED,
  SW_PREPRESSED,
  SW_PRESSED,
  SW_PRERELEASED
}HAL_SW_tStates;
/*************      REVIEWED by HARDWARE Man >> Khaled      ***************/
typedef enum{
  SW_MODESW,
  SW_OKSW,
  SW_PLUSSW,
  SW_MINUSSW
}HAL_SW_tTypes;


extern void HAL_SW_Init(void);
extern HAL_SW_tStates HAL_SW_GetState(HAL_SW_tTypes Switch);
extern void HAL_SW_TaskStateUpdate(void);


#endif /* SW_H_ */
