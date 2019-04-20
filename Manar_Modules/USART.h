/*
 * USART.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: manar
 */

#ifndef USART_H_
#define USART_H_
#include "STD_TYPES.h"
#include "RCC.h"
typedef struct {
	HWREG32 SR;
	HWREG32 DR;
	HWREG32 BRR;
	HWREG32 CR1;
	HWREG32 CR2;
	HWREG32 CR3;
	HWREG32 GTPR;
}USART1_typedef;

#define USART1  (*((volatile USART1_typedef * const )(0x40013800)))

void MCAL_UART1_Init(void);
/*Synch*/
void MCAL_UART1_SendByte(u8 Value );
/*Synch*/
u8 MCAL_UART1_ReadByte(void);

#endif /* USART_H_ */
