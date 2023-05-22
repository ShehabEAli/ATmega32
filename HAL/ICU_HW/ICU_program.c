#include "STD_TYPES.h"
#include "BIT_MATHS.h"

#include "GIE_interface.h"
#include "ICU_cfg.h"
#include "ICU_interface.h"
#include "ICU_private.h"


void (*ICU_PVCallBackptr)(void)=NULL;

void TIMER0_voidRunPWMFastNonInverted(u8 Copy_u8ComVal){

	/*Set Timer0 mode to be FAST PWM*/
	SET_BIT(TCCR0, TCCR0_WGM01);
	SET_BIT(TCCR0, TCCR0_WGM00);

	/*Disconnecting OC0 pin*/
	CLR_BIT(TCCR0, TCCR0_COM00);
	SET_BIT(TCCR0, TCCR0_COM01);

	/*Setting compare match value to be 250*/
	OCR0 = Copy_u8ComVal;

	/*Setting prescaler*/
	TCCR0 &= PRESCALER_MASK;
	TCCR0 |= TIM0_PRESCALER_8;

}

void Timer1_voidRunNormalMode(void){
	/* By Default Timer1 ON Normal Mode */
	/*ICU Initially in rising edge*/
	SET_BIT(TCCR1B,ICES1);

	/*ICU Interrupt Enable*/
	SET_BIT(TIMSK,TICIE1);

	/* Set Prescaler -> 8*/
	TCCR1B &= PRESCALER_MASK ;
	TCCR1B |= TIM1_PRESCALER_8;
}

u16 Timer1_u16GETInputCaptureReading(void){
	return ICR1;
}

void Timer1_voidDisableICUInterrupt(void){
	CLR_BIT(TIMSK,TICIE1);
}
void Timer1_voidChangeICUEdge(u8 Copy_u8Edge){
	if(ICU_RISING_EDGE==Copy_u8Edge){
		SET_BIT(TCCR1B,ICES1);
	}
	else if(ICU_FALLING_EDGE==Copy_u8Edge){
		CLR_BIT(TCCR1B,ICES1);
	}
}
void Timer1_voidICUSetCallBack(void(*Copy_pvCallBackFunc)(void)){
	if(Copy_pvCallBackFunc!=NULL){
		ICU_PVCallBackptr=Copy_pvCallBackFunc;
	}
}

void __vector_6 (void) __attribute__((signal));
void __vector_6 (void){
	if(ICU_PVCallBackptr!=NULL){
			ICU_PVCallBackptr();
		}
}
