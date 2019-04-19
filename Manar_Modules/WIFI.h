/*
 * WIFI.h
 *
 *  Created on: Mar 1, 2019
 *      Author: Mostafa Samir Nawar
 */

#ifndef HEADERS_WIFI_H_
#define HEADERS_WIFI_H_
#include "STD_Types.h"

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



/**************************************************************************************
 * 								Optional/Advanced Implementations 					  *
 **************************************************************************************
 */
void WIFI_Send_Block(u8 * Block_Start_Ptr, u32 Block_Size );
void WIFI_Read_Block(u8 * Block_Start_Ptr, u32 Block_Size );

#endif /* HEADERS_WIFI_H_ */
