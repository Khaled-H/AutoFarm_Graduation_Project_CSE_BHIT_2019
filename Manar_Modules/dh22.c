/*
 * dh22.c
 *
 *  Created on: ??�/??�/????
 *      Author: manar
 */


#include "DH22.h"
static u8 ReadByte(void);
static void Delay_us(u8 DelayPeriod);

#define HAL_DHT_PINOUT  DIO_PORTA.DIO_CRL|=1<<17
#define HAL_DHT_PININ   DIO_PORTA.DIO_CRL|=8<<16



extern HAL_SENSORS_tDH22ReturnType HAL_DHT22_Read(void){
	HAL_SENSORS_tDH22ReturnType Ret;
	u8 Checksum;
	HAL_DHT_PINOUT;
	 MCAL_DIO_WritePin(HAL_SENSORS_DHT_PORT,HAL_SENSORS_DHT_CHANNEL,STD_LOW);
	 Delay_us(500);
	 MCAL_DIO_WritePin  (HAL_SENSORS_DHT_PORT,HAL_SENSORS_DHT_CHANNEL,STD_HIGH);
	 Delay_us(40);
	 HAL_DHT_PININ;
	 	while(MCAL_DIO_ReadPin(HAL_SENSORS_DHT_PORT,HAL_SENSORS_DHT_CHANNEL) == STD_HIGH );
	 	while(MCAL_DIO_ReadPin(HAL_SENSORS_DHT_PORT,HAL_SENSORS_DHT_CHANNEL) == STD_LOW );
	 			/*Response is Correct*/
		while(MCAL_DIO_ReadPin(HAL_SENSORS_DHT_PORT,HAL_SENSORS_DHT_CHANNEL) == STD_HIGH );
		 Ret.Hum = (u16)ReadByte();
		 Ret.Hum=(Ret.Hum<<8) | ((u16)ReadByte());
		 Ret.Temp = (u16)ReadByte();
		 Ret.Temp=(Ret.Temp<<8) | ((u16)ReadByte());
		 Checksum=ReadByte();
		 Ret.Hum=Ret.Hum/10;
		 Ret.Temp = Ret.Temp /10;
		 return Ret;
}

static u8 ReadByte(void){
	u8 i ,temp =0;
	for (i=0;i<8;i++){
		while(!(MCAL_DIO_ReadPin(HAL_SENSORS_DHT_PORT,HAL_SENSORS_DHT_CHANNEL)));
		Delay_us(50);
		if ((MCAL_DIO_ReadPin(HAL_SENSORS_DHT_PORT,HAL_SENSORS_DHT_CHANNEL)) == STD_LOW)   // if the pin is low
			{
				temp= temp & ~(1<<(8-i));   // write 0
			}
			else{
				temp = temp | (1<<(8-i));  // if the pin is high, write 1
				}
			while ((MCAL_DIO_ReadPin(HAL_SENSORS_DHT_PORT,HAL_SENSORS_DHT_CHANNEL)==STD_HIGH));  // wait for the pin to go low
		}
		return temp;
	}

static void Delay_us(u8 DelayPeriod){
	u8 i , j ;
	for(i=0;i<=DelayPeriod;i++){
		for(j=0;j<=4;j++);
	}
}
