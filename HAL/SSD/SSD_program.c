/**************************************************************************/
/*Author      : Shehab Emad Ali										      */
/*File Name   : SSD_program.c                                             */
/*Layer       : HAL										  		          */
/*Description : This file contains functions' implementation of SSD module*/
/*Date        : 27 March 2023                                             */
/**************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATHS.h"

#include "DIO_interface.h"
#include "DIO_private.h"
#include "DIO_cfg.h"

#include "SSD_interface.h"
#include "SSD_private.h"
#include "SSD_cfg.h"



/******************************************************************************/
/*************************Functions' implementation****************************/
/******************************************************************************/

void SSD_void_Init(u8 Copy_u8PortID,u8 Copy_u8Comport,u8 Copy_u8Compin){
	DIO_voidSetPortDirection( Copy_u8PortID,DIO_PORT_OUTPUT );
	DIO_voidSetPinDirection( Copy_u8Comport,Copy_u8Compin,DIO_PIN_OUTPUT );

}

void SSD_voidOn(u8 Copy_u8connection,u8 Copy_u8Comport,u8 Copy_u8Compin){
	if(Copy_u8connection==COM_Cathode)
	{
		DIO_voidSetPinValue(Copy_u8Comport,Copy_u8Compin,DIO_LOW_PIN);

	}
	else if(Copy_u8connection==COM_Anode)
	{
		DIO_voidSetPinValue(Copy_u8Comport,Copy_u8Compin,DIO_HIGH_PIN);

	}

}

void SSD_voidDisplay(u8 Copy_u8PortID,u8 Copy_u8connection,u8 Copy_u8number){
	if(Copy_u8connection==COM_Cathode)
		{
			DIO_u8SetPortValue(Copy_u8PortID,Copy_u8number);

		}
	else if(Copy_u8connection==COM_Anode)
		{
			DIO_u8SetPortValue(Copy_u8PortID,~Copy_u8number);

		}
}

void SSD_voidOff(u8 Copy_u8connection,u8 Copy_u8Comport,u8 Copy_u8Compin){
	if(Copy_u8connection==COM_Cathode)
	{
		DIO_voidSetPinValue(Copy_u8Comport,Copy_u8Compin,DIO_HIGH_PIN);

	}
	else if(Copy_u8connection==COM_Anode)
	{
		DIO_voidSetPinValue(Copy_u8Comport,Copy_u8Compin,DIO_LOW_PIN);

	}
}

