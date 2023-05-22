/************************************************************************/
/*Author      : Shehab Emad Ali										    */
/*File Name   : KPD_interface.h                                         */
/*Layer       : HAL 												    */
/*Description : This file contains interfacing paremeters of DIO module */
/*Date        : 22 March 2023                                           */
/************************************************************************/

/*preprocessor header file guard*/
#ifndef KPD_INTERFACE_H_
#define KPD_INTERFACE_H_


/*************************************************************************/
/*************************Interfacing macros******************************/
/*************************************************************************/


/*************************************************************************/
/*************************Functions' prototypes***************************/
/*************************************************************************/

/*This function shall initialise the KPD*/
void KPD_voidInit(void);

/*This function shall return the value of any pressed key*/
u8 KPD_u8GetPressedKey(void);

#endif /* KPD_INTERFACE_H_ */
