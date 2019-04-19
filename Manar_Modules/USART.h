/*
 * UART.h
 *
 *  Created on: Mar 1, 2019
 *      Author: Mostafa Samir Nawar
 */

#ifndef HEADERS_UART_H_
#define HEADERS_UART_H_
#include "STD_Type.h"
#include "st32myReg.h"

void MCAL_UART1_Init(void);
/*Synch*/
void MCAL_UART1_SendByte(u8 Value );
/*Synch*/
u8 MCAL_UART1_ReadByte(void);

#endif /* HEADERS_UART_H_ */
