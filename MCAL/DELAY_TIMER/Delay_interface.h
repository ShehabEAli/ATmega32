/***********************************************************************/
/****************   Author   : Shehab Emad Ali   ***********************/
/****************   File Name: TMI0_interface.h  ***********************/
/****************   Layer    : MCAL	             ***********************/
/****************   Date     : 7 April 2023      ***********************/
/*Description :This file contains interfacing parameters of TMI0 module*/
/***********************************************************************/



/*************************************************************************/
/*************************Functions' prototypes***************************/
/*************************************************************************/


/*This function shall start timer0*/

void Delay_voidSetDelaySync(u16 Copy_u16TimeInMillISec);
void Delay_voidSetDelayASync(u16 Copy_u16TimeInMillISec,void(* Copy_ptvoidfCallBack )(void));
