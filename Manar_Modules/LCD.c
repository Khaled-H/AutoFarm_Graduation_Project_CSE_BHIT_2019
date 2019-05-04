/*
 * LCD.c
 *
 *  Created on: Apr 20, 2019
 *      Author: Mostafa Samir Nawar		Mostafa.nwar@yahoo.com
 */


#include "LCD.h"
#include "PORT.h"

//**** Register Select (RS) Pin Conditions *****
#define DATA (1)
#define COMMAND (0)

//**** Read-Write (R/W) Pin Conditions *****
#define WRITE (0)
#define READ (1)

static void _delay_ms(u8 DelayTime){
	for (int i=0;i<DelayTime;i++){
		for (int j=0; j <= 4000; j++);
	}
}

extern void HAL_LCD_Init(void)
{
_delay_ms(40);
HAL_LCD_WriteCommand(0x33);
_delay_ms(5);
HAL_LCD_WriteCommand(0x32);
_delay_ms(5);
HAL_LCD_WriteCommand(0x28);         // LCD initialization as 4bit mode
_delay_ms(2);
HAL_LCD_WriteCommand(0x0E);
_delay_ms(2);
HAL_LCD_WriteCommand(0x01);
_delay_ms(2);
HAL_LCD_WriteCommand(0x06); /*entry mode set*/

}
//************************************************
extern void HAL_LCD_WriteChar(u8 Value)
{

/**************   send the higher 4 bits ***/

LCD_4BITMODE_DATA_OUT((u32)((Value >> 4) & 0x0F));
MCAL_DIO_WritePin(HAL_LCD_CONTROL_PORT,HAL_LCD_RS_PIN,DATA);
MCAL_DIO_WritePin(HAL_LCD_CONTROL_PORT,HAL_LCD_EN_PIN,STD_HIGH);
_delay_ms(1);
MCAL_DIO_WritePin(HAL_LCD_CONTROL_PORT,HAL_LCD_EN_PIN,STD_LOW);

/**************   send the lower 4 bits ***/

LCD_4BITMODE_DATA_OUT((u32)(Value & 0x0F));
MCAL_DIO_WritePin(HAL_LCD_CONTROL_PORT,HAL_LCD_RS_PIN,DATA);
MCAL_DIO_WritePin(HAL_LCD_CONTROL_PORT,HAL_LCD_EN_PIN,BITHIGH);
_delay_ms(1);
MCAL_DIO_WritePin(HAL_LCD_CONTROL_PORT,HAL_LCD_EN_PIN,BITLOW);

}
//************************************************
static void HAL_LCD_WriteCommand(u8 Value)
{

    /**************   send the higher 4 bits LCD command  ***/

    LCD_4BITMODE_DATA_OUT((u32)((Value >> 4) & 0x0F));
    MCAL_DIO_WritePin(HAL_LCD_CONTROL_PORT,HAL_LCD_RS_PIN,COMMAND);
    MCAL_DIO_WritePin(HAL_LCD_CONTROL_PORT,HAL_LCD_EN_PIN,BITHIGH);
    _delay_ms(1);
    MCAL_DIO_WritePin(HAL_LCD_CONTROL_PORT,HAL_LCD_EN_PIN,BITLOW);

    /**************   send the lower 4 bits LCD command  ***/

    LCD_4BITMODE_DATA_OUT((u32)(Value & 0x0F));
    MCAL_DIO_WritePin(HAL_LCD_CONTROL_PORT,HAL_LCD_RS_PIN,COMMAND);
    MCAL_DIO_WritePin(HAL_LCD_CONTROL_PORT,HAL_LCD_EN_PIN,BITHIGH);
    _delay_ms(1);
    MCAL_DIO_WritePin(HAL_LCD_CONTROL_PORT,HAL_LCD_EN_PIN,BITLOW);

}
//**************************************************
/* Function for Writing A String of ASCIIs Chars on the LCD */
extern void HAL_LCD_WriteString(u8 *arry)
{
    u8 i = 0 ;
    while((arry[i])!= '\0') // loop the String until find the Null Value
    {
    	HAL_LCD_WriteChar(arry[i]);
        i++;
       for (int j=0; j <= 4000; j++);
    }
}

extern void HAL_LCD_WriteNumber(u32 Value)
{
    //      Function for Writing an Integer on the LCD, Converting from Integer
    //      Value to it's ASCII Value

   u32 temp = Value%100 ;
    Value = Value /100;
    HAL_LCD_WriteChar(Value+48);
    //Value = Value*10;
    HAL_LCD_WriteChar((temp/10)+48);
    HAL_LCD_WriteChar((temp%10)+48);
}

extern void HAL_LCD_SetCursor(u8 RowNumber,u8 ColomNumber){
     	if(RowNumber==1){
		switch (ColomNumber) {
		case HAL_LCD_COLUMN1:
			HAL_LCD_WriteCommand(0x80);
			break;
		case HAL_LCD_COLUMN2:
			HAL_LCD_WriteCommand(0x81);
			break;
		case HAL_LCD_COLUMN3:
			HAL_LCD_WriteCommand(0x82);
			break;
		case HAL_LCD_COLUMN4:
			HAL_LCD_WriteCommand(0x83);
			break;
		case HAL_LCD_COLUMN5:
			HAL_LCD_WriteCommand(0x84);
			break;
		case HAL_LCD_COLUMN6:
			HAL_LCD_WriteCommand(0x85);
			break;
		case HAL_LCD_COLUMN7:
			HAL_LCD_WriteCommand(0x86);
			break;
		case HAL_LCD_COLUMN8:
			HAL_LCD_WriteCommand(0x87);
			break;
		case HAL_LCD_COLUMN9:
			HAL_LCD_WriteCommand(0x88);
			break;
		case HAL_LCD_COLUMN10:
			HAL_LCD_WriteCommand(0x89);
			break;
		case HAL_LCD_COLUMN11:
			HAL_LCD_WriteCommand(0x8A);
			break;
		case HAL_LCD_COLUMN12:
			HAL_LCD_WriteCommand(0x8B);
			break;
		case HAL_LCD_COLUMN13:
			HAL_LCD_WriteCommand(0x8C);
			break;
		case HAL_LCD_COLUMN14:
			HAL_LCD_WriteCommand(0x8D);
			break;
		case HAL_LCD_COLUMN15:
			HAL_LCD_WriteCommand(0x8E);
			break;
		case HAL_LCD_COLUMN16:
			HAL_LCD_WriteCommand(0x8F);
			break;
		}
     	}
     	else {
			switch (ColomNumber)
			{
			case HAL_LCD_COLUMN1:
				HAL_LCD_WriteCommand(0xC0);
				break;
			case HAL_LCD_COLUMN2:
				HAL_LCD_WriteCommand(0xC1);
				break;
			case HAL_LCD_COLUMN3:
				HAL_LCD_WriteCommand(0xC2);
				break;
			case HAL_LCD_COLUMN4:
				HAL_LCD_WriteCommand(0xC3);
				break;
			case HAL_LCD_COLUMN5:
				HAL_LCD_WriteCommand(0xC4);
				break;
			case HAL_LCD_COLUMN6:
				HAL_LCD_WriteCommand(0xC5);
				break;
			case HAL_LCD_COLUMN7:
				HAL_LCD_WriteCommand(0xC6);
				break;
			case HAL_LCD_COLUMN8:
				HAL_LCD_WriteCommand(0xC7);
				break;
			case HAL_LCD_COLUMN9:
				HAL_LCD_WriteCommand(0xC8);
				break;
			case HAL_LCD_COLUMN10:
				HAL_LCD_WriteCommand(0xC9);
				break;
			case HAL_LCD_COLUMN11:
				HAL_LCD_WriteCommand(0xCA);
				break;
			case HAL_LCD_COLUMN12:
				HAL_LCD_WriteCommand(0xCB);
				break;
			case HAL_LCD_COLUMN13:
				HAL_LCD_WriteCommand(0xCC);
				break;
			case HAL_LCD_COLUMN14:
				HAL_LCD_WriteCommand(0xCD);
				break;
			case HAL_LCD_COLUMN15:
				HAL_LCD_WriteCommand(0xCE);
				break;
			case HAL_LCD_COLUMN16:
				HAL_LCD_WriteCommand(0xCF);
				break;
			}
		}
     	for (int j=0; j <= 4000; j++);
	}
