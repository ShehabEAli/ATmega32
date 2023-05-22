/**************************************************************************/
/*Author      : Shehab Emad Ali										      */
/*File Name   : DIP_program.c                                             */
/*Layer       : HAL										  		          */
/*Description : This file contains functions' implementation of DIP module*/
/*Date        : 27 March 2023                                             */
/**************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATHS.h"

#include "DIO_interface.h"
#include "DIO_private.h"
#include "DIO_cfg.h"

#include "DIP_interface.h"
#include "DIP_private.h"
#include "DIP_cfg.h"


/******************************************************************************/
/*************************Functions' implementation****************************/
/******************************************************************************/

void DIP_void_DIPSwitchInit(u8 copy_u8DipPort,u8 copy_u8DipPin0,u8 copy_u8DipPin1,u8 copy_u8DipPin2){
		DIO_voidSetPinDirection(copy_u8DipPort, copy_u8DipPin0 , DIO_PIN_INPUT_PULLUP);
		DIO_voidSetPinDirection(copy_u8DipPort, copy_u8DipPin1 , DIO_PIN_INPUT_PULLUP);
		DIO_voidSetPinDirection(copy_u8DipPort, copy_u8DipPin2 , DIO_PIN_INPUT_PULLUP);
}
