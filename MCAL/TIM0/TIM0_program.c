#include "STD_TYPES.h"
#include "BIT_MATHS.h"

#include "TIM0_interface.h"
#include "GIE_interface.h"
#include "TIM0_cfg.h"
#include "TIM0_private.h"


void (*Global_pfCTCCallBack)(void)=NULL;

void TIMR0_voidRunTimer0CTCAsync(void(*Copy_pfCompareMatchInterrupt)(void))
{
	/*Set Timer0 mode to be CTC*/
	SET_BIT(TCCR0, TCCR0_WGM01);
	CLR_BIT(TCCR0, TCCR0_WGM00);

	/*Disconnecting OC0 pin*/
	CLR_BIT(TCCR0, TCCR0_COM00);
	CLR_BIT(TCCR0, TCCR0_COM01);

	/*Setting compare match value to be 250*/
	OCR0 = 31;

	/*Enable compare match interrupt*/
	SET_BIT(TIMSK,TIMSK_OCIE0);
	/*Enable Global interrupt*/
	GIE_voidEnableGlobalInterrupt();


	if(Copy_pfCompareMatchInterrupt != NULL){
	Global_pfCTCCallBack = Copy_pfCompareMatchInterrupt;
	}
	/*Setting prescaler*/
	TCCR0 &= PRESCALER_MASK;
	TCCR0 |= TIM0_PRESCALER_8;

}

void __vector_10(void) __attribute__((signal));
void __vector_10(void)
{
	if (Global_pfCTCCallBack != NULL)
	{
		Global_pfCTCCallBack();
	}
	else
	{
		/*Do nothing*/
	}
}

