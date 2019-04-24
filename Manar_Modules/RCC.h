/*
 * RCC.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: manar
 */

#ifndef RCC_H_
#define RCC_H_
#include "STD_TYPES.h"
typedef enum
{
MCAL_RCC_PORTA,
MCAL_RCC_PORTB,
MCAL_RCC_PORTC,
MCSL_RCC_USART1,
MCAL_RCC_ADC1,
MCAL_RCC_ADC2,
MCAL_RCC_ADC3,
}RCC_TPrepheral_Number;
typedef struct {
	HWREG32 CR;
	HWREG32 CFGR;
	HWREG32 CIR;
	HWREG32 APB2RSTR;
	HWREG32 APB1RTSR;
	HWREG32 AHBENR;
	HWREG32 APB2ENR;
	HWREG32 APB1ENR;
	HWREG32 BDCR;
	HWREG32 CSR;
}RCC_typedef;
#define RCC   (*(( volatile RCC_typedef* const )(0x40021000)))

void MCAL_RCC_SystemInit(void);
void MCAL_RCC_PrepheralEnable(RCC_TPrepheral_Number PrepheralNumber);

#endif /* RCC_H_ */
