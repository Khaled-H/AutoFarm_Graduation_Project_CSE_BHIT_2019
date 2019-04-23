/*
 * DIO.c
 *
 *  Created on: Apr 19, 2019
 *      Author: Khaled
 */

#include "DIO.h"

/****************    write a word to a given port    ****************/

extern void MCAL_DIO_WritePort(MCAL_DIO_tPortNum PortNumber,u32 Value)
{
switch (PortNumber)
{
	case PORTA :
	DIO_PORTA.DIO_ODR = Value;
	break;
	case PORTB :
	DIO_PORTB.DIO_ODR = Value;
	break;
	case PORTC :
	DIO_PORTC.DIO_ODR = Value;
	break;
}
}

/****************     set/reset pin of a given  port   *****************/

extern void MCAL_DIO_WritePin(MCAL_DIO_tPortNum PortNumber,u8 Value , u8 PinNumber)
{
switch (PortNumber)
{
/******************  set or reset pins of PORTA     ***************/
	case PORTA :
	if (Value)
	{
		DIO_PORTA.DIO_BSRR |= (1<<PinNumber);
	}
	else
	{
		DIO_PORTA.DIO_BSRR |= (1<<(PinNumber+16));
	}
	break;
/***************   set or reset pins of PORTB    *********************/
	case PORTB :
	if (Value)
	{
		DIO_PORTB.DIO_BSRR |= (1<<PinNumber);
	}
	else
	{
		DIO_PORTB.DIO_BSRR |= (1<<(PinNumber+16));
	}
	break;
/***************** set or reset pins of PORTC    *******************/
	case PORTC :
	if (Value)
	{
		DIO_PORTC.DIO_BSRR |= (1<<PinNumber);
	}
	else
	{
		DIO_PORTC.DIO_BSRR |= (1<<(PinNumber+16));
	}
	break;
}
}

/*********************     read a word from a given port    ********************/

extern MCAL_DIO_tPortWidth MCAL_DIO_ReadPort(MCAL_DIO_tPortNum PortNumber)
{
MCAL_DIO_tPortWidth Input_Value = 0;
	switch (PortNumber)
	{
		case PORTA :
		Input_Value = DIO_PORTA.DIO_IDR;
		break;
		case PORTB :
		Input_Value = DIO_PORTB.DIO_IDR;
		break;
		case PORTC :
		Input_Value = DIO_PORTC.DIO_IDR;
		break;

	}
	return Input_Value;
}

/*********************     read a pin from a given port      *************************/

extern STD_tLogic MCAL_DIO_ReadPin(MCAL_DIO_tPortNum PortNumber ,u8 PinNumber)
{
STD_tLogic InputPin = 0;
switch (PortNumber)
{
	case PORTA :
	InputPin = (DIO_PORTA.DIO_IDR & (1 << PinNumber))>> PinNumber;
	break;
	case PORTB :
	InputPin = (DIO_PORTB.DIO_IDR & (1 << PinNumber));
	InputPin = (InputPin >> PinNumber);
	break;
	case PORTC :
	InputPin = (DIO_PORTC.DIO_IDR & (1<< PinNumber));
	InputPin = (InputPin >> PinNumber);
	break;
}
return InputPin;
}
/*********************     Toggle a Full DIO Port    ********************/
extern void                MCAL_DIO_TogglePort(MCAL_DIO_tPortNum PortNumber){
  MCAL_DIO_tPortWidth ones = ~((MCAL_DIO_tPortWidth)0);
  switch (PortNumber)
  {
      case PORTA :
      DIO_PORTA.DIO_ODR ^=  ones ;
      break;
      case PORTB :
      DIO_PORTB.DIO_ODR ^=  ones ;
      break;
      case PORTC :
      DIO_PORTC.DIO_ODR ^=  ones ;
      break;
  }
}


/*********************     Toggle a Pin from a Port    ********************/
extern void                MCAL_DIO_TogglePin (MCAL_DIO_tPortNum PortNumber, u8 PinNumber){
  switch (PortNumber)
    {
        case PORTA :
        DIO_PORTA.DIO_ODR ^= (MCAL_DIO_tPortWidth)(1<<PinNumber);
        break;
        case PORTB :
        DIO_PORTB.DIO_ODR ^=  (MCAL_DIO_tPortWidth)(1<<PinNumber);
        break;
        case PORTC :
        DIO_PORTC.DIO_ODR ^=  (MCAL_DIO_tPortWidth)(1<<PinNumber);
        break;
    }
}




