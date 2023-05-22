/*****************************************************************************/
/*****************************************************************************/
/******************	   		Author:    Shehab Emad Ali  	******************/
/******************			File Name: EXTI_register.h      ******************/
/******************			Layer:     MCAL     		    ******************/
/******************			Date:      24/3/2023     	    ******************/
/*****************************************************************************/
/*****************************************************************************/

#ifndef EXTI_PRIVATE_H_
#define EXTI_PRIVATE_H_

#define GICR			*((volatile u8*)0x5B )
/*specific interrupt enable*/
#define GICR_INT2		5
#define GICR_INT0		6
#define GICR_INT1		7

#define GIFR			*((volatile u8*)0x5A )
#define GIFR_INTF0		6
#define GIFR_INTF1		7
#define GIFR_INTF2		5

#define MCUCR			*((volatile u8*)0x55 )
#define MCUCR_ISC00		0		//for sense signal for interrupt 0
#define MCUCR_ISC01		1
#define MCUCR_ISC10		2		//for sense signal for interrupt 1
#define MCUCR_ISC11		3


#define MCUCSR			*((volatile u8*)0x54 )
#define MCUCSR_ISC2		6		//for sense signal for interrupt 2


#define  LOW_LEVEL		1
#define  ON_CHANGE		2
#define  FALLING_EDGE	3
#define  RISING_EDGE	4





#endif
