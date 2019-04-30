/*
 * DH22.h
 *
 *  Created on: ??�/??�/????
 *      Author: manar
 */

#ifndef DH22_H_
#define DH22_H_

#include "STD_TYPES.h"
#include "PORT.h"
#include "DIO.h"

// DHT Pin Configuration
typedef struct {
	u16 Temp ;
	u16 Hum ;
}HAL_SENSORS_tDH22ReturnType;

extern HAL_SENSORS_tDH22ReturnType HAL_DHT22_Read(void);

#endif /* DH22_H_ */
