/*
 * PORT.h
 *
 *  Created on: Apr 19, 2019
 *      Author: Khaled
 */

#ifndef PORT_H_
#define PORT_H_

#include "STD_TYPES.h"
#include "DIO.h"


/*************************************************************
**********************   HAL_SENSORS  ******************
*************************************************************/

/***   PORT NUMBER  ***/
#define  HAL_SENSORS_AMONNIA_PORT        (2)
#define  HAL_SENSORS_TEMPRATURE_PORT     (2)
#define  HAL_SENSORS_HUMMIDY_PORT        (1)
#define  HAL_SENSORS_COLEVEL_PORT        (1)
/***   PIN NUMBER  ***/
#define  HAL_SENSORS_AMONNIA_PIN         (1)
#define  HAL_SENSORS_TEMPRATURE_PIN      (0)
#define  HAL_SENSORS_HUMMIDY_PIN         (7)
#define  HAL_SENSORS_COLEVEL_PIN         (6)


/*************************************************************
**********************   HAL_LCD  **********************
*************************************************************/

/***  PORT NUMBER  ***/
#define  HAL_LCD_RS_PORT        (2)
#define  HAL_LCD_EN_PORT        (2)
#define  HAL_LCD_D4_PORT        (2)
#define  HAL_LCD_D5_PORT        (2)
#define  HAL_LCD_D6_PORT        (1)
#define  HAL_LCD_D7_PORT        (1)
/***   PIN NUMBER  ***/
#define  HAL_LCD_RS_PIN         (12)
#define  HAL_LCD_EN_PIN         (13)
#define  HAL_LCD_D4_PIN         (14)
#define  HAL_LCD_D5_PIN         (15)
#define  HAL_LCD_D6_PIN         (08)
#define  HAL_LCD_D7_PIN         (09)


/*************************************************************
**********************   HAL_SWITCHES  ******************
*************************************************************/

/***   PORT NUMBER  ***/
#define  HAL_SWITCHES_MODE_PORT          (1)
#define  HAL_SWITCHES_SCROLLUP_PORT      (2)
#define  HAL_SWITCHES_SCROLLDOWN_PORT    (2)
#define  HAL_SWITCHES_RIGHT_PORT         (2)
#define  HAL_SWITCHES_LEFT_PORT          (2)
/***   PIN NUMBER  ***/
#define  HAL_SWITCHES_MODE_PIN           (1)
#define  HAL_SWITCHES_SCROLLUP_PIN       (2)
#define  HAL_SWITCHES_SCROLLDOWN_PIN     (2)
#define  HAL_SWITCHES_RIGHT_PIN          (2)
#define  HAL_SWITCHES_LEFT_PIN           (2)


/*************************************************************
**********************   HAL_ACTUATORS  ****************
*************************************************************/

/***   PORT NUMBER  ***/
#define  HAL_ACTUATORS_FAN_PORT          (1)
#define  HAL_ACTUATORS_AIRHOOD_PORT      (1)
#define  HAL_ACTUATORS_HEATER_PORT       (1)
/***   PIN NUMBER  ***/
#define  HAL_ACTUATORS_FAN_PIN           (1)
#define  HAL_ACTUATORS_AIRHOOD_PIN       (2)
#define  HAL_ACTUATORS_HEATER_PIN        (3)


/*************************************************************
*******************   HAL_INDICATORS  ******************
*************************************************************/

/***  SYSTEM  INDICATOR  ***/
#define  HAL_LED_PORT      (01)
#define  HAL_BUZZER_PORT   (01)
#define  HAL_LED_PIN       (10)
#define  HAL_BUZZER_PIN    (11)


/*************************************************************
**********************   HAL_UART  *********************
*************************************************************/

/***  UART PINs  ***/
#define  HAL_UART_TX_PORT (2)
#define  HAL_UART_RX_PORT (2)
#define  HAL_UART_TX_PIN  (6)
#define  HAL_UART_RX_PIN  (7)


/********************************************************************
*****************  HAL_ Functions Prototypes  *****************
********************************************************************/

/***  PORT/PIN CONFIGURATION   ***/
extern void MCAL_PORT_Init();



#endif /* PORT_H_ */
