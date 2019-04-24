/*
 * DISPALY.h
 *
 *  Created on: Apr 24, 2019
 *      Author: Mostafa Samir Nawar		Mostafa.nwar@yahoo.com
 */

#ifndef DISPALY_H_
#define DISPALY_H_
#include "STD_TYPES.h"
#include "LCD.h"

/*Initialization Function*/
extern void APP_DISPLAY_INIT(void);
/*Task to Come every 15 ms to refresh the LCD Display*/
extern void APP_DISPLAY_Task(void);


#endif /* DISPALY_H_ */
