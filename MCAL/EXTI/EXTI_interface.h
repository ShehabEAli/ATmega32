/*****************************************************************************/
/*****************************************************************************/
/******************	   		Author:    Shehab Emad Ali	   	******************/
/******************			File Name: EXTI_interface.h     ******************/
/******************			Layer:     MCAL     		    ******************/
/******************			Date:      24/3/2023     	    ******************/
/*****************************************************************************/
/*****************************************************************************/

#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_


#define INT0_LOW_LEVEL			1
#define INT0_ON_CHANGE   	    2
#define INT0_FALLING_EDGE     	3
#define INT0_RISING_EDGE     	4

#define INT1_LOW_LEVEL			1
#define INT1_ON_CHANGE   	    2
#define INT1_FALLING_EDGE     	3
#define INT1_RISING_EDGE     	4

#define INT2_FALLING_EDGE     	1
#define INT2_RISING_EDGE     	2

#define INT0					1
#define INT1					2
#define INT2					3






/*runtime build function for initialization the int0*/
void EXTI_voidInt0SetSenseControl(u8 Copy_u8MCUCR_ISR);

/*runtime build function for initialization the int1*/
void EXTI_voidInt1SetSenseControl(u8 Copy_u8MCUCR_ISR);

/*runtime build function for initialization the int2*/
void EXTI_voidInt2SetSenseControl(u8 Copy_u8MCUCR_ISR);

void EXTI_voidIntEnable(u8 Copy_u8Sense);

void EXTI_voidIntDisable(u8 Copy_u8Sense);

void EXTI_voidInt0Init(void);

void EXTI_voidInt1Init(void);

void EXTI_voidInt2Init(void);

void EXTI_voidInt0SetCallBack(void(*Copy_PtrToFunc)(void));

void EXTI_voidInt1SetCallBack(void(*Copy_PtrToFunc)(void));

void EXTI_voidInt2SetCallBack(void(*Copy_PtrToFunc)(void));


#endif

