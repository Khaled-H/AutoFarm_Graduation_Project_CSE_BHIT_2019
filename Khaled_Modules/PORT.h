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
#define  HAL_SENSORS_TEMP_PORT           (2)
#define  HAL_SENSORS_HUMMIDY_PORT        (1)
#define  HAL_SENSORS_AMONNIA_PORT        (2)
#define  HAL_SENSORS_COLEVEL_PORT        (1)
/***   PIN NUMBER  ***/
#define  HAL_SENSORS_TEMP_PIN            (0)
#define  HAL_SENSORS_HUMMIDY_PIN         (7)
#define  HAL_SENSORS_AMONNIA_PIN         (1)
#define  HAL_SENSORS_COLEVEL_PIN         (6)


/*************************************************************
**********************   HAL_LCD  **********************
*************************************************************/

/***  PORT NUMBER  ***/
#define  HAL_LCDRS_PORT                  (2)
#define  HAL_LCDRW_PORT                  (2)
#define  HAL_LCDEN_PORT                  (2)
#define  HAL_LCDD4_PORT                  (2)
#define  HAL_LCDD5_PORT                  (2)
#define  HAL_LCDD6_PORT                  (1)
#define  HAL_LCDD7_PORT                  (1)
/***   PIN NUMBER  ***/
#define  HAL_LCDRS_PIN                   (2)
#define  HAL_LCDRW_PIN                   (2)
#define  HAL_LCDEN_PIN                   (2)
#define  HAL_LCDD4_PIN                   (2)
#define  HAL_LCDD5_PIN                   (2)
#define  HAL_LCDD6_PIN                   (1)
#define  HAL_LCDD7_PIN                   (1)


/*************************************************************
**********************   HAL_SWITCHES  ******************
*************************************************************/

/***   PORT NUMBER  ***/
#define  HAL_SWITCHES_MODESW_PORT          (1)
#define  HAL_SWITCHES_OKSW_PORT            (2)
#define  HAL_SWITCHES_PLUS_PORT            (2)
#define  HAL_SWITCHES_MINUSSW_PORT         (2)
/***   PIN NUMBER  ***/
#define  HAL_SWITCHES_MODESW_PIN           (1)
#define  HAL_SWITCHES_OKSW_PIN             (2)
#define  HAL_SWITCHES_PLUS_PIN             (2)
#define  HAL_SWITCHES_MINUSSW_PIN          (2)


/*************************************************************
**********************   HAL_ACTUATORS  ****************
*************************************************************/

/***   PORT NUMBER  ***/
#define  HAL_ACTUATORS_UPPERFAN_PORT           (1)
#define  HAL_ACTUATORS_LOWERFAN_PORT           (1)
#define  HAL_ACTUATORS_HEATER_PORT             (1)
/***   PIN NUMBER  ***/
#define  HAL_ACTUATORS_UPPERFAN_PIN            (2)
#define  HAL_ACTUATORS_LOWERFAN_PIN            (1)
#define  HAL_ACTUATORS_HEATER_PIN              (3)


/*************************************************************
*******************   HAL_INDICATORS  ******************
*************************************************************/

/***  SYSTEM  INDICATOR  ***/
#define  HAL_NORMALMODE_LED_PORT       (01)
#define  HAL_OTA_LED_PORT              (01)
#define  HAL_BUZZER_PORT               (01)
/***   PIN NUMBER  ***/
#define  HAL_NORMALMODE_LED_PIN        (01)
#define  HAL_OTA_LED_PIN               (01)
#define  HAL_BUZZER_PIN                (01)


/*************************************************************
**********************   HAL_UART  *********************
*************************************************************/

/***   PORT NUMBER  ***/
#define  HAL_WIFI_TX_PORT              (2)
#define  HAL_WIFI_RX_PORT              (2)
/***   PIN NUMBER   ***/
#define  HAL_WIFI_TX_PIN               (6)
#define  HAL_WIFI_RX_PIN               (7)


/********************************************************************
*****************  HAL_ Functions Prototypes  *****************
********************************************************************/

/***  PORT/PIN CONFIGURATION   ***/
extern void MCAL_PORT_Init();



#endif /* PORT_H_ */
