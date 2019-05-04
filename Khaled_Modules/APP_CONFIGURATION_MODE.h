/*
 * APP_CONFIGURATION_MODE.h
 *
 *  Created on: Apr 30, 2019
 *      Author: khale
 */

#ifndef APP_CONFIGURATION_MODE_H_
#define APP_CONFIGURATION_MODE_H_


#include "CONFIGURATIONMODE.h"

/***************************   configuration mode Types    **********************/
/**** configuration mode pages ***/
typedef enum  {
	CONFIG_MODE_WELCOMPAGE = 1,
	CONFIG_MODE_DEFAULTSPAGE,
	CONFIG_MODE_SETTINGPAGE,
	CONFIG_MODE_ENDPAGE,
}APP_CONFIG_tPageNum;

/**** sensors to be set  ***/
typedef enum  {
	TEMPERATURE_LVL_SEETING = 1,
	HUMMIDITY_LVL_SEETING,
	AMMINIA_LVL_SEETING,
	CO_LVL_SEETING,
}APP_CONFIG_tSensorForSetting;

/***************************   constant declaration    **************************/
#define WellcomPageDisplayTime    (5)      // defined form the team leader ,want to be 5sec


/**************************  Configuration mode function prototypes  *********************/
extern void APP_CONFIG_MODE_TaskProcess();



void APP_CONFIG_MODE_SwitchsUpdates();
void APP_CONFIG_MODE_PageDisplay();
void APP_CONFIG_MODE_SensorsRefLvlSetting();

#endif /* APP_CONFIGURATION_MODE_H_ */
