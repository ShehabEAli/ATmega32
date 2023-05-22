/***********************************************************************/
/****************   Author   : Shehab Emad Ali   ***********************/
/****************   File Name: SM_interface.h    ***********************/
/****************   Layer    : HAL	             ***********************/
/****************   Date     : 5 April 2023      ***********************/
/*Description : This file contains interfacing parameters of SM module */
/***********************************************************************/

/*preprocessor header file guard*/
#ifndef SM_INTERFACE_H_
#define SM_INTERFACE_H_


#define SM_PORT 	    DIO_PORTD


#define SM_PIN0			DIO_PIN0
#define SM_PIN1			DIO_PIN1
#define SM_PIN2		    DIO_PIN2
#define SM_PIN3		    DIO_PIN3


/*************************************************************************/
/*************************Functions' prototypes***************************/
/*************************************************************************/
void SM_voidInit(void);
void SM_voidCW_Continous(void);
void SM_voidCCW_Continous(void);
void SM_voidCW_WithAngel(u8 Copy_u8Angel);
void SM_voidCCW_WithAngel(u8 Copy_u8Angel);
void SM_voidTurnOff(void);

#endif /* SM_INTERFACE_H_ */
