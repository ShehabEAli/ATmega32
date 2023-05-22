/*****************************************************************************/
/*****************************************************************************/
/******************	   		Author:    Shehab Emad Ali	    ******************/
/******************			File Name: EXTI_program.c       ******************/
/******************			Layer:     MCAL     		    ******************/
/******************			Date:      24/3/2023     	    ******************/
/*****************************************************************************/
/*****************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATHS.h"

#include "DIO_interface.h"
#include "EXTI_interface.h"
#include "EXTI_cfg.h"
#include "EXTI_private.h"

/*Global Pointer to function*/
void (*EXTI_Int0PtrToFunc)(void) = NULL;
void (*EXTI_Int1PtrToFunc)(void) = NULL;
void (*EXTI_Int2PtrToFunc)(void) = NULL;

void EXTI_voidInt0SetSenseControl(u8 Copy_u8MCUCR_ISR)
{
	switch (Copy_u8MCUCR_ISR)
	{
	case  INT0_LOW_LEVEL:
		/*Set sense control for INT0 to be low level*/
		CLR_BIT(MCUCR, MCUCR_ISC01);
		CLR_BIT(MCUCR, MCUCR_ISC00);


		break;

	case INT0_ON_CHANGE:

		/*Set sense control for INT0 to be on change*/
		CLR_BIT(MCUCR, MCUCR_ISC01);
		SET_BIT(MCUCR, MCUCR_ISC00);


		break;

	case INT0_FALLING_EDGE:

		/*Set sense control for INT0 to be falling edge*/
		SET_BIT(MCUCR, MCUCR_ISC01);
		CLR_BIT(MCUCR, MCUCR_ISC00);


		break;

	case INT0_RISING_EDGE:

		/*Set sense control for INT0 to be rising edge*/
		SET_BIT(MCUCR, MCUCR_ISC01);
		SET_BIT(MCUCR, MCUCR_ISC00);


		break;
	}
}



void EXTI_voidInt1SetSenseControl(u8 Copy_u8MCUCR_ISR)
{
	switch (Copy_u8MCUCR_ISR)
	{
	case INT1_LOW_LEVEL:
		/*Set sense control for INT1 to be low level*/
		CLR_BIT(MCUCR, MCUCR_ISC01);
		CLR_BIT(MCUCR, MCUCR_ISC00);


		break;

	case INT1_ON_CHANGE:

		/*Set sense control for INT1 to be on change*/
		CLR_BIT(MCUCR, MCUCR_ISC01);
		SET_BIT(MCUCR, MCUCR_ISC00);


		break;
	case INT1_FALLING_EDGE:

		/*Set sense control for INT1 to be falling edge */
		SET_BIT(MCUCR, MCUCR_ISC01);
		CLR_BIT(MCUCR, MCUCR_ISC00);


		break;
	case INT1_RISING_EDGE:

		/*Set sense control for INT1 to be rising edge*/
		SET_BIT(MCUCR, MCUCR_ISC01);
		SET_BIT(MCUCR, MCUCR_ISC00);


		break;
	}
}



void EXTI_voidInt2SetSenseControl(u8 Copy_u8MCUCR_ISR)
{
	switch (Copy_u8MCUCR_ISR)
	{
	case INT2_RISING_EDGE:
		/*Set sense control for INT2 to be rising edge*/
		SET_BIT(MCUCSR, MCUCSR_ISC2);


		break;

	case INT2_FALLING_EDGE:

		/*Set sense control for INT2 to be falling edge*/
		CLR_BIT(MCUCSR, MCUCSR_ISC2);


		break;
	}

}
void EXTI_voidIntEnable(u8 Copy_u8Sense)
{
	if (Copy_u8Sense == INT0)
	{
		SET_BIT(GICR, GICR_INT0);
	}
	else if( Copy_u8Sense == INT1)
	{
		SET_BIT(GICR, GICR_INT1);
	}
	else if( Copy_u8Sense == INT2)
	{
		SET_BIT(GICR, GICR_INT2);
	}

}

void EXTI_voidIntDisable(u8 Copy_u8Sense)
{
	if (Copy_u8Sense == INT0)
	{
		CLR_BIT(GICR, GICR_INT0);
	}
	else if( Copy_u8Sense == INT1)
	{
		CLR_BIT(GICR, GICR_INT1);
	}
	else if( Copy_u8Sense == INT2)
	{
		CLR_BIT(GICR, GICR_INT2);
	}

}

void EXTI_voidInt0Init(void)
{
	/*check sense control*/
#if INT0_SENSE == LOW_LEVEL
	CLR_BIT(MCUCR, MCUCR_ISC01);
	CLR_BIT(MCUCR, MCUCR_ISC00);


#elif INT0_SENSE == ON_CHANGE
	CLR_BIT(MCUCR, MCUCR_ISC01);
	SET_BIT(MCUCR, MCUCR_ISC00);


#elif INT0_SENSE == FALLING_EDGE
	SET_BIT(MCUCR, MCUCR_ISC01);
	CLR_BIT(MCUCR, MCUCR_ISC00);

#elif INT0_SENSE == RISING_EDGE
	SET_BIT(MCUCR, MCUCR_ISC01);
	SET_BIT(MCUCR, MCUCR_ISC00);

#endif
	SET_BIT(GICR, GICR_INT0);

}

void EXTI_voidInt1Init(void)
{
#if INT1_SENSE == LOW_LEVEL
	CLR_BIT(MCUCR, MCUCR_ISC11);
	CLR_BIT(MCUCR, MCUCR_ISC10);


#elif INT1_SENSE == ON_CHANGE
	CLR_BIT(MCUCR, MCUCR_ISC11);
	SET_BIT(MCUCR, MCUCR_ISC10);

#elif INT1_SENSE == FALLING_EDGE
	SET_BIT(MCUCR, MCUCR_ISC11);
	CLR_BIT(MCUCR, MCUCR_ISC10);


#elif INT1_SENSE == RISING_EDGE
	SET_BIT(MCUCR, MCUCR_ISC11);
	SET_BIT(MCUCR, MCUCR_ISC10);

#endif
	SET_BIT(GICR, GICR_INT1);

}

void EXTI_voidInt2Init(void)
{
#if INT2_SENSE == FALLING_EDGE
	SET_BIT(MCUCSR, MCUCR_ISC11);



#elif IN2_SENSE == RISING_EDGE
	CLR_BIT(MCUCSR, MCUCR_ISC11);


#endif
	SET_BIT(GICR, GICR_INT2);

}

void EXTI_voidInt0SetCallBack(void(*Copy_PtrToFunc)(void))
{
	if (Copy_PtrToFunc != NULL)
	{
		EXTI_Int0PtrToFunc = Copy_PtrToFunc;
	}
	else
	{

	}
}

void EXTI_voidInt1SetCallBack(void(*Copy_PtrToFunc)(void))
{
	if (Copy_PtrToFunc != NULL)
	{
		EXTI_Int1PtrToFunc = Copy_PtrToFunc;
	}
	else
	{

	}
}

void EXTI_voidInt2SetCallBack(void(*Copy_PtrToFunc)(void))
{
	if (Copy_PtrToFunc != NULL)
	{
		EXTI_Int2PtrToFunc = Copy_PtrToFunc;
	}
	else
	{

	}
}




void __vector_1(void) __attribute__((signal));
void __vector_1(void)
{
	if (EXTI_Int0PtrToFunc != NULL)
	{
		EXTI_Int0PtrToFunc();
	}
	else
	{

	}
}

void __vector_2(void) __attribute__((signal));
void __vector_2(void)
{
	if (EXTI_Int1PtrToFunc != NULL)
	{
		EXTI_Int1PtrToFunc();
	}
	else
	{

	}
}

void __vector_3(void) __attribute__((signal));
void __vector_3(void)
{
	if (EXTI_Int2PtrToFunc != NULL)
	{
		EXTI_Int2PtrToFunc();
	}
	else
	{

	}
}
