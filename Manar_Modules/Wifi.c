/*
 * Wifi.c
 *
 *  Created on: Mar 1, 2019
 *      Author: Mostafa Samir Nawar
 */
#include "WIFI.h"
#include "UART.h"
void HAL_WIFI_Init(void){
	/*Init the Wifi Module Connections as UART Connections*/
	MCAL_UART1_UART1Init();
}
/*Synch*/
void HAL_WIFI_SendByte(u8 Value){
	/*Send a Byte "Value" To the Wifi Module*/
	 MCAL_UART1_SendByte( Value );
}
/*Synch*/
u8 HAL_WIFI_ReadByte(void){
	/*Read The Received Byte "Value" from the Wifi Module */
	return ( MCAL_UART1_ReadByte() );
}





