/*
 * LCD.c
 *
 *  Created on: Apr 20, 2019
 *      Author: Mostafa Samir Nawar		Mostafa.nwar@yahoo.com
 */


/*
 * LCD.c
 *
 *  Created on: Nov 3, 2017
 *      Author: Mostafa
 */
#include "LCD.h"

//**** Register Select (RS) Pin Conditions *****
#define DATA 1
#define COMMAND 0

//**** Read-Write (R/W) Pin Conditions *****
#define WRITE 0
#define READ 1

void _delay_ms(u8 DelayTime){
	for (int i=0;i<=DelayTime;i++){
	   for (int j=0;j<=7500;i++);
	}
}

extern void HAL_LCD_Init(void)
{
_delay_ms(30);
HAL_LCD_WriteCommand(0x38);
_delay_ms(1);
HAL_LCD_WriteCommand(0x0E);
_delay_ms(1);
HAL_LCD_WriteCommand(0x01);
_delay_ms(2);
HAL_LCD_WriteCommand(0x06); /*entry mode set*/

}
//************************************************
extern void HAL_LCD_WriteChar(u8 Value)
{
MCAL_DIO_WritePort(HAL_LCD_DATA_PORT,Value);
MCAL_DIO_WritePin(HAL_LCD_CONTROL_PORT,HAL_LCD_RS_PIN,DATA);
MCAL_DIO_WritePin(HAL_LCD_CONTROL_PORT,HAL_LCD_EN_PIN,BITHIGH);
_delay_ms(1);
MCAL_DIO_WritePin(HAL_LCD_CONTROL_PORT,HAL_LCD_EN_PIN,BITLOW);
}
//************************************************
extern void HAL_LCD_WriteCommand(u8 Value)
{
	MCAL_DIO_WritePort(HAL_LCD_DATA_PORT,Value);
	MCAL_DIO_WritePin(HAL_LCD_CONTROL_PORT,HAL_LCD_RS_PIN,COMMAND);
	MCAL_DIO_WritePin(HAL_LCD_CONTROL_PORT,HAL_LCD_EN_PIN,BITHIGH);
    _delay_ms(1);
    MCAL_DIO_WritePin(HAL_LCD_CONTROL_PORT,HAL_LCD_EN_PIN,BITLOW);

}
//**************************************************
/* Function for Writing A String of ASCIIs Chars on the LCD */
extern void HAL_LCD_WriteString(u8 *arry)
{
    u8 i =0 ;
    while((arry[i])!= '\0') // loop the String until find the Null Value
    {
    	HAL_LCD_WriteChar(arry[i]);
        i++;
    }
}

extern void HAL_LCD_WriteNumber(u8 Value)
{
    //      Function for Writing an Integer on the LCD, Converting from Integer
    //      Value to it's ASCII Value

    u8 temp = Value%100 ;
    Value = Value /100;
    HAL_LCD_WriteChar(Value+48);
    //Value = Value*10;
    HAL_LCD_WriteChar((temp/10)+48);
    HAL_LCD_WriteChar((temp%10)+48);
}
extern void HAL_LCD_SetCursor(u8 RowNumber,HAL_LCD_TColom ColomNumber){
     	if(RowNumber==1){
		switch (ColomNumber) {
		case C01:
			HAL_LCD_WriteCommand(0x80);
			break;
		case C02:
			HAL_LCD_WriteCommand(0x81);
			break;
		case C03:
			HAL_LCD_WriteCommand(0x82);
			break;
		case C04:
			HAL_LCD_WriteCommand(0x83);
			break;
		case C05:
			HAL_LCD_WriteCommand(0x84);
			break;
		case C06:
			HAL_LCD_WriteCommand(0x85);
			break;
		case C07:
			HAL_LCD_WriteCommand(0x86);
			break;
		case C08:
			HAL_LCD_WriteCommand(0x87);
			break;
		case C09:
			HAL_LCD_WriteCommand(0x88);
			break;
		case C10:
			HAL_LCD_WriteCommand(0x89);
			break;
		case C11:
			HAL_LCD_WriteCommand(0x8A);
			break;
		case C12:
			HAL_LCD_WriteCommand(0x8B);
			break;
		case C13:
			HAL_LCD_WriteCommand(0x8C);
			break;
		case C14:
			HAL_LCD_WriteCommand(0x8D);
			break;
		case C15:
			HAL_LCD_WriteCommand(0x8E);
			break;
		case C16:
			HAL_LCD_WriteCommand(0x8F);
			break;
		}
     	}
     	else {
			switch (ColomNumber)
			{
			case C01:
				HAL_LCD_WriteCommand(0xC0);
				break;
			case C02:
				HAL_LCD_WriteCommand(0xC1);
				break;
			case C03:
				HAL_LCD_WriteCommand(0xC2);
				break;
			case C04:
				HAL_LCD_WriteCommand(0xC3);
				break;
			case C05:
				HAL_LCD_WriteCommand(0xC4);
				break;
			case C06:
				HAL_LCD_WriteCommand(0xC5);
				break;
			case C07:
				HAL_LCD_WriteCommand(0xC6);
				break;
			case C08:
				HAL_LCD_WriteCommand(0xC7);
				break;
			case C09:
				HAL_LCD_WriteCommand(0xC8);
				break;
			case C10:
				HAL_LCD_WriteCommand(0xC9);
				break;
			case C11:
				HAL_LCD_WriteCommand(0xCA);
				break;
			case C12:
				HAL_LCD_WriteCommand(0xCB);
				break;
			case C13:
				HAL_LCD_WriteCommand(0xCC);
				break;
			case C14:
				HAL_LCD_WriteCommand(0xCD);
				break;
			case C15:
				HAL_LCD_WriteCommand(0xCE);
				break;
			case C16:
				HAL_LCD_WriteCommand(0xCF);
				break;
			}
		}

	}
