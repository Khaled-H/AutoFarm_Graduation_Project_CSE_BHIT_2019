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
void MCAL_RCC_SystemInit(void);
/*void MCAL_RCC_PrepheralEnable(RCC_TPrepheral_Number PrepheralName);*/

#endif /* RCC_H_ */
