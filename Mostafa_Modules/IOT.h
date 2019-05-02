/*
 * IOT.h
 *
 *  Created on: Apr 13, 2019
 *      Author: Mostafa Samir Nawar		Mostafa.nwar@yahoo.com
 */

#ifndef IOT_H_
#define IOT_H_
#include "STD_TYPES.h"
#include "SENSORSREADER.h"
#include "WIFI.h"

extern void APP_IOT_Init();

/*Task, 15 Sec , Send Data to WIFI Module , Execution Time more than 4ms  */
extern void APP_IOT_SendPacket(void);
#endif /* IOT_H_ */
