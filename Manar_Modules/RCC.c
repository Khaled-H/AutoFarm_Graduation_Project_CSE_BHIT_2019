/*
 * RCC.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: manar
 */

#include "RCC.h"
typedef struct {
	HWREG32 CR;
	HWREG32 CFGR;
	HWREG32 CIR;
	HWREG32 APB2RSTR;
	HWREG32 APB1RTSR;
	HWREG32 AHBENR;
	HWREG32 APB2ENR;
	HWREG32 APB1ENR;
	HWREG32 BDCR;
	HWREG32 CSR;
}RCC_typedef;
#define RCC   (*(( volatile RCC_typedef* const )(0x40021000)))

void MCAL_RCC_SystemInit(void)
{

	/** used HSE 8MHZ without PLL**/
	/*HSE ON and select byBath*/
	/*MCO: Micro_controller clock output HSE clock selected*/
	/*SWS system clock switch*/
	/*SW system clock switch**/
	RCC.CR.REG_FULL_32=(u32)0x00050000;
	RCC.CFGR.REG_FULL_32=(u32)0x06000001; /*sw bit only in CFGR  not */
	RCC.APB2ENR.REG_FULL_32=(u32)0x0000C61D;
}


