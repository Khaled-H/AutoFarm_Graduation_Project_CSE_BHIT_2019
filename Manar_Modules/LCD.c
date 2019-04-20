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
#include <util/delay.h>

//**** Register Select (RS) Pin Conditions *****
#define DATA 1
#define COMMAND 0

//**** Read-Write (R/W) Pin Conditions *****
#define WRITE 0
#define READ 1



extern void LCD_voidInit(void)
{
DIO_voidSetPortDirection(LCD_DataPort,PORTOUT);
DIO_voidSetPinDirection(LCD_ControlPort,LCD_EnablePin,PINOUT);
DIO_voidSetPinDirection(LCD_ControlPort,LCD_ReadWritePin,PINOUT);
DIO_voidSetPinDirection(LCD_ControlPort,LCD_RegSelectPin,PINOUT);

_delay_ms(40);
LCD_voidWriteCommand(0b00111000);
_delay_ms(1);
LCD_voidWriteCommand(0b00001100);
_delay_ms(1);
LCD_voidWriteCommand(0x01);
_delay_ms(2);

}
//************************************************
extern void LCD_voidWriteChar(u8 Value)
{
DIO_voidWritePort(LCD_DataPort,Value);
DIO_voidWritePin(LCD_ControlPort,LCD_RegSelectPin,DATA);
DIO_voidWritePin(LCD_ControlPort,LCD_ReadWritePin,WRITE);
DIO_voidWritePin(LCD_ControlPort,LCD_EnablePin,BITHIGH);
_delay_ms(1);
DIO_voidWritePin(LCD_ControlPort,LCD_EnablePin,BITLOW);
}
//************************************************
extern void LCD_voidWriteCommand(u8 Value)
{
    DIO_voidWritePort(LCD_DataPort,Value);
    DIO_voidWritePin(LCD_ControlPort,LCD_RegSelectPin,COMMAND);
    DIO_voidWritePin(LCD_ControlPort,LCD_ReadWritePin,WRITE);
    DIO_voidWritePin(LCD_ControlPort,LCD_EnablePin,BITHIGH);
    _delay_ms(1);
    DIO_voidWritePin(LCD_ControlPort,LCD_EnablePin,BITLOW);

}
//**************************************************
/* Function for Writing A String of ASCIIs Chars on the LCD */
extern void LCD_voidWriteString(u8 *arry)
{
    u8 i =0 ;
    while((arry[i])!= '\0') // loop the String until find the Null Value
    {
        LCD_voidWriteChar(arry[i]);
        i++;
    }
}
//*****************************************************
/*extern void LCD_voidSetPosition(u8 rows , u8 columns)
{

}*/
//*****************************************************
extern void LCD_voidWriteNumber(u8 Value)
{
    //      Function for Writing an Integer on the LCD, Converting from Integer
    //      Value to it's ASCII Value

    u8 temp = Value%100 ;
    Value = Value /100;
    LCD_voidWriteChar(Value+48);
    //Value = Value*10;
    LCD_voidWriteChar((temp/10)+48);
    LCD_voidWriteChar((temp%10)+48);
}
