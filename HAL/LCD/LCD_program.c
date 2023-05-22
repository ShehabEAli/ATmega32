/*****************************************************************************/
/*****************************************************************************/
/******************	   		Author:    Shehab Emad	   		******************/
/******************			File Name: LCD_program.c        ******************/
/******************			Layer:     HAL     		        ******************/
/******************			Date:      28/3/2023     	    ******************/
/*****************************************************************************/
/*****************************************************************************/
#include <util/delay.h>
#include <stdio.h>

#include "STD_TYPES.h"
#include "BIT_MATHS.h"

#include "DIO_interface.h"

#include "LCD_interface.h"
#include "LCD_private.h"
#include "LCD_cfg.h"
static u8 init=0 ;

/*LCD_DATA_PORT
LCD_CONTROL_PORT


RS_PIN
RW_PIN
EN_PIN*/
void LCD_voidLCDInit(void)
{
	DIO_voidSetPinDirection(LCD_CONTROL_PORT, RS_PIN, DIO_PIN_OUTPUT);
	DIO_voidSetPinDirection(LCD_CONTROL_PORT, RW_PIN, DIO_PIN_OUTPUT);
	DIO_voidSetPinDirection(LCD_CONTROL_PORT, EN_PIN, DIO_PIN_OUTPUT);
#if  LCD_MODE == _8_BIT
	DIO_voidSetPortDirection(LCD_DATA_PORT, DIO_PORT_OUTPUT);

	_delay_ms(40);
	LCD_voidSendCommand(FuncSet);
	_delay_us(100);

	LCD_voidSendCommand(Display_on);
	_delay_us(100);

	LCD_voidSendCommand(LCD_Clear);

#elif  LCD_MODE == _4_BIT
	DIO_voidSetPinDirection(LCD_DATA_PORT, DB4, DIO_PIN_OUTPUT);
	DIO_voidSetPinDirection(LCD_DATA_PORT, DB5, DIO_PIN_OUTPUT);
	DIO_voidSetPinDirection(LCD_DATA_PORT, DB6, DIO_PIN_OUTPUT);
	DIO_voidSetPinDirection(LCD_DATA_PORT, DB7, DIO_PIN_OUTPUT);
	_delay_ms(30);
	LCD_voidSendCommand(FuncSet0);
	LCD_voidSendCommand(FuncSet1);
	LCD_voidSendCommand(FuncSet2);
	_delay_ms(1);
	LCD_voidSendCommand(Display_on0);
	LCD_voidSendCommand(Display_on1);
	_delay_ms(1);
	LCD_voidSendCommand(LCD_Clear0);
	LCD_voidSendCommand(LCD_Clear1);
	_delay_ms(1);
	init=1;
#endif
}

void LCD_voidSendCommand(u8 Copy_u8CMD)
{
	DIO_voidSetPinValue(LCD_CONTROL_PORT,RS_PIN, DIO_LOW_PIN);
	DIO_voidSetPinValue(LCD_CONTROL_PORT,RW_PIN, DIO_LOW_PIN);

#if	LCD_MODE == _8_BIT
	DIO_u8SetPortValue(LCD_DATA_PORT, Copy_u8CMD);             // passing command to LSD port

	DIO_voidSetPinValue(LCD_CONTROL_PORT,EN_PIN, DIO_HIGH_PIN);
	_delay_ms(10);
	DIO_voidSetPinValue(LCD_CONTROL_PORT,EN_PIN, DIO_LOW_PIN);
#elif	LCD_MODE == _4_BIT
	DIO_voidSetPinValue(LCD_DATA_PORT,DB4, GET_BIT(Copy_u8CMD,DB4));
	DIO_voidSetPinValue(LCD_DATA_PORT,DB5, GET_BIT(Copy_u8CMD,DB5));
	DIO_voidSetPinValue(LCD_DATA_PORT,DB6, GET_BIT(Copy_u8CMD,DB6));
	DIO_voidSetPinValue(LCD_DATA_PORT,DB7, GET_BIT(Copy_u8CMD,DB7));
	_delay_ms(1);
	DIO_voidSetPinValue(LCD_CONTROL_PORT,EN_PIN, DIO_HIGH_PIN);
			_delay_ms(1);
			DIO_voidSetPinValue(LCD_CONTROL_PORT,EN_PIN, DIO_LOW_PIN);
	if(init){
		DIO_voidSetPinValue(LCD_DATA_PORT,DB4, GET_BIT(Copy_u8CMD,0));
		DIO_voidSetPinValue(LCD_DATA_PORT,DB5, GET_BIT(Copy_u8CMD,1));
		DIO_voidSetPinValue(LCD_DATA_PORT,DB6, GET_BIT(Copy_u8CMD,2));
		DIO_voidSetPinValue(LCD_DATA_PORT,DB7, GET_BIT(Copy_u8CMD,3));
		_delay_ms(1);
		DIO_voidSetPinValue(LCD_CONTROL_PORT,EN_PIN, DIO_HIGH_PIN);
		_delay_ms(10);
		DIO_voidSetPinValue(LCD_CONTROL_PORT,EN_PIN, DIO_LOW_PIN);
	}
#endif
}

void LCD_voidSendCharacter(u8 Copy_u8Character)
{
	DIO_voidSetPinValue(LCD_CONTROL_PORT,RS_PIN, DIO_HIGH_PIN);
	DIO_voidSetPinValue(LCD_CONTROL_PORT,RW_PIN, DIO_LOW_PIN);
#if	LCD_MODE == _8_BIT
	DIO_u8SetPortValue(LCD_DATA_PORT, Copy_u8Character);

	DIO_voidSetPinValue(LCD_CONTROL_PORT,EN_PIN, DIO_HIGH_PIN);
	_delay_ms(10);
	DIO_voidSetPinValue(LCD_CONTROL_PORT,EN_PIN, DIO_LOW_PIN);
#elif	LCD_MODE == _4_BIT
	DIO_voidSetPinValue(LCD_DATA_PORT,DB4, GET_BIT(Copy_u8Character,DB4));
	DIO_voidSetPinValue(LCD_DATA_PORT,DB5, GET_BIT(Copy_u8Character,DB5));
	DIO_voidSetPinValue(LCD_DATA_PORT,DB6, GET_BIT(Copy_u8Character,DB6));
	DIO_voidSetPinValue(LCD_DATA_PORT,DB7, GET_BIT(Copy_u8Character,DB7));
	DIO_voidSetPinValue(LCD_CONTROL_PORT,EN_PIN, DIO_HIGH_PIN);
	_delay_ms(1);
	DIO_voidSetPinValue(LCD_CONTROL_PORT,EN_PIN, DIO_LOW_PIN);

	DIO_voidSetPinValue(LCD_DATA_PORT,DB4, GET_BIT(Copy_u8Character,0));
	DIO_voidSetPinValue(LCD_DATA_PORT,DB5, GET_BIT(Copy_u8Character,1));
	DIO_voidSetPinValue(LCD_DATA_PORT,DB6, GET_BIT(Copy_u8Character,2));
	DIO_voidSetPinValue(LCD_DATA_PORT,DB7, GET_BIT(Copy_u8Character,3));
	DIO_voidSetPinValue(LCD_CONTROL_PORT,EN_PIN, DIO_HIGH_PIN);
	_delay_ms(1);
	DIO_voidSetPinValue(LCD_CONTROL_PORT,EN_PIN, DIO_LOW_PIN);
	_delay_ms(2);
#endif
}

void LCD_voidSendString(const char *Copy_pu8String)
{
	u8 Local_u8Iterator = 0;
	while (Copy_pu8String[Local_u8Iterator] != '\0')
	{
		LCD_voidSendCharacter(*(Copy_pu8String + Local_u8Iterator));
		Local_u8Iterator++;
	}

}

u8 LCD_u8GoTORowCol(u8 Copy_u8Row, u8 Copy_u8Col)
{
	u8 Local_u8ErrorState = 0;

	u8 Local_u8DDRAMAddress;

	if(((Copy_u8Row == 0) || (Copy_u8Row == 1)) && ((Copy_u8Col >= 0) && (Copy_u8Col < 16)))
	{
		if(Copy_u8Row == 0)
		{
			Local_u8DDRAMAddress = Copy_u8Col;
		}
		else if(Copy_u8Row == 1)
		{
			Local_u8DDRAMAddress = Copy_u8Col + 0x40;
		}
	}
	else
	{
		Local_u8ErrorState = 1;
	}

	/*modify the command to make bit 7 = 1*/
	Local_u8DDRAMAddress += 128;

	/*send command : Set DDRAM address*/
	LCD_voidSendCommand(Local_u8DDRAMAddress);

	return Local_u8ErrorState;
}


void LCD_voidSendSpecialCharacter(u8 *Copy_pu8Pattern, u8 Copy_u8Location, u8 Copy_u8Row, u8 Copy_u8Col)
{
	u8 Local_u8Iterator;
	u8 Local_u8CGRAMAddress;

	Local_u8CGRAMAddress = Copy_u8Location * 8;
	SET_BIT(Local_u8CGRAMAddress, 6);

	LCD_voidSendCommand(Local_u8CGRAMAddress);

	for (Local_u8Iterator = 0; Local_u8Iterator < 8; Local_u8Iterator++)
	{
		LCD_voidSendCharacter(Copy_pu8Pattern[Local_u8Iterator]);
	}
	LCD_u8GoTORowCol(Copy_u8Row, Copy_u8Col);

	LCD_voidSendCharacter(Copy_u8Location);
}

void LCD_voidSendNumber(u32 Number){
	char arr[16];
	sprintf(arr, "%d", Number);                // string printf in stdio
	LCD_voidSendString(arr);
}

