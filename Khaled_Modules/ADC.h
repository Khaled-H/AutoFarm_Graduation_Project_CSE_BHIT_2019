/*
 * ADC.h
 *
 *  Created on: Apr 24, 2019
 *      Author: khale
 */

#ifndef ADC_H_
#define ADC_H_

#include "STD_TYPES.h"

/*********** MCAL_ADC data_types *************/
typedef u32 MCAL_ADC_tInputData;
typedef struct
{
	HWREG32 SR;
	HWREG32 CR1;
	HWREG32 CR2;
	HWREG32 SMPR1;
	HWREG32 SMPR2;
	HWREG32 JOFR1;
	HWREG32 JOFR2;
	HWREG32 JOFR3;
	HWREG32 JOFR4;
	HWREG32 HTR;
	HWREG32 LTR;
	HWREG32 SQR1;
	HWREG32 SQR2;
	HWREG32 SQR3;
	HWREG32 JSQR;
	HWREG32 JDR1;
	HWREG32 JDR2;
	HWREG32 JDR3;
	HWREG32 JDR4;
	HWREG32 DR;
} MCAL_ADC_tType;

/*** ADC1 base address  ***/
#define  MCAL_ADC1 (*((volatile MCAL_ADC_tType*const)(0x40012400)))

/***   MCAL_ADC Functions Prototypes  ***/
void MCAL_ADC_Init();
MCAL_ADC_tInputData MCAL_ADC_ReadChannel(MCAL_ADC_tChannelType ChannelNum);

#endif /* ADC_H_ */
