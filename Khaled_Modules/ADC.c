/*
 * ADC.c
 *
 *  Created on: Apr 24, 2019
 *      Author: khale
 */

#include "ADC.h"
#include "PORT.h"

void MCAL_ADC_Init(){

	MCAL_ADC1.CR2 |= (0 << 1);                      //Enable single mode conversion
	MCAL_ADC1.CR2 |= (0 << 11);                     // enable right data alignment
	MCAL_ADC1.SQR1 = 0;                             // Activate 1 ADC channels
	/***********************************************************************************************************/
	MCAL_ADC1.CR2 |= (1 << 0);                      // walk up the ADC from the power down mode
	for (int i = 0; i < 8000; i++);                 // delay for 1ms to walk up the ADC
	MCAL_ADC1.CR2 |= (1 << 0);                      // power on the ADC
	/************************************************************************************************************/
	MCAL_ADC1.CR2 |= (1 << 2);                      // enable the internal ADC calibration
	for (int i = 0; i < 16000; i++);                // delay for 2ms to calibrate the ADC


}

MCAL_ADC_tInputData MCAL_ADC_ReadChannel(MCAL_ADC_tChannelType ChannelNum){

	MCAL_ADC_tInputData AdcInputData = 0;       // define a variable to store the input analog data

	switch (ChannelNum){
	case MCAL_ADC_CHANNEL04 :
		MCAL_ADC1.SQR3 = 4;                     // define the channel number of the first sequence
		MCAL_ADC1.CR2 |= (1 << 0);              // start conversion
		break;
	case MCAL_ADC_CHANNEL05 :
		MCAL_ADC1.SQR3 = 5;
		MCAL_ADC1.CR2 |= (1 << 0);
		break;
	case MCAL_ADC_CHANNEL06 :
		MCAL_ADC1.SQR3 = 6;
		MCAL_ADC1.CR2 |= (1 << 0);
		break;
	case MCAL_ADC_CHANNEL07 :
		MCAL_ADC1.SQR3 = 7;
		MCAL_ADC1.CR2 |= (1 << 0);
		break;
	}

	/*wait until the end of conversion(EOC) flag set */

	while((MCAL_ADC1.SR & 2) != 2);
	AdcInputData = MCAL_ADC1.DR;                 //get the input analog data
	MCAL_ADC1.CR2 |= (0 << 0);                   //Force ADC to the power down mode
	MCAL_ADC1.DR = 0;                            //clear the input analog data register

	 // convert the sensor reading to voltage in volts
	AdcInputData = ((AdcInputData / ADC_HIGHEST_LEVEL) * ADC_REFERANCE_VOLTAGE) ;
	return (AdcInputData);
}


