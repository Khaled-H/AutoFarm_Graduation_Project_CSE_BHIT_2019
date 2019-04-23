/*
 * RCC.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: manar
 */

#include "RCC.h"
void MCAL_RCC_Init(void)
{

	/** used HSE 8MHZ without PLL*/
	/*HSE ON and select bypath*/
	/*MCO: Microcontroller clock output HSE clock selected*/
	/*SWS system clock switch*/
	/*SW systetm clock switch**/
	RCC.CR.REG_FULL_32=(u32)0x00028000;
	RCC.CFGR.REG_FULL_32=(32)0x06000005;

}
extern  void MCAL_RCC_PortEnable(u8 PortNumber){
	switch (PortNumber)
	{
		case PORTA :
		MCAL_RCC_Init();
		RCC.APB2ENR.Bit02=1;
		break;
		case PORTB :
		MCAL_RCC_Init();
		RCC.APB2ENR.Bit03=1;
		break;
		case PORTC :
		MCAL_RCC_Init();
		RCC.APB2ENR.Bit04=1;
		break;
	}
}
extern  void MCAL_RCC_Uart1Enable(void){
	MCAL_RCC_Init();
	RCC.APB1ENR.Bit14=1;
	RCC.APB1ENR.Bit00=1; //AFIO
}


