/*
 * STD_TYPES.h
 *
 *  Created on: Apr 19, 2019
 *      Author: Mostafa Samir Nawar		Mostafa.nwar@yahoo.com
 */

#ifndef STD_TYPES_H_
#define STD_TYPES_H_

#define NULL    ((void  * )0)
#define BITHIGH     (1)
#define BITLOW      (0)

#define STD_FLAG_HIGH   (1)
#define STD_FLAG_LOW    (0)


#define STD_LOW     (0)
#define STD_HIGH    (1)

#define BYTEHIGH    (0xffff)
#define BYTELOW     (0)

typedef unsigned char u8 ;
typedef unsigned short int u16 ;
typedef unsigned long int u32 ;

typedef signed char s8;
typedef signed short int s16;
typedef signed long long int s32;

typedef float f32;
typedef double f64;

typedef u8 STD_tLogic;
/* Define a 32-Bit HW Register General Type */
typedef union {
    u32 REG_FULL_32 ;
    struct {
    u32 Bit00:1,Bit01:1,Bit02:1,Bit03:1,Bit04:1,Bit05:1,Bit06:1,Bit07:1,
        Bit08:1,Bit09:1,Bit10:1,Bit11:1,Bit12:1,Bit13:1,Bit14:1,Bit15:1,
        Bit16:1,Bit17:1,Bit18:1,Bit19:1,Bit20:1,Bit21:1,Bit22:1,Bit23:1,
        Bit24:1,Bit25:1,Bit26:1,Bit27:1,Bit28:1,Bit29:1,Bit30:1,Bit31:1;
    };
}HWREG32;
typedef union {
    u32 REG_FULL_16 ;
    struct {
    u32 Bit00:1,Bit01:1,Bit02:1,Bit03:1,Bit04:1,Bit05:1,Bit06:1,Bit07:1,
        Bit08:1,Bit09:1,Bit10:1,Bit11:1,Bit12:1,Bit13:1,Bit14:1,Bit15:1;
    };
}HWREG16;



#endif /* STD_TYPES_H_ */
