/***********************************************************************/
/****************   Author   : Shehab Emad Ali   ***********************/
/****************   File Name: ICU_interface.h   ***********************/
/****************   Layer    : MCAL	             ***********************/
/****************   Date     : 7 April 2023      ***********************/
/*Description :This file contains interfacing parameters of TMI0 module*/
/***********************************************************************/



/*************************************************************************/
/*************************Functions' prototypes***************************/
/*************************************************************************/


/*This function shall start timer0*/

void TIMER0_voidRunPWMFastNonInverted(u8 Copy_u8ComVal);
void Timer1_voidRunNormalMode(void);
void Timer1_voidClear(void);
u16 Timer1_u16GETReading(void);
