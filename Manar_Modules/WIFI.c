/*
 * WIFI.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: manar
 */
#include "WIFI.h"

void HAL_WIFI_Init(void){
	/*Init the Wifi Module Connections as UART Connections*/
	MCAL_UART1_Init();
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







