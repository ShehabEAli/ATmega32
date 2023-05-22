#include "STD_TYPES.h"
#include "BIT_MATHS.h"

#include "GIE_interface.h"
#include "ICU_cfg.h"
#include "ICU_interface.h"
#include "ICU_private.h"


void (*Global_pfCTCCallBack)(void)=NULL;

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

	/* Set Prescaler -> 8*/
	TCCR1B &= PRESCALER_MASK ;
	TCCR1B |= TIM1_PRESCALER_8;
}
void Timer1_voidClear(void){
	TCNT1=0;
}

u16 Timer1_u16GETReading(void){
	return TCNT1;
}
