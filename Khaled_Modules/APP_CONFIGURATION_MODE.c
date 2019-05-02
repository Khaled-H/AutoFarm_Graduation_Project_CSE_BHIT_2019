/*
 * APP_CONFIGURATION_MODE.c
 *
 *  Created on: Apr 30, 2019
 *      Author: khale
 */
#include "STD_TYPES.h"
#include "APP_CONFIGURATION_MODE.h"

#define WellcomPageDisplayTime    (5)      // defined form the team leader ,want to be 5sec

u8  OkSwitchState     = SWITCHES_RELEASED; // will be in the init function
u8  ModeSwitchState   = SWITCHES_RELEASED;
u8  PlusSwitchState   = SWITCHES_RELEASED;
u8  MinusSwitchState  = SWITCHES_RELEASED;

typedef enum  {
	CONFIG_MODE_WELCOMPAGE = 1,
	CONFIG_MODE_DEFAULTSPAGE,
	CONFIG_MODE_SETTINGPAGE,
	CONFIG_MODE_ENDPAGE,
}APP_CONFIG_tPageNum;


typedef enum  {
	TEMPERATURE_LVL_SEETING = 1,
	HUMMIDITY_LVL_SEETING,
	AMMINIA_LVL_SEETING,
	CO_LVL_SEETING,
}APP_CONFIG_tSensorForSetting;

APP_CONFIG_tPageNum APP_CONFIG_PageNum = 0 ;        //the page to display
APP_CONFIG_tSensorForSetting SensorForSetting = 0;  //the sensor to set

void APP_CONFIG_MODE_Init(){
APP_CONFIG_tPageNum APP_CONFIG_PageNum = CONFIG_MODE_WELCOMPAGE ;        // the first page of configuration mode
APP_CONFIG_tSensorForSetting SensorForSetting = TEMPERATURE_LVL_SEETING;  // the first sensor for setting reference point
}

void APP_CONFIG_MODE_TaskProcess(){

static u32 firstpagetimeout = 0 ;                   // time duration for displaying welcome page

APP_CONFIG_MODE_PageDisplay(APP_CONFIG_PageNum);    // display the current page

/***************************   select the current page     ****************************/

switch (APP_CONFIG_PageNum){
/*** Case of the welcome  page ***/
case CONFIG_MODE_WELCOMPAGE:
	if (firstpagetimeout == WellcomPageDisplayTime ){
		APP_CONFIG_PageNum = CONFIG_MODE_DEFAULTSPAGE;
		break;
	}
	else {
		firstpagetimeout ++;
	}
	break;

/*** Case of the Defaults  page ***/
case CONFIG_MODE_DEFAULTSPAGE :
	OkSwitchState = APP_CONFIG_MODE_SwitchsUpdates(SWITCHES_OKSW);            //wait until OK switch be pressed
	if (OkSwitchState == SWITCHES_PRESSED){
		APP_CONFIG_PageNum = CONFIG_MODE_SETTINGPAGE;
		break;
	}
	else {}
	break;

/*** Case of the setting  page ***/
case CONFIG_MODE_SETTINGPAGE :
		/**********   select sensor  for setting   *************/
		switch (SensorForSetting){

		/*** Case of temperature sensor ***/
		case TEMPERATURE_LVL_SEETING:
			OkSwitchState = APP_CONFIG_MODE_SwitchsUpdates (SWITCHES_OKSW);
			if (OkSwitchState == SWITCHES_PRESSED ){
				SensorForSetting = HUMMIDITY_LVL_SEETING;
				break;
			}
			else {
				APP_CONFIG_MODE_SensorRefSeeting(TEMPERATURE_LVL_SEETING);
			}
			break;

		/*** Case of humidity sensor ***/
		case HUMMIDITY_LVL_SEETING:
			OkSwitchState = APP_CONFIG_MODE_SwitchsUpdates (SWITCHES_OKSW);
			if (OkSwitchState == SWITCHES_PRESSED ){
				SensorForSetting = AMMINIA_LVL_SEETING;
				break;
			}
			else {
				APP_CONFIG_MODE_SensorRefSeeting(HUMMIDITY_LVL_SEETING);
			}
			break;

		/*** Case of ammonia sensor ***/
		case AMMINIA_LVL_SEETING:
			OkSwitchState = APP_CONFIG_MODE_SwitchsUpdates (SWITCHES_OKSW);
			if (OkSwitchState == SWITCHES_PRESSED ){
				SensorForSetting = CO_LVL_SEETING;
				break;
			}
			else {
				APP_CONFIG_MODE_SensorRefSeeting(AMMINIA_LVL_SEETING);
			}
			break;

		/*** Case of CO sensor ***/
		case CO_LVL_SEETING:
			OkSwitchState = APP_CONFIG_MODE_SwitchsUpdates (SWITCHES_OKSW);
			if (OkSwitchState == SWITCHES_PRESSED ){
				APP_CONFIG_PageNum = CONFIG_MODE_ENDPAGE;
				break;
			}
			else {
				APP_CONFIG_MODE_SensorRefSeeting(CO_LVL_SEETING);
			}
			break;
		}
	}
}



void APP_CONFIG_MODE_SwitchsUpdates(HAL_SWITCHES_tTypes SwitchType){

}

void APP_CONFIG_MODE_PageDisplay(APP_CONFIG_tPageNum  PageNum){

}

void APP_CONFIG_MODE_SensorRefSeeting(){

}






