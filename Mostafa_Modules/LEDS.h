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


#define HAL_LEDS_LEDON  (1)
#define HAL_LEDS_LEDOFF (0)

extern void HAL_LEDS_NormalLed_ON(void);
extern void HAL_LEDS_OTALed_ON(void);
extern void HAL_LEDS_NormalLed_OFF(void);
extern void HAL_LEDS_OTALed_OFF(void);
extern void HAL_LEDS_NormalLed_Toggle(void);
extern void HAL_LEDS_OTALed_Toggle(void);



#endif /* LEDS_H_ */
