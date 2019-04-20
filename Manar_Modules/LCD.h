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
#include "Types_Utilities.h"
#include "LCD_Config.h"

#define LCD_CLEAR LCD_voidWriteCommand(0x01) // Macro for Clearin the LCD

extern void LCD_voidInit();
extern void LCD_voidWriteChar(u8 Value);
extern void LCD_voidWriteCommand(u8 Value);
extern void LCD_voidWriteString(u8 *arry);
extern void LCD_voidWriteNumber(u8 Value);



#endif /* LCD_H_ */


#endif /* LCD_H_ */
