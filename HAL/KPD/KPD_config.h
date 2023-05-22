/************************************************************************/
/*Author      : Shehab Emad Ali										    */
/*File Name   : KPD_cfg.h                                               */
/*Layer       : HAL  												    */
/*Description : This file contains configurable paremeters of DIO module*/
/*Date        : 22 March 2023                                           */
/************************************************************************/

/*preprocessor header file guard*/
#ifndef KPD_CONFIG_H_
#define KPD_CONFIG_H_


/*This configuration is for the port connected to the keypad*/
/*Available configurations : DIO_PORTA , DIO_PORTB , DIO_PORTC , DIO_PORTD*/
#define KPD_PORT     DIO_PORTA

#define KPD_ROW0     DIO_PIN0
#define KPD_ROW1     DIO_PIN1
#define KPD_ROW2     DIO_PIN2
#define KPD_ROW3     DIO_PIN3

#define KPD_COL0     DIO_PIN4
#define KPD_COL1     DIO_PIN5
#define KPD_COL2     DIO_PIN6
#define KPD_COL3     DIO_PIN7


#define COL_NUM      4
#define ROW_NUM      4

#define KPD_NO_PRESSED_KEY    1


#define KPD_VALUES  {{'7', '8' , '9' , 'd'} , {'4', '5' , '6' , 'h'},{'1', '2' , '3' , 'l'},{'m', 'n' , 'o' , 'p'}}









#endif /* KPD_CONFIG_H_ */
