/*
 * DH22.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: manar
 */

#ifndef DH22_H_
#define DH22_H_
#include "STD_TYPES.h"
#include "PORT.h"
#include "DIO.h"
void HAL_DHT22_Start (void);
void HAL_DHT22_CheckResponse (void);
u8 HAL_DHT22_ReadData(void);
#endif /* DH22_H_ */
