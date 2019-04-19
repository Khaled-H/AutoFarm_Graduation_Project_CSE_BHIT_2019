/*
 * DIO_TEST_UNIT.c
 *
 *  Created on: Apr 19, 2019
 *      Author: Khaled
 */

#include "DIO.h"
#define RCC_PORTC_EN (*((volatile u32 * const)(0x40021018)))
int main()
{
DIO_PORTC.DIO_CRH = 0x300000;
RCC_PORTC_EN = 0x16;

while (1)
	{
	MCAL_DIO_WritePin (3,1,13);
	for(int i =0; i<5000000; i++);
	MCAL_DIO_WritePin (3,0,13);
	for(int i =0; i<5000000; i++);
	}
return 0;
}



