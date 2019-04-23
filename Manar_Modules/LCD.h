/*
 * LCD.h
 *
 *  Created on: Apr 20, 2019
 *      Author: Mostafa Samir Nawar		Mostafa.nwar@yahoo.com
 */

#ifndef LCD_H_
#define LCD_H_

/*
 * LCD.h
 *
 *  Created on: Nov 3, 2017
 *      Author: Mostafa
 */

#ifndef _LCD_H__
#define _LCD_H__
#include "STD_TYPES.h"
#include "DIO.h"
#include "PORT.h"
#define HAL_LCD_CLEAR HAL_LCD_WriteCommand(0x01) // Macro for Clearin the LCD

extern void HAL_LCD_Init();
extern void HAL_LCD_WriteChar(u8 Value);
extern void HAL_LCD_WriteCommand(u8 Value);
extern void HAL_LCD_WriteString(u8 *arry);
extern void HAL_LCD_WriteNumber(u8 Value);
void _delay_ms(u8 DelayTime);


#endif /* LCD_H_ */


#endif /* LCD_H_ */
