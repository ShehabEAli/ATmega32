/*****************************************************************************/
/*****************************************************************************/
/******************	   		Author:    Shehab Emad	   		******************/
/******************			File Name: LCD_interface.h      ******************/
/******************			Layer:     HAL     		        ******************/
/******************			Date:      29/3/2023     	    ******************/
/*****************************************************************************/
/*****************************************************************************/

#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_
/**************LCD_MODES******************/
#define _8_BIT            0
#define FuncSet           0x38
#define Display_on        0x0F
#define LCD_Clear         0x01
/*****************************************/
#define _4_BIT            1
#define FuncSet0          0x20       // first function sent
#define FuncSet1          0x20       // second function sent
#define FuncSet2          0xC0       // third function sent
#define Display_on0       0x00       //first Display on
#define Display_on1       0xF0       //second display on
#define LCD_Clear0        0x00       //first lcd clear cmd sent
#define LCD_Clear1        0x10       //second lcd clear cmd sent
#define DB4               4          //connection pins
#define DB5               5
#define DB6               6
#define DB7               7



void LCD_voidLCDInit(void);

void LCD_voidSendCommand(u8 CMD);

void LCD_voidSendCharacter(u8 Character);

void LCD_voidSendString(const char *Copy_pu8String);

u8 LCD_u8GoTORowCol(u8 Copy_u8Row, u8 Copy_u8Col);

void LCD_voidSendSpecialCharacter(u8 *Copy_pu8Pattern, u8 Copy_u8Location, u8 Copy_u8Row, u8 Copy_u8Col);

void LCD_voidSendNumber(u32 Number);


#endif
