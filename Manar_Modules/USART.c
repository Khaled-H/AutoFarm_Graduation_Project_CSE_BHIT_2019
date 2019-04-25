/*
 * USART.c
 *
 *  Created on: ??þ/??þ/????
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
	SET PA9 and PA10 as outpout pins
	 *AFIO.MAPR.Bit02=1;
	 remape register
	 enable receive bit
	 transmit enable
	enable USART1*/
	USART1.BRR.REG_FULL_32=(u32)0x00000342; //baud rate 9600
	USART1.CR1.REG_FULL_32 = (u32)0x0000200C;
    USART1.CR3.REG_FULL_32=(u32)0x000000C0;
}

void MCAL_UART1_SendByte(u8 Value ){
/* Just Send the Argument "Value" to the Data Register */
	/*9th bit is for parity bit */
  //transfer data to buffer register DR
     while(USART1.SR.REG_FULL_32==(u32)0x00000080);
	 USART1.DR.REG_FULL_32 = (u32)Value; //wait to transition to complete
	 while(USART1.SR.REG_FULL_32==(u32)0x000000C0);//TXE & TC
}

u8 MCAL_UART1_ReadByte(void){
   /* Just Read The Received Byte From Data Register
    * Then Return it */
	 while(USART1.SR.REG_FULL_32==(u32)0x00000020); //wait until recieve is complete
     return ((u8)(USART1.DR && 0xFF));   //return(0xFF & USART1.DR)?? return readed data
}


