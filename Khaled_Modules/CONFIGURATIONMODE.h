/*
 * CONFIGURATIONMODE.h
 *
 *  Created on: May 2, 2019
 *      Author: khale
 */

#ifndef CONFIGURATIONMODE_H_
#define CONFIGURATIONMODE_H_

#include "SWITCHES.h"

extern u8  OkSwitchState     = SWITCHES_RELEASED; // will be in the init function
extern u8  ModeSwitchState   = SWITCHES_RELEASED;
extern u8  PlusSwitchState   = SWITCHES_RELEASED;
extern u8  MinusSwitchState  = SWITCHES_RELEASED;



void APP_CONFIG_MODE_SwitchsUpdates(HAL_SWITCHES_tTypes SwitchType);
void APP_CONFIG_MODE_PageDisplay(APP_CONFIG_tPageNum  PageNum);
void APP_CONFIG_MODE_SensorRefSeeting();



#endif /* CONFIGURATIONMODE_H_ */
