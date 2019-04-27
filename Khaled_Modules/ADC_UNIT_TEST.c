/*
 * ADC_UNIT_TEST.c
 *
 *  Created on: Apr 24, 2019
 *      Author: khale
 */
#include "DIO.h"
#include "PORT.h"
#include "ADC.h"
#define RCC_EN  (*((volatile u32 * const)(0x40021018)))
#define RCC_EN1 (*((volatile u32 * const)(0x40021004)))


int main (){
	RCC_EN = 0x215;    // enable the clock for the AFIO & and ADC1
	u8 ChannelNumber  = 4;
	u32 InputChannelValue = 0;
	MCAL_ADC_Init();
	while(1){
		InputChannelValue = MCAL_ADC_ReadChannel (ChannelNumber);
		if (InputChannelValue > 1)
		{
			MCAL_DIO_WritePin(HAL_LEDS_OTALED_PORT,HAL_LEDS_OTALED_PIN,STD_HIGH);

		}
		else{}

		//MCAL_DIO_WritePin(HAL_LEDS_NORMALMODELED_PORT,HAL_LEDS_NORMALMODELED_PIN,STD_LOW)	;
	}
}

