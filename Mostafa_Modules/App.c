/*
 * App.c
 *
 *  Created on: Apr 24, 2019
 *      Author: Mostafa Samir Nawar		Mostafa.nwar@yahoo.com
 */

#include "App.h"


typedef enum {
  NORMAL,
  CONFIG,
  OTP
}APP_tSystemModes;
static APP_tSystemModes APP_SystemMode ;
extern void APP_SystemInit(){
  MCAL_RCC_SystemInit();
  MCAL_PORT_Init();
  APP_SENSORREADER_Init();
  APP_PROCESS_Init();
  APP_DISPLAY_INIT();
  APP_IOT_Init();
  /******       System Specific Tasks       **********/
  HAL_LEDS_NormalModeLed_ON();
  APP_SystemMode = NORMAL ;

}

/*1 Sec Period Task, To show System state Indicator*/
extern void APP_SystemIdicatorTask(){
if (APP_SystemMode == NORMAL ){
HAL_LEDS_NormalModeLed_Toggle();
}
else {
  /*Do nothing*/
}
}
/*15 Sec Period Task Called by OS */
extern void APP_SystemTask(){
  /*Read Sensor Values*/
  APP_SENSORREADER_TaskLvlsUpdate();
  /*Control Motors*/
  APP_PROCESS_Process();
  /*update display */
  APP_DISPLAY_Task();
  /*Send Data to cloud*/
  APPL_IOT_SendPacket();
}
