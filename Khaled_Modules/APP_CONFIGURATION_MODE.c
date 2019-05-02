/*
 * APP_CONFIGURATION_MODE.c
 *
 *  Created on: Apr 30, 2019
 *      Author: khale
 */
#include "STD_TYPES.h"
#include "APP_CONFIGURATION_MODE.h"

u8  OkSwitchState     = 0;
u8  ModeSwitchState   = 0;
u8  PlusSwitchState   = 0;
u8  MinusSwitchState  = 0;

typedef enum  {
	FIRST_PAGE = 1,
	SECOND_PAGE,
	THIRD_PAGE,
	FOURTH_PAGE,
	FIFTH_PAGE,
	SIXTH_PAGE,
	SEVENTH_PAGE,
}APP_CONFIGURATIONMODE_tPageNum;


void APP_CONFIG_MODE_SwitchsUpdates(){

 // here we will get the four switches states

}

void APP_CONFIG_MODE_PageDisplay(){

	switch (FIRST_PAGE){




	}

}

void APP_CONFIG_MODE_SensorsRefLvlSetting(){

}

/*
 * get switches updates
 * update system important values
 * page display
 * set points
 *
 *
 */
