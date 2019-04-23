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
}MCAL_DIO_tPortType;

/*******************    Declaration Of Port Number VS Name    *********************/
typedef enum
{
PORTA =1,
PORTB =2,
PORTC =3
}MCAL_DIO_tPortNum;

/***************************************************************************************
                             DIO Registers Base/Offset Addresses
***************************************************************************************/
/**************************** DIO Port  Register Base Addresses **********************/
#define  DIO_PORTA (*((volatile MCAL_DIO_tPortType*const)(0x40010800)))
#define  DIO_PORTB (*((volatile MCAL_DIO_tPortType*const)(0x40010C00)))
#define  DIO_PORTC (*((volatile MCAL_DIO_tPortType*const)(0x40011000)))


/*************************     DIO Module Functions Prototypes   *******************/


extern void                MCAL_DIO_WritePort(MCAL_DIO_tPortNum PortNumber,u32 Value);
extern void                MCAL_DIO_WritePin (MCAL_DIO_tPortNum PortNumber, u8 PinNumber,u8 Value );
extern MCAL_DIO_tPortWidth MCAL_DIO_ReadPort (MCAL_DIO_tPortNum PortNumber);
extern STD_tLogic          MCAL_DIO_ReadPin  (MCAL_DIO_tPortNum PortNumber ,u8 PinNumber);
extern void                MCAL_DIO_TogglePort(MCAL_DIO_tPortNum PortNumber);
extern void                MCAL_DIO_TogglePin (MCAL_DIO_tPortNum PortNumber, u8 PinNumber);




#endif /* DIO_H_ */
