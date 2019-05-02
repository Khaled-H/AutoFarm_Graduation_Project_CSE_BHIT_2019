/*
 * APP_CONFIGURATION_MODE.c
 *
 *  Created on: Apr 30, 2019
 *      Author: khale
 */
#include "STD_TYPES.h"
#include "APP_CONFIGURATION_MODE.h"



u8  OkSwitchState     = SWITCHES_RELEASED; // will be init function
u8  ModeSwitchState   = SWITCHES_RELEASED;
u8  PlusSwitchState   = SWITCHES_RELEASED;
u8  MinusSwitchState  = SWITCHES_RELEASED;

typedef enum  {
	CONFIG_MODE_WELLCOMPAGE = 1,
	CONFIG_MODE_DEFAULTSPAGE,
	CONFIG_MODE_SETTINGPAGE,
	CONFIG_MODE_ENDPAGE,
}APP_CONFIG_tPageNum;


void APP_CONFIG_MODE_SwitchsUpdates(HAL_SWITCHES_tTypes SwitchType){

 // here we will get the four switches states

}

void APP_CONFIG_MODE_PageDisplay(APP_CONFIG_tPageNum  PageNum){

	switch (PageNum){
	case CONFIG_MODE_WELLCOMPAGE :




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
APP_CONFIG_tPageNum APP_CONFIG_PageNum = CONFIG_MODE_WELLCOMPAGE ;    //will be in the init function

void APP_CONFIG_MODE_TaskLvlsUpdate(){

	u32 WellcomPageDisplayTime = 0 ;                                 //will be in the init function

	switch (APP_CONFIG_PageNum){
	case CONFIG_MODE_WELLCOMPAGE:
		// welcome page operation
		APP_CONFIG_MODE_PageDisplay(CONFIG_MODE_WELLCOMPAGE);
		WellcomPageDisplayTime ++;
		// switch to the next page check;
		if (WellcomPageDisplayTime == WellcomPageDisplayTime ){
			APP_CONFIG_PageNum = CONFIG_MODE_DEFAULTSPAGE;
		}
		else {};
		break;

	case CONFIG_MODE_DEFAULTSPAGE :
		APP_CONFIG_MODE_PageDisplay(CONFIG_MODE_WELLCOMPAGE);
		APP_CONFIG_MODE_SwitchsUpdates (SWITCHES_OKSW);
		if (OkSwitchState == SWITCHES_PRESSED){
			APP_CONFIG_PageNum = CONFIG_MODE_ENDPAGE;

		}
		else {}
		break;
	case CONFIG_MODE_SETTINGPAGE :

		APP_CONFIG_MODE_PageDisplay(CONFIG_MODE_SETTINGPAGE);
		APP_CONFIG_MODE_SwitchsUpdates (SWITCHES_OKSW);
		if (OkSwitchState == SWITCHES_PRESSED){
			APP_CONFIG_PageNum = CONFIG_MODE_SETTINGPAGE ;

		}
		else {}
		break;




	}
}





