/***********************************************************************/
/****************   Author   : Shehab Emad Ali   ***********************/
/****************   File Name: TIM0_interface.h  ***********************/
/****************   Layer    : MCAL	             ***********************/
/****************   Date     : 7 April 2023      ***********************/
/*Description :This file contains interfacing parameters of TIM0 module*/
/***********************************************************************/

/*preprocessor header file guard*/
#ifndef TIM0_PRIVATE_H_
#define TIM0_PRIVATE_H_


/****************************************/
/*********  TIM0 Registers   ************/
/****************************************/

#define TCCR0       ( *( volatile u8 * ) (0x53) )
#define TCCR0_WGM00                 6  //two bits for mode of timer0
#define TCCR0_WGM01                 3
#define TCCR0_COM01                 5  //two bits for behaviour of OC0 pin as a Hardware event and this pin must be output
#define TCCR0_COM00                 4

#define TCNT0       ( *( volatile u8 * ) (0x52) )

#define OCR0        ( *( volatile u8 * ) (0x5C) )

#define TIMSK       ( *( volatile u8 * ) (0x59) )
#define TIMSK_TOIE0                 0  // Overflow interrupt is enabled
#define TIMSK_OCIE0                 1  // Compare Match interrupt is enabled

#define TIFR        ( *( volatile u8 * ) (0x58) )
#define TIFR_TOV0                   0  // Overflow interrupt is enabled flag
#define TIFR_OCF0                   1  // Compare Match interrupt is enabled flag

#define PRESCALER_MASK				0b11111000
#define TIM0_PRESCALER_8            2
#define TIM0_PRESCALER_64           3
#define TIM0_PRESCALER_256          4
#define TIM0_PRESCALER_1024         5


#endif /* TIM0_PRIVATE_H_ */
