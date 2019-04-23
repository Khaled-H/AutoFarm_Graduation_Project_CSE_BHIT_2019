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
#include "DIO.h"
#include "LCD.h"

//**** Register Select (RS) Pin Conditions *****
#define DATA 1
#define COMMAND 0

//**** Read-Write (R/W) Pin Conditions *****
#define WRITE 0
#define READ 1

void _delay_ms(u8 DelayTime){
	for (int i=0;i<=DelayTime;i++);
}

extern void HAL_LCD_Init(void)
{

_delay_ms(40);
HAL_LCD_WriteCommand(0b00111000);
_delay_ms(1);
HAL_LCD_WriteCommand(0b00001100);
_delay_ms(1);
HAL_LCD_WriteCommand(0x01);
_delay_ms(2);

}
//************************************************
extern void HAL_LCD_WriteChar(u8 Value)
{
MCAL_DIO_WritePort(HAL_LCD_DATA_PORT,Value);
MCAL_DIO_WritePin(HAL_LCD_CONTROL_PORT,HAL_LCD_RS_PIN,DATA);
MCAL_DIO_WritePin(HAL_LCD_CONTROL_PORT,HAL_LCD_RW_PIN,WRITE);
MCAL_DIO_WritePin(HAL_LCD_CONTROL_PORT,HAL_LCD_EN_PIN,BITHIGH);
_delay_ms(1);
MCAL_DIO_WritePin(HAL_LCD_CONTROL_PORT,HAL_LCD_EN_PIN,BITLOW);
}
//************************************************
extern void LCD_voidWriteCommand(u8 Value)
{
	MCAL_DIO_WritePort(HAL_LCD_DATA_PORT,Value);
	MCAL_DIO_WritePin(HAL_LCD_CONTROL_PORT,HAL_LCD_RS_PIN,COMMAND);
	MCAL_DIO_WritePin(HAL_LCD_CONTROL_PORT,HAL_LCD_RW_PIN,WRITE);
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
//*****************************************************
/*extern void LCD_voidSetPosition(u8 rows , u8 columns)
{

}*/
//*****************************************************
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
