
#include "STD_TYPES.h"
#include "BIT_MATHS.h"

#include "WDT_cfg.h"
#include "WDT_interface.h"
#include "WDT_private.h"






/******************************************************************************/
/*************************Functions' implementation****************************/
/******************************************************************************/

void WDT_voidEnableWatchDogTimer(u8 Copy_u8Seconds){
	WDTCR=0;
	SET_BIT(WDTCR,3);
	WDTCR|=Copy_u8Seconds;
}
void WDT_voidDisableWatchDogTimer(void){
	WDTCR |=0b00011000;
	WDTCR=0;
}
