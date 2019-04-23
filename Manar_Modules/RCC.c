/*
 * RCC.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: manar
 */

#include "RCC.h"
void MCAL_RCC_SystemInit(void)
{

	/** used HSE 8MHZ without PLL*/
	/*HSE ON and select byBath*/
	/*MCO: Micro_controller clock output HSE clock selected*/
	/*SWS system clock switch*/
	/*SW system clock switch**/
	RCC.CR.REG_FULL_32=(u32)0x00028000;
	RCC.CFGR.REG_FULL_32=(u32)0x06000005;

}
extern  void MCAL_RCC_PrepheralEnable(RCC_TPrepheral_Number PortNumber)
{
	switch (PortNumber)
	{
	case MCAL_RCC_PORTA :
		MCAL_RCC_Init();
		RCC.APB2ENR.Bit02=1;
		break;
	case MCAL_RCC_PORTB :
		MCAL_RCC_Init();
		RCC.APB2ENR.Bit03=1;
		break;
	case MCAL_RCC_PORTC:
		MCAL_RCC_Init();
		RCC.APB2ENR.Bit04=1;
		break;
	case MCSL_RCC_USART1:
		MCAL_RCC_Init();
		RCC.APB1ENR.Bit14=1;
		RCC.APB1ENR.Bit00=1; //AFIO
		break;
	case MCAL_RCC_ADC1:
		MCAL_RCC_Init();
		RCC.APB1ENR.Bit09=1;
		RCC.APB1ENR.Bit00=1;
        break;
	case MCAL_RCC_ADC2:
			MCAL_RCC_Init();
			RCC.APB1ENR.Bit10=1;
			RCC.APB1ENR.Bit00=1;
	        break;
	case MCAL_RCC_ADC3:
			MCAL_RCC_Init();
			RCC.APB1ENR.Bit15=1;
			RCC.APB1ENR.Bit00=1;
	        break;
	}
}


