/*
 * dh22.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: manar
 */


#include "DH22.h"

#define HAL_DH22_DELAY_500uS (500)
#define HAL_DH22_DELAY_40uS (40)

typedef struct {
	u16 Temp ;
	u16 Hum ;
}HAL_SENSORS_tDH22ReturnType;

extern HAL_SENSORS_tDH22ReturnType HAL_DHT22_Read(void){
	HAL_SENSORS_tDH22ReturnType Ret;
	u8 Checksum;
	HAL_DHT_PINOUT;
	 MCAL_DIO_WritePin(HAL_SENSORS_DHT_PORT,HAL_SENSORS_DHT_CHANNEL,STD_LOW);
	 Delay_us(HAL_DH22_DELAY_500uS);
	 MCAL_DIO_WritePin  (HAL_SENSORS_DHT_PORT,HAL_SENSORS_DHT_CHANNEL,STD_HIGH);
	 Delay_us(HAL_DH22_DELAY_40uS);
	 HAL_DHT_PININ;
	 	while(MCAL_DIO_ReadPin(HAL_SENSORS_DHT_PORT,HAL_SENSORS_DHT_CHANNEL) == 1 );
	 	while(MCAL_DIO_ReadPin(HAL_SENSORS_DHT_PORT,HAL_SENSORS_DHT_CHANNEL) == 0 );
	 			/*Response is Correct*/
		while(MCAL_DIO_ReadPin(HAL_SENSORS_DHT_PORT,HAL_SENSORS_DHT_CHANNEL) == 1 );
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
		if ((MCAL_DIO_ReadPin(HAL_SENSORS_DHT_PORT,HAL_SENSORS_DHT_CHANNEL)) == 0)   // if the pin is low
			{
				temp= temp & ~(1<<(8-i));   // write 0
			}
			else{
				temp = temp | (1<<(8-i));  // if the pin is high, write 1
				}
			while ((MCAL_DIO_ReadPin(HAL_SENSORS_DHT_PORT,HAL_SENSORS_DHT_CHANNEL)==1));  // wait for the pin to go low
		}
		return temp;
	}

static void Delay_us(u8 DelayPeriod){
	u8 i , j ;
	for(i=0;i<=DelayPeriod;i++){
		for(j=0;j<=4;j++);
	}
}







