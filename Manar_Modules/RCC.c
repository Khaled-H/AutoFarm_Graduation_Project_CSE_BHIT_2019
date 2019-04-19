/*
 * RCC.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: manar
 */
#include"RCC.h"
void MCAL_RCC_RCCInit(void)
{
	//** used HSE 8MHZ without PLL **//
	//HSE ON and select bypath
	RCC.CR.REG_FULL_32=(u32)0x00028000;
	//MCO: Microcontroller clock output HSE clock selected//
	//SWS system clock switch//
	//SW systetm clock switch
	RCC.CFGR.REG_FULL_32=(32)0x06000005;

}
