/*
 * main.c
 *
 *  Created on: Aug 16, 2023
 *      Author: user
 */



#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "DIO_private.h"

#include "LED_interface.h"

#include "SSD_interface.h"
#include "SSD_private.h"

LED_CONFIG LED1={ LED_PORTA,LED_PIN0,LED_ACTIVE_HIGH};
LED_CONFIG LED2={ LED_PORTA,LED_PIN1,LED_ACTIVE_HIGH};
LED_CONFIG LED3={ LED_PORTA,LED_PIN2,LED_ACTIVE_HIGH};


SSD_TYPE SSD1={SSD_COMMON_CATHOD,SSD_PORTC,SSD_PORTC,SSD_PIN7};
SSD_TYPE SSD2={SSD_COMMON_CATHOD,SSD_PORTD,SSD_PORTC,SSD_PIN7};
#include <avr/delay.h>

int main(void)
{
	HLED_voidLEDIntialization( LED1);
	HLED_voidLEDIntialization( LED2);
	HLED_voidLEDIntialization( LED3);


	HSSD_voidSSDInitialization(SSD1);
	HSSD_voidSSDInitialization(SSD2);


	u8 counter=0;
	while(1){
		HLED_voidLEDOn(LED1);
		while(counter<=9)
		{
			HSSD_voidSSDSendNumber(SSD1,counter);
			if(counter==9)
			{
				_delay_ms(100);
				HSSD_voidSSDSendNumber(SSD1,1);
				HSSD_voidSSDSendNumber(SSD2,0);
				_delay_ms(100);
				HSSD_voidSSDOff (SSD2);
				break;
			}
			else
				counter++;
			_delay_ms(100);
		}
		HLED_voidLEDIOff(LED1);
		HSSD_voidSSDOff (SSD2);

		counter=0;
		HLED_voidLEDOn(LED2);
		while(counter<=3)
		{
			HSSD_voidSSDSendNumber(SSD1,counter);

			counter++;
			_delay_ms(100);
		}
		HLED_voidLEDIOff(LED2);
		HSSD_voidSSDOff (SSD2);

		counter=0;
		HLED_voidLEDOn(LED3);
		while(counter<=9)
		{
			HSSD_voidSSDSendNumber(SSD1,counter);
			if(counter==9)
			{
				_delay_ms(100);
				HSSD_voidSSDSendNumber(SSD1,1);
				HSSD_voidSSDSendNumber(SSD2,0);
				_delay_ms(100);
				HSSD_voidSSDOff (SSD2);
				break;
			}
			else
				counter++;
			_delay_ms(100);
		}
		HLED_voidLEDIOff(LED3);
		HSSD_voidSSDOff (SSD2);
		counter=0;

	}
}




