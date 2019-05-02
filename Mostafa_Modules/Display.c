/*
 * Display.c
 *
 *  Created on: Apr 24, 2019
 *      Author: Mostafa Samir Nawar		Mostafa.nwar@yahoo.com
 */

#include "DISPALY.h"

extern void APP_DISPLAY_INIT(void){
  HAL_LCD_Init();
}

/*Task to Come every 15 ms to refresh the LCD Display*/
extern void APP_DISPLAY_Task(void){
  HAL_LCD_SetCursor(HAL_LCD_FIRSTROW, HAL_LCD_COLUMN1);
  HAL_LCD_WriteString("Temp:");
  HAL_LCD_WriteNumber(APP_SENSORREADER_GetTempLvl());
  HAL_LCD_WriteString("   ");
  HAL_LCD_WriteString("Hum:");
  HAL_LCD_WriteNumber(APP_SENSORREADER_GetHumLvl());
  HAL_LCD_SetCursor(HAL_LCD_SECONDROW, HAL_LCD_COLUMN1);
  HAL_LCD_WriteString("Amonia:");
  HAL_LCD_WriteNumber(APP_SENSORREADER_GetAmoniaLvl());
  HAL_LCD_WriteString("  ");
  HAL_LCD_WriteString("CO:");
  HAL_LCD_WriteNumber(APP_SENSORREADER_GetCo2Lvl());
}

