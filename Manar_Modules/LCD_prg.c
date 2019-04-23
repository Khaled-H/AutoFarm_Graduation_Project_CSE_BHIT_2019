/***************************************************************************************/
/* Description ! 16x2 Character LCD for chip LMB161A                                   */
/* Release Date! 28/6/2016                                                             */
/* Version     ! V01                                                                   */
/***************************************************************************************/

/********************************** Header Files INCLUSIONS ****************************/
#include "Std_Types.h"
#include "Macros.h"

#define F_CPU 16000000UL
#include "util/delay.h"

#include "DIO_interface.h"
#include "LCD_interface.h"
/***************************************************************************************/

/*
 -----------                   ----------
 | ATmega32  |                 |   LCD    |
 |           |                 |          |
 |        PD7|---------------->|D7        |
 |        PD6|---------------->|D6        |
 |        PD5|---------------->|D5        |
 |        PD4|---------------->|D4        |
 |        PD3|---------------->|D3        |
 |        PD2|---------------->|D2        |
 |        PD1|---------------->|D1        |
 |        PD0|---------------->|D0        |
 |           |                 |          |
 |        PA2|---------------->|E         |
 |        PA1|---------------->|RW        |
 |        PA0|---------------->|RS        |
 -----------                   ----------
 */

/***************************************************************************************/
/********************************** Fucntion Definition ********************************/
/***************************************************************************************/



/***************************************************************************************/
/* Description! Apply initialization sequence for LCD module                           */
/* Input      ! Nothing                                                                */
/* Output     ! Nothing                                                                */
/***************************************************************************************/
void LCD_vidInit(void)
{
  /* Delay 100ms to ensure the initialization of the LCD driver */
  _delay_ms(100);

  /* Clear Display */
  LCD_vidSendCommand(0b00000001);

  /* Return Home  */
  LCD_vidSendCommand(0b00000010);

  /* Entry Mode Set  */
  LCD_vidSendCommand(0b00000110);

  /* Display ON OFF Control */
  LCD_vidSendCommand(0b00001100);

  /* Function Set  */
  LCD_vidSendCommand(0b00111000);

}


/***************************************************************************************/
/* Description! Interface to send the configuration commands to the LCD Driver         */
/* Input      ! Command number                                                         */
/* Output     ! Nothing                                                                */
/***************************************************************************************/
void LCD_vidSendCommand(u8 u8CmdCpy)
{

  /* Set RS to LOW */
  DIO_vidSetPinValue(DIO_PORTA, 0, STD_LOW);

  /* Set R/W to LOW */
  DIO_vidSetPinValue(DIO_PORTA, 1, STD_LOW);

  /* Set E to HIGH  */
  DIO_vidSetPinValue(DIO_PORTA, 2, STD_HIGH);

  /* Load Command on Data bus */
  DIO_vidSetPortValue(DIO_PORTD, u8CmdCpy);

  /* Set E to LOW */
  DIO_vidSetPinValue(DIO_PORTA, 2, STD_LOW);

  /* Wait for E to settle */
  _delay_ms(5);

  /* Set E to HIGH */
  DIO_vidSetPinValue(DIO_PORTA, 2, STD_HIGH);

  /* Delay for 10ms to let the LCD execute command */
  _delay_ms(10);

}

/***************************************************************************************/
/* Description! Interface to write character on LCD screen                             */
/* Input      ! Data to send                                                           */
/* Output     ! Nothing                                                                */
/***************************************************************************************/
void LCD_vidWriteCharctr(u8 u8DataCpy)
{
  /* Set RS to HIG */
  DIO_vidSetPinValue(DIO_PORTA, 0, STD_HIGH);

  /* Set R/W to LOW */
  DIO_vidSetPinValue(DIO_PORTA, 1, STD_LOW);

  /* Set E to HIGH */
  DIO_vidSetPinValue(DIO_PORTA, 2, STD_HIGH);

  /* Load Command on Data bus */
  DIO_vidSetPortValue(DIO_PORTD, u8DataCpy);

  /* Set E to LOW */
  DIO_vidSetPinValue(DIO_PORTA, 2, STD_LOW);

  /* Wait for E to settle */
  _delay_ms(5);

  /* Set E to HIGH */
  DIO_vidSetPinValue(DIO_PORTA, 2, STD_HIGH);

  /* Delay to let the LCD Display the character */
  _delay_ms(10);

}

/***************************************************************************************/
/* Description! Interface to write string on LCD screen                                */
/* Input      ! Pointer to the string                                                  */
/* Output     ! Nothing                                                                */
/***************************************************************************************/                                                                           */
void LCD_vidWriteString(u8* pu8StringCpy)
{

  /* Local loop index */
  u8 u8Index = 0;

  while (pu8StringCpy[u8Index] != 0)
  {
    /* Write Character on LCD */
    LCD_vidWriteCharctr(pu8StringCpy[u8Index]);

    /* Increment local loop index */
    u8Index++;

    /* Delay to let the LCD show the character */
    _delay_ms(2);
  }

}
