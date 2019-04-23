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
#define  HAL_SENSORS_TEMP_PORT                 (1)
#define  HAL_SENSORS_HUMMIDY_PORT              (1)
#define  HAL_SENSORS_AMONNIA_PORT              (1)
#define  HAL_SENSORS_COLEVEL_PORT              (1)
/***   PIN NUMBER  ***/
#define  HAL_SENSORS_TEMP_PIN                  (4)
#define  HAL_SENSORS_HUMMIDY_PIN               (5)
#define  HAL_SENSORS_AMONNIA_PIN               (6)
#define  HAL_SENSORS_COLEVEL_PIN               (7)


/*************************************************************
**********************   HAL_LCD  **********************
*************************************************************/

/***  PORT NUMBER  ***/
#define  HAL_LCD_CONTROL_PORT                  (1)
#define  HAL_LCD_DATA_PORT                     (2)
/***   PIN NUMBER  ***/
#define  HAL_LCD_RS_PIN                        (9)
#define  HAL_LCD_EN_PIN                        (8)


/*************************************************************
**********************   HAL_SWITCHES  **********************
*************************************************************/

/***   PORT NUMBER  ***/
#define  HAL_SWITCHES_MODESW_PORT              (1)
#define  HAL_SWITCHES_OKSW_PORT                (2)
#define  HAL_SWITCHES_PLUSSW_PORT              (2)
#define  HAL_SWITCHES_MINUSSW_PORT             (2)
/***   PIN NUMBER  ***/
#define  HAL_SWITCHES_MODESW_PIN              (15)
#define  HAL_SWITCHES_OKSW_PIN                 (3)
#define  HAL_SWITCHES_PLUSSW_PIN               (4)
#define  HAL_SWITCHES_MINUSSW_PIN              (5)


/*************************************************************
**********************   HAL_ACTUATORS  ****************
*************************************************************/

/***   PORT NUMBER  ***/
#define  HAL_ACTUATORS_UPPERFAN_PORT           (1)
#define  HAL_ACTUATORS_LOWERFAN_PORT           (1)
#define  HAL_ACTUATORS_HEATER_PORT             (1)
/***   PIN NUMBER  ***/
#define  HAL_ACTUATORS_UPPERFAN_PIN            (1)
#define  HAL_ACTUATORS_LOWERFAN_PIN            (2)
#define  HAL_ACTUATORS_HEATER_PIN              (3)


/*************************************************************
*******************   HAL_INDICATORS  ******************
*************************************************************/

/***  SYSTEM  INDICATOR  ***/
#define  HAL_LEDS_NORMALMODELED_PORT          (01)
#define  HAL_LEDS_OTALED_PORT                 (01)
#define  HAL_BUZZER_PORT                      (01)
/***   PIN NUMBER  ***/
#define  HAL_LEDS_NORMALMODELED_PIN           (10)
#define  HAL_LEDS_OTALED_PIN                  (11)
#define  HAL_BUZZER_PIN                       (12)


/*************************************************************
**********************   HAL_UART  ***************************
*************************************************************/

/***   PORT NUMBER  ***/
#define  HAL_WIFI_TX_PORT                      (2)
#define  HAL_WIFI_RX_PORT                      (2)
/***   PIN NUMBER   ***/
#define  HAL_WIFI_TX_PIN                       (6)
#define  HAL_WIFI_RX_PIN                       (7)


/********************************************************************
*****************  HAL_ Functions Prototypes  *****************
********************************************************************/

/***  PORT/PIN CONFIGURATION   ***/
extern void MCAL_PORT_Init();



#endif /* PORT_H_ */

