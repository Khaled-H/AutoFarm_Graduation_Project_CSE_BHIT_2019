/*
 * USART.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: manar
 */

#ifndef USART_H_
#define USART_H_
#include "STD_TYPES.h"

void MCAL_UART1_Init(void);
/*Synch*/
void MCAL_UART1_SendByte(u8 Value );
/*Synch*/
u8 MCAL_UART1_ReadByte(void);

#endif /* USART_H_ */
