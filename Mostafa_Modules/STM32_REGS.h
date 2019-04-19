/*
 * STM32_REGS.h
 *
 *  Created on: Apr 19, 2019
 *      Author: Mostafa Samir Nawar		Mostafa.nwar@yahoo.com
 */

#ifndef STM32_REGS_H_
#define STM32_REGS_H_
#include "STD_TYPES.h"
/**********     GPIO Peripheral Registers ***************/
typedef struct {
    HWREG32 CRL ;   // Control Low (Configuration Register)
    HWREG32 CRH ;   // Control High (Configuration Register)
    HWREG32 IDR ;   //Input Data Register
    HWREG32 ODR ;   // Output Data Register
    HWREG32 BSR ;   // Bit Set Register, Write 1 to the index of the pin to Set output to 1
    HWREG32 BRR ;   // Bit Reset Register, Write 1 to the index of the pin to Reset output to 0
    HWREG32 LCKR ;  // Lock Bit Register to disable the Bit Configuration Changes
}GPIO_typedef;
#define GPIOA (*((volatile GPIO_typedef*const )(0x40010800)))
#define GPIOB (*((volatile GPIO_typedef*const )(0x40010C00)))
#define GPIOC (*((volatile GPIO_typedef*const )(0x40011000)))
/***********************************************************/
/**********     RCC Peripheral Registers ***************/
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
#define RCC   (*((volatile RCC_typedef*const )(0x40021000)))
/******************************************************************************************************/
/******************************************************************************************************/
/********************************** Private Peripheral Registers    ***********************************/
/**********     SysTick Private Peripheral Registers ***************/
typedef struct {
    HWREG32 CTRL ;
    HWREG32 LOAD ;
    HWREG32 VAL  ;
    HWREG32 CALIB;
}SYSTICK_typedef;
#define SYSTICK     (*((volatile SYSTICK_typedef * const )(0xE000E010)))


#endif /* STM32_REGS_H_ */
