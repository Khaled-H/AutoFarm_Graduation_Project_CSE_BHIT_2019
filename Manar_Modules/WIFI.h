/*
 * WIFI.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: manar
 */

#ifndef WIFI_H_
#define WIFI_H_

#include "STD_TYPES.h"
#include "USART.h"

/*Dont Erase these 2 below Comments */
//#define WIFI_RD_CHANNEL		(UART_RD_CHANNEL_1)
//#define WIFI_WRT_CHANNEL	(UART_WRT_CHANNEL_1)


/**********************************************************************
 * 					WIFI_Init
 **********************************************************************
 * 	Function to Init Wifi Connections and State*/
void HAL_WIFI_Init(void);

/**********************************************************************
 * 					WIFI_Send_Byte
 **********************************************************************
 * 	Function to Send a Byte to the Wifi/ESP Module */
void HAL_WIFI_SendByte(u8 Value);

/**********************************************************************
 * 					WIFI_Read_Byte
 **********************************************************************
 * 	Function to Read a Byte from the WIFI/ESP Module */
void HAL_WIFI_ReadByte(void);






#endif /* WIFI_H_ */
