/*
 * LEDS.h
 *
 *  Created on: Apr 20, 2019
 *      Author: Mostafa Samir Nawar		Mostafa.nwar@yahoo.com
 */

#ifndef LEDS_H_
#define LEDS_H_
#include "STD_TYPES.h"
#include "PORT.h"
#include "DIO.h"



extern void HAL_LEDS_NormalModeLed_ON(void);
extern void HAL_LEDS_OTAModeLed_ON(void);
extern void HAL_LEDS_NormalModeLed_OFF(void);
extern void HAL_LEDS_OTAModeLed_OFF(void);
extern void HAL_LEDS_NormalModeLed_Toggle(void);
extern void HAL_LEDS_OTAModeLed_Toggle(void);



#endif /* LEDS_H_ */
