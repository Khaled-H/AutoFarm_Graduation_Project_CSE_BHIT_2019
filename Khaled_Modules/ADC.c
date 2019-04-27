/*
 * ADC.c
 *
 *  Created on: Apr 24, 2019
 *      Author: khale
 */

#include <ADC.h>
#include "PORT.h"

void MCAL_ADC_Init(){

	MCAL_ADC1.CR2 |= (1 << 1);                      //Enable continuous mode conversion
	MCAL_ADC1.CR2 |= (0 << 11);                     // enable right data alignment
	MCAL_ADC1.SMPR2 = 0x7;                          // Initialization of the channel conversion sampling time
	MCAL_ADC1.SQR1 = 0;                             // Activate 1 ADC channels
//  MCAL_ADC1.CR1 |= (1 << 5);                      // enable end of conversion interrupt
	MCAL_ADC1.CR2 |= (1 << 0);                      // walk up the ADC from the power down mode
//	for (int i = 0; i < 8000; i++);                 // delay for 1ms to walk up the ADC
//	MCAL_ADC1.CR2 |= (1 << 0);                      // power on the ADC
	MCAL_ADC1.CR2 |= (1 << 2);                      // enable the internal ADC calibration
	for (int i = 0; i < 16000; i++);                // delay for 2ms to calibrate the ADC
	MCAL_ADC1.CR2 |= (1 << 22);                     // start conversion


}

MCAL_ADC_tInputData MCAL_ADC_ReadChannel(MCAL_ADC_tChannelType ChannelNum){
	MCAL_ADC_tInputData AdcInputData = 0;
	switch (ChannelNum){
	case MCAL_ADC_CHANNEL00 :
		MCAL_ADC1.SQR3 = 4;         // define the channel number of the first sequence
		break;
	case MCAL_ADC_CHANNEL01 :
		MCAL_ADC1.SQR3 = 5;
		break;
	case MCAL_ADC_CHANNEL02 :
		MCAL_ADC1.SQR3 = 6;
		break;
	case MCAL_ADC_CHANNEL03 :
		MCAL_ADC1.SQR3 = 7;
		break;
	}

	// wait until the end of conversion(EOC) flag set
	while( MCAL_ADC1.SR != 2 )
	{
		AdcInputData = MCAL_ADC1.DR;
	}
	return (AdcInputData);
}


