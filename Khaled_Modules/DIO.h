/*
 * DIO.h
 *
 *  Created on: Apr 19, 2019
 *      Author: Khaled
 */

#ifndef DIO_H_
#define DIO_H_

#include "STD_TYPES.h"
/*********************************************************************************
                             user defined data types
**********************************************************************************/
/***************************     	input data types  	 ************************/

typedef u16 MCAL_DIO_tPortWidth;
typedef u16  MCAL_DIO_tReadpin	;

/*****************************   DIO Data Types      ****************/
typedef struct{
	u32 DIO_CRL;
	u32 DIO_CRH;
	u32 DIO_IDR;
	u32 DIO_ODR;
	u32 DIO_BSRR;
	u32 DIO_BRR;
	u32 DIO_LCKR;
}DIO_Type;

/*******************    Declaration Of Port Number VS Name    *********************/
typedef enum
{
PORTA =1,
PORTB =2,
PORTC =3
}DIO_Port_Number;

/***************************************************************************************
                             DIO Registers Base/Offset Addresses
***************************************************************************************/
/**************************** DIO Port  Register Base Addresses **********************/
#define  DIO_PORTA (*((volatile DIO_Type*const)(0x40010800)))
#define  DIO_PORTB (*((volatile DIO_Type*const)(0x40010C00)))
#define  DIO_PORTC (*((volatile DIO_Type*const)(0x40011000)))

#define PIN_HIGH  (1)
#define PIN_LOW   (0)
/*************************     DIO Module Functions Prototypes   *******************/


extern void                MCAL_DIO_WritePort(DIO_Port_Number PortNumber,u32 Value);
extern void                MCAL_DIO_WritePin (DIO_Port_Number PortNumber, u8 PinNumber,u8 Value );
extern MCAL_DIO_tPortWidth MCAL_DIO_ReadPort (DIO_Port_Number PortNumber);
extern STD_tLogic          MCAL_DIO_ReadPin  (DIO_Port_Number PortNumber ,u8 PinNumber);




#endif /* DIO_H_ */
