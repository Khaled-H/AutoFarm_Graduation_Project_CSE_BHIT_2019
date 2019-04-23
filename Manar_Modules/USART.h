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
    HWREG32 EVCR ;
    HWREG32 MAPR ;
    HWREG32 EXTICR1 ;
    HWREG32 EXTICR2;
    HWREG32 EXTICR3;
    HWREG32 EXTICR4 ;
}AFIO_typedef;
#define AFIO (*((volatile AFIO_typedef*const )(0x40010000)))

void MCAL_UART1_Init(void);
/*Synch*/
void MCAL_UART1_SendByte(u8 Value );
/*Synch*/
u8 MCAL_UART1_ReadByte(void);
/* TX AF push-pull ,RX input pullup or input floating */
#endif /* USART_H_ */
