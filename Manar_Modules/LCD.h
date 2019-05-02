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

// LCD 4 bit mode macros
#define LCD_4BITMODE_DATA_OUT(OUTPUT_DATA)      (DIO_PORTB.DIO_ODR= (DIO_PORTB.DIO_ODR & ~(0x000F <<  12)) | (OUTPUT_DATA << 12))

#define HAL_LCD_FIRSTROW (1)
#define HAL_LCD_SECONDROW (2)
#define HAL_LCD_COLUMN1 (1)
#define HAL_LCD_COLUMN2 (2)
#define HAL_LCD_COLUMN3 (3)
#define HAL_LCD_COLUMN4 (4)
#define HAL_LCD_COLUMN5 (5)
#define HAL_LCD_COLUMN6 (6)
#define HAL_LCD_COLUMN7 (7)
#define HAL_LCD_COLUMN8 (8)
#define HAL_LCD_COLUMN9  (9)
#define HAL_LCD_COLUMN10 (10)
#define HAL_LCD_COLUMN11 (11)
#define HAL_LCD_COLUMN12 (12)
#define HAL_LCD_COLUMN13 (13)
#define HAL_LCD_COLUMN14 (14)
#define HAL_LCD_COLUMN15 (15)
#define HAL_LCD_COLUMN16 (16)

#define HAL_LCD_CLEAR HAL_LCD_WriteCommand(0x01)  // Macro for Clear in the LCD

extern void HAL_LCD_Init();
extern void HAL_LCD_WriteChar(u8 Value);
extern void HAL_LCD_WriteCommand(u8 Value);
extern void HAL_LCD_WriteString(u8 *arry);
extern void HAL_LCD_WriteNumber(u8 Value);
extern void HAL_LCD_SetCursor(u8 RowNumber,u8 ColomNumber);

#endif /* LCD_H_ */



