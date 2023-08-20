/*
 *
 *<<<<<<<<<<<<<<<<<<<<<SSD_PROGRAM.c>>>>>>>>>>>>>>>>>>>>>
 * Author : ALIAA ESLAM ZAYED
 * Created: 15 /8/2023
 * Layer  : HAL
 * SWC    : SSD
 *
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "DIO_private.h"

#include "LED_interface.h"
#include "LED_private.h"

#include "SSD_interface.h"
#include "SSD_private.h"


static u8 Local_u8SSDNumbers[10] = SSD_NUMBER_CATHOD;


void HSSD_voidSSDInitialization (SSD_TYPE A_structSSDConfig)
{
	MDIO_voidSetPortDirection (A_structSSDConfig.DataPort , SSD_ON);
}

void HSSD_voidSSDOn            (SSD_TYPE A_structSSDConfig)
{
	if(A_structSSDConfig.Type== SSD_COMMON_CATHOD )
	{
		MDIO_voidSetPortValue   (A_structSSDConfig.DataPort , Local_u8SSDNumbers[0]);
		MDIO_voidSetPinDirection(A_structSSDConfig.EnablePort , A_structSSDConfig.EnablePin ,SSD_PIN_HIGH );
		MDIO_voidSetPinValue    (A_structSSDConfig.EnablePort , A_structSSDConfig.EnablePin ,SSD_PIN_LOW);
	}
	else if(A_structSSDConfig.Type== SSD_COMMON_ANODE )
	{
		MDIO_voidSetPortValue   (A_structSSDConfig.DataPort , ~Local_u8SSDNumbers[0]);
		MDIO_voidSetPinDirection(A_structSSDConfig.EnablePort , A_structSSDConfig.EnablePin ,SSD_PIN_HIGH );
		MDIO_voidSetPinValue    (A_structSSDConfig.EnablePort , A_structSSDConfig.EnablePin ,SSD_PIN_HIGH );
	}
}

void HSSD_voidSSDOff            (SSD_TYPE A_structSSDConfig)
{
	if(A_structSSDConfig.Type== SSD_COMMON_CATHOD )
	{
		MDIO_voidSetPinDirection(A_structSSDConfig.EnablePort , A_structSSDConfig.EnablePin ,SSD_PIN_LOW );
		MDIO_voidClrPortValue   (A_structSSDConfig.DataPort  );
	}
	else if(A_structSSDConfig.Type== SSD_COMMON_ANODE )
	{
		MDIO_voidSetPinDirection(A_structSSDConfig.EnablePort , A_structSSDConfig.EnablePin ,SSD_PIN_HIGH );
		MDIO_voidClrPortValue   (A_structSSDConfig.DataPort );
	}
}

void HSSD_voidSSDSendNumber(SSD_TYPE A_structSSDConfig, u8 A_u8SSDNumber)
{
	if(A_structSSDConfig.Type== SSD_COMMON_CATHOD )
	{
		MDIO_voidSetPortValue(A_structSSDConfig.DataPort , Local_u8SSDNumbers[ A_u8SSDNumber]);
	}
	else if(A_structSSDConfig.Type== SSD_COMMON_ANODE )
	{
		MDIO_voidSetPortValue(A_structSSDConfig.DataPort , ~Local_u8SSDNumbers[A_u8SSDNumber]);
	}
}

