/*
 * ADC.h
 *
 *  Created on: Apr 24, 2019
 *      Author: khale
 */

#ifndef ADC_H_
#define ADC_H_

#include "STD_TYPES.h"
#include "PORT.h"

/*********** MCAL_ADC data_types *************/
typedef u32 MCAL_ADC_tInputData;
typedef struct
{
	u32 SR;
	u32 CR1;
	u32 CR2;
	u32 SMPR1;
	u32 SMPR2;
	u32 JOFR1;
	u32 JOFR2;
	u32 JOFR3;
	u32 JOFR4;
	u32 HTR;
	u32 LTR;
	u32 SQR1;
	u32 SQR2;
	u32 SQR3;
	u32 JSQR;
	u32 JDR1;
	u32 JDR2;
	u32 JDR3;
	u32 JDR4;
	u32 DR;
} MCAL_ADC_tType;

/*** ADC1 base address  ***/
#define  MCAL_ADC1 (*((volatile MCAL_ADC_tType*const)(0x40012400)))

/***   MCAL_ADC Functions Prototypes  ***/
void MCAL_ADC_Init();
MCAL_ADC_tInputData MCAL_ADC_ReadChannel(MCAL_ADC_tChannelType ChannelNum);

#endif /* ADC_H_ */
