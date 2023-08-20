/*
 *
 *<<<<<<<<<<<<<<<<<<<<<SSD_INTERFACE_H_>>>>>>>>>>>>>>>>>>>>>>>>
 * Author : ALIAA ESLAM ZAYED
 * Created: 15 /8/2023
 * Layer  : HAL
 * SWC    : SSD
 *
 */
#ifndef SSD_INTERFACE_H_
#define SSD_INTERFACE_H_


/** PORT Defines****/
#define SSD_PORTA  DIO_PORTA
#define SSD_PORTB  DIO_PORTB
#define SSD_PORTC  DIO_PORTC
#define SSD_PORTD  DIO_PORTD


/** PIN Defines****/
#define SSD_PIN0  DIO_PIN0
#define SSD_PIN1  DIO_PIN1
#define SSD_PIN2  DIO_PIN2
#define SSD_PIN3  DIO_PIN3
#define SSD_PIN4  DIO_PIN4
#define SSD_PIN5  DIO_PIN5
#define SSD_PIN6  DIO_PIN6
#define SSD_PIN7  DIO_PIN7

/** SSD Types*****/
#define SSD_COMMON_CATHOD   0
#define SSD_COMMON_ANODE    1


/** SSD Struct****/
typedef struct 
{
	u8 Type     ;
	u8 DataPort ;
	u8 EnablePort;
	u8 EnablePin ;
}SSD_TYPE;


/** Modes OF SSD*****/
#define SSD_ON   DIO_PORT_HIGH
#define SSD_OFF  DIO_PORT_LOW 

/** Modes OF SSD PIN*****/
#define SSD_PIN_HIGH   DIO_PIN_HIGH
#define SSD_PIN_LOW    DIO_PIN_LOW


/*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<Functions>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/


/**
	Function Name        : HSSD_voidSSDInitialization
	Function Returns     : void
	Function Arguments   : A_structSSDConfig
	Function Description : Intialize the given pin in the given port as an output pin
 */
void HSSD_voidSSDInitialization (SSD_TYPE A_structSSDConfig);

/**
	Function Name        : HSSD_voidSSDOn
	Function Returns     : void
	Function Arguments   : A_structSSDConfig
	Function Description : Set the SSD to be high
 */
void  HSSD_voidSSDOn            (SSD_TYPE A_structSSDConfig);


/**
	Function Name        : HSSD_voidSSDOff
	Function Returns     : void
	Function Arguments   : A_structSSDConfig
	Function Description : Clear the port of the SSD 
 */	

void HSSD_voidSSDOff            (SSD_TYPE A_structSSDConfig);


/**
	Function Name        : HSSD_voidSSDSendNumber
	Function Returns     : void
	Function Arguments   : A_structSSDConfig,  A_u8SSDNumber
	Function Description : Display a specific number on the SSD
 */
void HSSD_voidSSDSendNumber     (SSD_TYPE A_structSSDConfig, u8 A_u8SSDNumber);


#endif



