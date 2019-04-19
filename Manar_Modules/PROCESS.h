/*
 * PROCESS.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: manar
 */

#ifndef INCLUDE_PROCESS_H_
#define INCLUDE_PROCESS_H_
#include "FAN(1).h"


/*
 *
typedef enum{
  M_ON=1,
  M_OFF=0
}tM1_State;

tM1_State M1_State;
tM1_State PROC_M1_State(void);
void PROC_M1_ON(void);
void PROC_M1_OFF(void);
*/
void APP_PROCESS_Init(void);
void APP_PROCESS_Process(void);



#endif /* INCLUDE_PROCESS_H_ */

