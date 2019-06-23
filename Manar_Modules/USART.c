/*
 * USART.c
 *
 *  Created on: ??�/??�/????
 *      Author: manar
 */
#include "USART.h"


typedef struct {
	HWREG32 SR;
	HWREG32 DR;
	HWREG32 BRR;
	HWREG32 CR1;
	HWREG32 CR2;
	HWREG32 CR3;
	HWREG32 GTPR;
}USART1_typedef;

#define USART1 (*((volatile USART1_typedef * const )(0x40013800)))


void MCAL_UART1_Init(void){

	/* Init the UART module Connections and Mode as
	 * 9600 bps, 8 bit data, no parity, 1 stop bit *
	enable Clock GPIOB
	Enable Clock to USART 1
	pin PB6 TX set as alternative push pull
	pin PB7 set as input floating
	 *AFIO.MAPR.Bit02=1;
	 remape register
	*/
	USART1.BRR.REG_FULL_32 = (u32)0x00000521; //baud rate 9600
	USART1.CR1.REG_FULL_32 = (u32)0x0000200C; // enable receive bit ..transmit enable ..enable USART1*/
}

void MCAL_UART1_SendByte(u8 Value ){
	 USART1.DR.REG_FULL_32 = (u32)Value; //wait to transition to complete
	 while(USART1.SR.REG_FULL_32 == (u32)0x000000C0);//TXE & TC
}

u8 MCAL_UART1_ReadByte(void){

	 while(USART1.SR.REG_FULL_32 == (u32)0x00000020); //wait until recieve is complete RXNE bit
     return ((u8)(USART1.DR.REG_FULL_32 & 0x000000FF));   //return(0xFF & USART1.DR)?? return readed data
}


