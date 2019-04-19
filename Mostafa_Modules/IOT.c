/*
 * IOT.c
 *
 *  Created on: Apr 13, 2019
 *      Author: Mostafa Samir Nawar		Mostafa.nwar@yahoo.com
 */

#include "IOT.h"
/*Task, 15 Sec , Send Data to WIFI Module , Execution Time more than 4ms  */
extern void APP_IOT_TaskSendPacket(void){
HAL_WIFI_SendByte(APP_SENSORREADER_GetAmoniaLvl());
HAL_WIFI_SendByte(APP_SENSORREADER_GetTempLvl());
HAL_WIFI_SendByte(APP_SENSORREADER_GetHumLvl());
HAL_WIFI_SendByte(APP_SENSORREADER_GetCo2Lvl());
}
