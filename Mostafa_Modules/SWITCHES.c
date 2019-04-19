/*
 * SW.c
 *
 *  Created on: Apr 13, 2019
 *      Author: Mostafa Samir Nawar		Mostafa.nwar@yahoo.com
 */
#include "SWITCHES.h"
#define SWITCHES_MAX_NUMBER  (4)

static HAL_SWITCHES_tStates ModeSwState,OKSwState,PlusSwState,MinusSwState;

extern void HAL_SWITCHES_Init(void){
ModeSwState=SWITCHES_RELEASED;
OKSwState=SWITCHES_RELEASED;
PlusSwState=SWITCHES_RELEASED;
MinusSwState=SWITCHES_RELEASED;
}


extern HAL_SWITCHES_tStates HAL_SWITCHES_GetState(HAL_SWITCHES_tTypes Switch){
  HAL_SWITCHES_tStates temp ;
  switch(Switch){
  case (SWITCHES_MODESW):
    temp= ModeSwState;
      break ;
  case (SWITCHES_OKSW):
    temp= OKSwState;
      break ;
  case (SWITCHES_PLUSSW):
    temp =PlusSwState;
      break ;
  case (SWITCHES_MINUSSW):
    temp =MinusSwState;
      break ;
}
  return temp ;
}
/* A task which is Come each 20 ms to handle the 4 Switches State */
extern void HAL_SWITCHES_TaskStateUpdate(void){
  u8 SwPort, SwPin;
  HAL_SWITCHES_tStates SwState;
  HAL_SWITCHES_tStates temp;
  u8 i;
  u8 SwsPorts[SWITCHES_MAX_NUMBER]={HAL_SWITCHES_MODE_PORT,HAL_SWITCHES_OK_PORT,HAL_SWITCHES_PLUS_PORT,HAL_SWITCHES_MINUS_PORT};
  u8 SwsPins[SWITCHES_MAX_NUMBER]={HAL_SWITCHES_MODE_PIN,HAL_SWITCHES_OK_PIN,HAL_SWITCHES_PLUS_PIN,HAL_SWITCHES_MINUS_PIN};
  HAL_SWITCHES_tStates * SwsStatesPtrs[SWITCHES_MAX_NUMBER]={ &ModeSwState,&OKSwState,&PlusSwState,&MinusSwState};

  for(i=0;i<SWITCHES_MAX_NUMBER;i++){
    SwPort=SwsPorts[i];
    SwPin=SwsPins[i];
    SwState=*(SwsStatesPtrs[i]);

    temp = MCAL_DIO_ReadPin(SwPort,SwPin);
      switch(SwState){
        case (SWITCHES_RELEASED):
            if(temp == SWITCHES_PRESSED)
              SwState=SWITCHES_PREPRESSED;
            else
              SwState=SWITCHES_RELEASED;
            break ;
        case (SWITCHES_PREPRESSED):
            if(temp == SWITCHES_PRESSED)
              SwState=SWITCHES_PRESSED;
            else
              SwState=SWITCHES_RELEASED;
                break ;
        case (SWITCHES_PRESSED):
            if(temp == SWITCHES_PRESSED)
             SwState=SWITCHES_PRESSED;
           else
             SwState=SWITCHES_PREPRESSED;
                break ;
        case (SWITCHES_PRERELEASED):
           if(temp == SWITCHES_PRESSED)
             SwState=SWITCHES_PRESSED;
           else
             SwState=SWITCHES_RELEASED;
                break ;
      }/*Switch Termination*/

    *(SwsStatesPtrs[i])=SwState;
}/*Loop Termination*/

}/*Function Termination*/
