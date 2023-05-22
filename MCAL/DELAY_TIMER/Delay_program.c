#include "STD_TYPES.h"
#include "BIT_MATHS.h"
#include <util\delay.h>

#include "Delay_cfg.h"
#include "Delay_interface.h"
#include "Delay_private.h"


void(* Global_ptfvoid )(void)=NULL;
void Delay_voidSetDelaySync(u16 Copy_u16TimeInMilliSec){

	/*setting timer1 to be ctc*/
	CLR_BIT(TCCR1A, WGM10);
	CLR_BIT(TCCR1A, WGM11);
	SET_BIT(TCCR1B, WGM12);
	CLR_BIT(TCCR1B, WGM13);

	/*setting timer1 to be normal*/
	CLR_BIT(TCCR1A, COM_A0);
	CLR_BIT(TCCR1A, COM_A1);
	CLR_BIT(TCCR1A, COM_B0);
	CLR_BIT(TCCR1A, COM_B1);

	/*setting compare match value*/
	OCR1A = ((Copy_u16TimeInMilliSec* 125UL) / 16UL);

	/*setting prescaler to the max*/
	TCCR1B &= PRESCALER_MASK;
	TCCR1B |= PRESCALER_1024;

	/*checking if the flag raised or not*/
	while((GET_BIT(TIFR, OCF1A)) == 0);
	SET_BIT(TIFR, OCF1A);
}
void Delay_voidSetDelayASync(u16 Copy_u16TimeInMilliSec,void(* Copy_ptvoidfCallBack )(void)){
	/*setting timer1 to be ctc*/
	CLR_BIT(TCCR1A, WGM10);
	CLR_BIT(TCCR1A, WGM11);
	SET_BIT(TCCR1B, WGM12);
	CLR_BIT(TCCR1B, WGM13);

	/*setting timer1 to be normal*/
	CLR_BIT(TCCR1A, COM_A0);
	CLR_BIT(TCCR1A, COM_A1);
	CLR_BIT(TCCR1A, COM_B0);
	CLR_BIT(TCCR1A, COM_B1);


	OCR1A=((Copy_u16TimeInMilliSec * 125UL) / 16UL);
	//set prescaler
	TCCR1B &=PRESCALER_MASK;
	TCCR1B |=PRESCALER_1024;

	/*enable interrupt*/
	SET_BIT(TIMSK, OCIE1A);

	if(Copy_ptvoidfCallBack != NULL)
	{
		Global_ptfvoid=Copy_ptvoidfCallBack;
	}
}

void __vector_7(void)__attribute__((signal));
void __vector_7(void)
{
	if(Global_ptfvoid != NULL)
	{
		Global_ptfvoid();
	}

}
