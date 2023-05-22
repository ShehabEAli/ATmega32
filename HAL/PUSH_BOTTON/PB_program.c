/**************************************************************************/
/*Author      : Shehab Emad Ali										      */
/*File Name   : PB_program.c                                              */
/*Layer       : HAL										  		      */
/*Description : This file contains functions' implementation of DIO module*/
/*Date        : 22 March 2023                                             */
/**************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATHS.h"

#include "DIO_interface.h"
#include "PB_interface.h"
#include "PB_private.h"
#include "PB_cfg.h"


/******************************************************************************/
/*************************Functions' implementation****************************/
/******************************************************************************/

u8 PB_void_Init(u8 Copy_u8PBPortID,u8 Copy_u8PBPin,u8 Copy_PBConnection){
	u8 LocalErrorState=0;
	if(Copy_PBConnection==PB_PULL_UP||Copy_PBConnection==PB_PULL_DOWN)
	{
		if(Copy_PBConnection==PB_PULL_UP){
			DIO_voidSetPinDirection(Copy_u8PBPortID,Copy_u8PBPin,DIO_PORT_INPUT_PULLUP);
			LocalErrorState=1;
		}
		else if(Copy_PBConnection==PB_PULL_DOWN){
			DIO_voidSetPinDirection(Copy_u8PBPortID,Copy_u8PBPin,DIO_PORT_INPUT_FLOAT);
			LocalErrorState=1;
		}
	}
	return LocalErrorState;
}

u8 PB_u8_GetState(u8 Copy_u8PBPortID,u8 Copy_u8PBPin,u8 Copy_PBConnection){
	u8 Local_u8Var;

	if(Copy_PBConnection==PB_PULL_UP){
		Local_u8Var=DIO_voidGetPinValue(Copy_u8PBPortID,Copy_u8PBPin);
		if(Local_u8Var==1){
			return PB_PU_RELEASED;
		}
		else if(Local_u8Var==0){
			return PB_PU_PRESSED;
		}
	}

	if(Copy_PBConnection==PB_PULL_DOWN){
		Local_u8Var=DIO_voidGetPinValue(Copy_u8PBPortID,Copy_u8PBPin);
		if(Local_u8Var==0){
			return PB_PD_RELEASED;
		}
		else if(Local_u8Var==1){
			return PB_PD_PRESSED;
		}
	}
	return Local_u8Var;
}



