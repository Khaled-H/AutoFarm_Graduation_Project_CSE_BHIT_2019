/*
 * RCC.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: manar
 */

#ifndef RCC_H_
#define RCC_H_
#include "STD_TYPES.h"
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
void MCAL_RCC_RCCInit(void);
#endif /* RCC_H_ */
