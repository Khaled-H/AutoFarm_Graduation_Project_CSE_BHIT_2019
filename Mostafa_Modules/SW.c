/*
 * SW.c
 *
 *  Created on: Apr 13, 2019
 *      Author: Mostafa Samir Nawar		Mostafa.nwar@yahoo.com
 */
#include "SW.h"
#define SWS_MAX_NUMBER  (4)

static HAL_SW_tStates ModeSwState,OKSwState,PlusSwState,MinusSwState;

extern void HAL_SW_Init(void){
ModeSwState=SW_RELEASED;
OKSwState=SW_RELEASED;
PlusSwState=SW_RELEASED;
MinusSwState=SW_RELEASED;
}


extern HAL_SW_tStates HAL_SW_GetState(HAL_SW_tTypes Switch){
  HAL_SW_tStates temp ;
  switch(Switch){
  case (SW_MODESW):
    temp= ModeSwState;
      break ;
  case (SW_OKSW):
    temp= OKSwState;
      break ;
  case (SW_PLUSSW):
    temp =PlusSwState;
      break ;
  case (SW_MINUSSW):
    temp =MinusSwState;
      break ;
}
  return temp ;
}
/* A task which is Come each 20 ms to handle the 4 Switches State */
extern void HAL_SW_TaskStateUpdate(void){
  u8 SwPort, SwPin;
  HAL_SW_tStates SwState;
  HAL_SW_tStates temp;
  u8 i;
  u8 SwsPorts[SWS_MAX_NUMBER]={HAL_SW_MODE_PORT,HAL_SW_OK_PORT,HAL_SW_PLUS_PORT,HAL_SW_MINUS_PORT};
  u8 SwsPins[SWS_MAX_NUMBER]={HAL_SW_MODE_PIN,HAL_SW_OK_PIN,HAL_SW_PLUS_PIN,HAL_SW_MINUS_PIN};
  HAL_SW_tStates * SwsStatesPtrs[SWS_MAX_NUMBER]={ &ModeSwState,&OKSwState,&PlusSwState,&MinusSwState};

  for(i=0;i<SWS_MAX_NUMBER;i++){
    SwPort=SwsPorts[i];
    SwPin=SwsPins[i];
    SwState=*(SwsStatesPtrs[i]);

    temp = DIO_ReadPin(SwPort,SwPin);
      switch(SwState){
        case (SW_RELEASED):
            if(temp == SW_PRESSED)
              SwState=SW_PREPRESSED;
            else
              SwState=SW_RELEASED;
            break ;
        case (SW_PREPRESSED):
            if(temp == SW_PRESSED)
              SwState=SW_PRESSED;
            else
              SwState=SW_RELEASED;
                break ;
        case (SW_PRESSED):
            if(temp == SW_PRESSED)
             SwState=SW_PRESSED;
           else
             SwState=SW_PREPRESSED;
                break ;
        case (SW_PRERELEASED):
           if(temp == SW_PRESSED)
             SwState=SW_PRESSED;
           else
             SwState=SW_RELEASED;
                break ;
      }/*Switch Termination*/

    *(SwsStatesPtrs[i])=SwState;
}/*Loop Termination*/

}/*Function Termination*/
