/***********************************************************************/
/****************   Author   : Shehab Emad Ali   ***********************/
/****************   File Name: SM_interface.h    ***********************/
/****************   Layer    : HAL	             ***********************/
/****************   Date     : 5 April 2023      ***********************/
/*Description : This file contains interfacing parameters of SM module */
/***********************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATHS.h"

#include "DIO_interface.h"
#include "DIO_private.h"
#include "DIO_cfg.h"

#include "SM_interface.h"
#include "SM_private.h"
#include "SM_cfg.h"
#include <util/delay.h>

/******************************************************************************/
/*************************Functions' implementation****************************/
/******************************************************************************/
void SM_voidInit(void){
	DIO_voidSetPinDirection(SM_PORT,SM_PIN0,DIO_PIN_OUTPUT);
	DIO_voidSetPinDirection(SM_PORT,SM_PIN1,DIO_PIN_OUTPUT);
	DIO_voidSetPinDirection(SM_PORT,SM_PIN2,DIO_PIN_OUTPUT);
	DIO_voidSetPinDirection(SM_PORT,SM_PIN3,DIO_PIN_OUTPUT);
}
void SM_voidCW_Continous(void){
	DIO_voidSetPinValue(SM_PORT,SM_PIN3,DIO_LOW_PIN);
	DIO_voidSetPinValue(SM_PORT,SM_PIN2,DIO_HIGH_PIN);
	DIO_voidSetPinValue(SM_PORT,SM_PIN1,DIO_HIGH_PIN);
	DIO_voidSetPinValue(SM_PORT,SM_PIN0,DIO_HIGH_PIN);
	_delay_ms(10);
	DIO_voidSetPinValue(SM_PORT,SM_PIN3,DIO_HIGH_PIN);
	DIO_voidSetPinValue(SM_PORT,SM_PIN2,DIO_LOW_PIN);
	DIO_voidSetPinValue(SM_PORT,SM_PIN1,DIO_HIGH_PIN);
	DIO_voidSetPinValue(SM_PORT,SM_PIN0,DIO_HIGH_PIN);
	_delay_ms(10);
	DIO_voidSetPinValue(SM_PORT,SM_PIN3,DIO_HIGH_PIN);
	DIO_voidSetPinValue(SM_PORT,SM_PIN2,DIO_HIGH_PIN);
	DIO_voidSetPinValue(SM_PORT,SM_PIN1,DIO_LOW_PIN);
	DIO_voidSetPinValue(SM_PORT,SM_PIN0,DIO_HIGH_PIN);
	_delay_ms(10);
	DIO_voidSetPinValue(SM_PORT,SM_PIN3,DIO_HIGH_PIN);
	DIO_voidSetPinValue(SM_PORT,SM_PIN2,DIO_HIGH_PIN);
	DIO_voidSetPinValue(SM_PORT,SM_PIN1,DIO_HIGH_PIN);
	DIO_voidSetPinValue(SM_PORT,SM_PIN0,DIO_LOW_PIN);
	_delay_ms(10);

}
void SM_voidCCW_Continous(void){
	DIO_voidSetPinValue(SM_PORT,SM_PIN0,DIO_LOW_PIN);
	DIO_voidSetPinValue(SM_PORT,SM_PIN1,DIO_HIGH_PIN);
	DIO_voidSetPinValue(SM_PORT,SM_PIN2,DIO_HIGH_PIN);
	DIO_voidSetPinValue(SM_PORT,SM_PIN3,DIO_HIGH_PIN);
	_delay_ms(10);
	DIO_voidSetPinValue(SM_PORT,SM_PIN0,DIO_HIGH_PIN);
	DIO_voidSetPinValue(SM_PORT,SM_PIN1,DIO_LOW_PIN);
	DIO_voidSetPinValue(SM_PORT,SM_PIN2,DIO_HIGH_PIN);
	DIO_voidSetPinValue(SM_PORT,SM_PIN3,DIO_HIGH_PIN);
	_delay_ms(10);
	DIO_voidSetPinValue(SM_PORT,SM_PIN0,DIO_HIGH_PIN);
	DIO_voidSetPinValue(SM_PORT,SM_PIN1,DIO_HIGH_PIN);
	DIO_voidSetPinValue(SM_PORT,SM_PIN2,DIO_LOW_PIN);
	DIO_voidSetPinValue(SM_PORT,SM_PIN3,DIO_HIGH_PIN);
	_delay_ms(10);
	DIO_voidSetPinValue(SM_PORT,SM_PIN0,DIO_HIGH_PIN);
	DIO_voidSetPinValue(SM_PORT,SM_PIN1,DIO_HIGH_PIN);
	DIO_voidSetPinValue(SM_PORT,SM_PIN2,DIO_HIGH_PIN);
	DIO_voidSetPinValue(SM_PORT,SM_PIN3,DIO_LOW_PIN);
	_delay_ms(10);



}
void SM_voidCW_WithAngel(u8 Copy_u8Angel){
	u8 Local_u8Iterator;
	for(Local_u8Iterator=0;Local_u8Iterator<=(Copy_u8Angel/0.703125);Local_u8Iterator++ ){
		DIO_voidSetPinValue(SM_PORT,SM_PIN3,DIO_LOW_PIN);
		DIO_voidSetPinValue(SM_PORT,SM_PIN2,DIO_HIGH_PIN);
		DIO_voidSetPinValue(SM_PORT,SM_PIN1,DIO_HIGH_PIN);
		DIO_voidSetPinValue(SM_PORT,SM_PIN0,DIO_HIGH_PIN);
		_delay_ms(10);
		DIO_voidSetPinValue(SM_PORT,SM_PIN3,DIO_HIGH_PIN);
		DIO_voidSetPinValue(SM_PORT,SM_PIN2,DIO_LOW_PIN);
		DIO_voidSetPinValue(SM_PORT,SM_PIN1,DIO_HIGH_PIN);
		DIO_voidSetPinValue(SM_PORT,SM_PIN0,DIO_HIGH_PIN);
		_delay_ms(10);
		DIO_voidSetPinValue(SM_PORT,SM_PIN3,DIO_HIGH_PIN);
		DIO_voidSetPinValue(SM_PORT,SM_PIN2,DIO_HIGH_PIN);
		DIO_voidSetPinValue(SM_PORT,SM_PIN1,DIO_LOW_PIN);
		DIO_voidSetPinValue(SM_PORT,SM_PIN0,DIO_HIGH_PIN);
		_delay_ms(10);
		DIO_voidSetPinValue(SM_PORT,SM_PIN3,DIO_HIGH_PIN);
		DIO_voidSetPinValue(SM_PORT,SM_PIN2,DIO_HIGH_PIN);
		DIO_voidSetPinValue(SM_PORT,SM_PIN1,DIO_HIGH_PIN);
		DIO_voidSetPinValue(SM_PORT,SM_PIN0,DIO_LOW_PIN);
		_delay_ms(10);

	}
}
void SM_voidCCW_WithAngel(u8 Copy_u8Angel){
	u8 Local_u8Iterator;
	for( Local_u8Iterator=0;Local_u8Iterator<=(Copy_u8Angel/0.703125);Local_u8Iterator++ ){
		DIO_voidSetPinValue(SM_PORT,SM_PIN0,DIO_LOW_PIN);
		DIO_voidSetPinValue(SM_PORT,SM_PIN1,DIO_HIGH_PIN);
		DIO_voidSetPinValue(SM_PORT,SM_PIN2,DIO_HIGH_PIN);
		DIO_voidSetPinValue(SM_PORT,SM_PIN3,DIO_HIGH_PIN);
		_delay_ms(10);
		DIO_voidSetPinValue(SM_PORT,SM_PIN0,DIO_HIGH_PIN);
		DIO_voidSetPinValue(SM_PORT,SM_PIN1,DIO_LOW_PIN);
		DIO_voidSetPinValue(SM_PORT,SM_PIN2,DIO_HIGH_PIN);
		DIO_voidSetPinValue(SM_PORT,SM_PIN3,DIO_HIGH_PIN);
		_delay_ms(10);
		DIO_voidSetPinValue(SM_PORT,SM_PIN0,DIO_HIGH_PIN);
		DIO_voidSetPinValue(SM_PORT,SM_PIN1,DIO_HIGH_PIN);
		DIO_voidSetPinValue(SM_PORT,SM_PIN2,DIO_LOW_PIN);
		DIO_voidSetPinValue(SM_PORT,SM_PIN3,DIO_HIGH_PIN);
		_delay_ms(10);
		DIO_voidSetPinValue(SM_PORT,SM_PIN0,DIO_HIGH_PIN);
		DIO_voidSetPinValue(SM_PORT,SM_PIN1,DIO_HIGH_PIN);
		DIO_voidSetPinValue(SM_PORT,SM_PIN2,DIO_HIGH_PIN);
		DIO_voidSetPinValue(SM_PORT,SM_PIN3,DIO_LOW_PIN);
		_delay_ms(10);
	}
}
void SM_voidTurnOff(void){
	DIO_voidSetPinValue(SM_PORT,SM_PIN0,DIO_LOW_PIN);
	DIO_voidSetPinValue(SM_PORT,SM_PIN1,DIO_LOW_PIN);
	DIO_voidSetPinValue(SM_PORT,SM_PIN2,DIO_LOW_PIN);
	DIO_voidSetPinValue(SM_PORT,SM_PIN3,DIO_LOW_PIN);
}
