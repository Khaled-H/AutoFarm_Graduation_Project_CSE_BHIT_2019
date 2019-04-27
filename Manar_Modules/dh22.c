/*
 * dh22.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: manar
 */


#include "DH22.h"

void HAL_DHT22_Start(void){
	 MCAL_Port_PinDirection(PORTA,MCAL_ADC_CHANNEL00,OutPut);
	 MCAL_DIO_WritePin  (PORTA,MCAL_ADC_CHANNEL00,0);
	 Delay_us(50);
	 MCAL_DIO_WritePin  (PORTA,MCAL_ADC_CHANNEL00,1);
	 Delay_us(3);
	 MCAL_Port_PinDirection(PORTA,MCAL_ADC_CHANNEL00,InPut);
}
void HAL_DHT22_CheckResponse (void){
	Delay(4);
	if(!(MCAL_DIO_ReadPin(PORTA,MCAL_ADC_CHANNEL00))){
		Delay_us(8);
		if((MCAL_DIO_ReadPin(PORTA,MCAL_ADC_CHANNEL00))==1);
	}
	while((MCAL_DIO_ReadPin(PORTA,MCAL_ADC_CHANNEL00)));
}

u8 HAL_DHT22_ReadData(void){
	u8 i ,j ;
	for (j=0;j<8;j++){
		while(!(MCAL_DIO_ReadPin(PORTA,MCAL_ADC_CHANNEL00)));
		Delay_us(4);
		if ((MCAL_DIO_ReadPin(PORTA,MCAL_ADC_CHANNEL00)) == 0)   // if the pin is low
			{
				i&= ~(1<<(7-j));   // write 0
			}
			else i|= (1<<(7-j));  // if the pin is high, write 1
			while ((MCAL_DIO_ReadPin(PORTA,MCAL_ADC_CHANNEL00)));  // wait for the pin to go low
		}
		return i;
	}
void Delay_us(u8 DelayPeriod){
	for(u8 i=0;i<=DelayPeriod;i++){
		for(u8 j=0;j<=10;j++);
	}
}


