/*
 * PORT_TEST_UNIT.c
 *
 *  Created on: Apr 19, 2019
 *      Author: Khaled
 */

#include "PORT.h"

#define RCC_PORTC_EN (*((volatile u32 * const)(0x40021018)))
int main()
{
MCAL_PORT_Init();
RCC_PORTC_EN = 0x4;
while(1)
  {
		MCAL_DIO_WritePin( HAL_LED_PORT,PIN_HIGH,HAL_LED_PIN);
		for(int i=0; i<5000000; i++);
		MCAL_DIO_WritePin( HAL_LED_PORT,PIN_LOW,HAL_LED_PIN);
		for(int i=0; i<5000000; i++);
	}

return 0;
}
 /* check my branch*/


