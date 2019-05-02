/*
 * LEDS.c
 *
 *  Created on: Apr 20, 2019
 *      Author: Mostafa Samir Nawar		Mostafa.nwar@yahoo.com
 */
#include "LEDS.h"

#define HAL_LEDS_LEDON  (1)
#define HAL_LEDS_LEDOFF (0)


/******************     Normal Mode Led On Function     ***********************/
extern void HAL_LEDS_NormalModeLed_ON(void){
MCAL_DIO_WritePin(HAL_LEDS_NORMALMODELED_PORT, HAL_LEDS_NORMALMODELED_PIN,HAL_LEDS_LEDON);
}
/******************     OTA Mode Led On Function     ***********************/
extern void HAL_LEDS_OTAModeLed_ON(void){
  MCAL_DIO_WritePin(HAL_LEDS_OTALED_PORT, HAL_LEDS_OTALED_PIN,HAL_LEDS_LEDON);
}
/******************     Normal Mode Led OFF Function     ***********************/
extern void HAL_LEDS_NormalModeLed_OFF(void){
  MCAL_DIO_WritePin(HAL_LEDS_NORMALMODELED_PORT, HAL_LEDS_NORMALMODELED_PIN,HAL_LEDS_LEDOFF);
}
/******************     OTA Mode Led OFF Function     ***********************/
extern void HAL_LEDS_OTAModeLed_OFF(void){
  MCAL_DIO_WritePin(HAL_LEDS_OTALED_PORT, HAL_LEDS_OTALED_PIN,HAL_LEDS_LEDOFF);
}
/******************     Normal Mode Led Toggle Function     ***********************/
extern void HAL_LEDS_NormalModeLed_Toggle(void){
  MCAL_DIO_TogglePin(HAL_LEDS_NORMALMODELED_PORT,HAL_LEDS_NORMALMODELED_PIN);
}
/******************     OTA Mode Led Toggle Function     ***********************/
extern void HAL_LEDS_OTAModeLed_Toggle(void){
  MCAL_DIO_TogglePin(HAL_LEDS_OTALED_PORT,HAL_LEDS_OTALED_PIN);

}
