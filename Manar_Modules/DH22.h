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

// DHT Pin Configuration

#define HAL_DHT_PINOUT  DIO_PORTA.DIO_CRL |= 1 << 17;
#define HAL_DHT_PININ   DIO_PORTA.DIO_CRL |= 8 << 16;


void HAL_DHT22_Start (void);
void HAL_DHT22_CheckResponse (void);
u8 HAL_DHT22_ReadData(void);
#endif /* DH22_H_ */
