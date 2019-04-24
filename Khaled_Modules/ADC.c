/*
 * ADC.c
 *
 *  Created on: Apr 24, 2019
 *      Author: khale
 */

#include "ADC.h"
#include "PORT.h"

void MCAL_ADC_Init() {

	MCAL_ADC1.CR1.REG_FULL_32 |= 1<<5;              // enable the end of conversion interrupt pin
	MCAL_ADC1.SMPR2.REG_FULL_32 = 0xF;              // Initialization of the channel conversion sampling time
	MCAL_ADC1.SQR1.REG_FULL_32 = 0x100000;          // Activate 1 ADC channels
	MCAL_ADC1.CR2.REG_FULL_32 |= 1<<2;              // activate calibration pin
	while (MCAL_ADC1.CR2.Bit02);                    // delay for calibration
}

MCAL_ADC_tInputData MCAL_ADC_ReadChannel(MCAL_ADC_tChannelType ChannelNum ){
	MCAL_ADC_tInputData AdcInputData = 0;
	switch (ChannelNum){
	case MCAL_ADC_CHANNEL00 :
		MCAL_ADC1.SQR3.REG_FULL_32 = 0;         // define the channel number of the first sequence
		MCAL_ADC1.CR2.REG_FULL_32 |= 1<<0;      // power on
		for (int i = 0; i<10000; i++);          // delay for almost 1ms
		MCAL_ADC1.CR2.REG_FULL_32 |= 1<<0;      //start conversion
		break;
	case MCAL_ADC_CHANNEL01 :
		MCAL_ADC1.SQR3.REG_FULL_32 = 1;
		MCAL_ADC1.CR2.REG_FULL_32 |= 1<<0;
		for (int i = 0; i<10000; i++);
		MCAL_ADC1.CR2.REG_FULL_32 |= 1<<0;
		break;
	case MCAL_ADC_CHANNEL02 :
		MCAL_ADC1.SQR3.REG_FULL_32 = 2;
		MCAL_ADC1.CR2.REG_FULL_32 |= 1<<0;
		for (int i = 0; i<10000; i++);
		MCAL_ADC1.CR2.REG_FULL_32 |= 1<<0;
		break;
	case MCAL_ADC_CHANNEL03 :
		MCAL_ADC1.SQR3.REG_FULL_32 = 3;
		MCAL_ADC1.CR2.REG_FULL_32 |= 1<<0;
		for (int i = 0; i<10000; i++);
		MCAL_ADC1.CR2.REG_FULL_32 |= 1<<0;
		break;

	}

// wait until the end of conversion(EOC) flag set
	while( MCAL_ADC1.SR.Bit01)
	{
		AdcInputData = MCAL_ADC1.DR.REG_FULL_32;
	}
	return (AdcInputData);
}

