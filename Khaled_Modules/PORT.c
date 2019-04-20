/*
 * PORT.c
 *
 *  Created on: Apr 19, 2019
 *      Author: Khaled
 */

#include "PORT.h"

extern void MCAL_PORT_Init()
{

/***   PORTA CONFIGURATION   ***/

DIO_PORTA.DIO_CRL = 0X0000EEE0;
DIO_PORTA.DIO_CRH = 0X80082222;

/***   PORTB CONFIGURATION   ***/
DIO_PORTB.DIO_CRL = 0X8A888000;
DIO_PORTB.DIO_CRH = 0X22220000;

}


