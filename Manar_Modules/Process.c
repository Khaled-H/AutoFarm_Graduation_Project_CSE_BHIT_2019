/*
 * Process.c
 *
 *  Created on: Apr 10, 2019
 *      Author: Mostafa Samir Nawar		Mostafa.nwar@yahoo.com
 */


#include "PROCESS.h"

/*
  tM1_State PROC_M1_State(void){
  return M1_State ;
}

void PROC_M1_ON(void){
    DIO_Pin_Write(MOTOR1_Port, M1_Pin, STD_High);
  M1_State = M_ON ;
}
void PROC_M1_OFF(void){
  DIO_Pin_Write(MOTOR1_Port, M1_Pin, STD_Low);
  M1_State = M_OFF ;
}
**/
void APP_PROCESS_Init(void)
{
	HAL_FAN_FanInit();
}
APP_PROCESS_Process(void){
    if(APP_SENSORS_GetTempLvl()==35)
      {
        HAL_FAN_FanOn(u8 FanNumber);
       }
      else
      {
    	HAL_FAN_FanOff(u8 FanNumber);
      }


    }
