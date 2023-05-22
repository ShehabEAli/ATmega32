#include "STD_TYPES.h"
#include "BIT_MATHS.h"

#include "GIE_interface.h"
#include "TIM0_interface.h"

#include "RTOS_cfg.h"
#include "RTOS_interface.h"
#include "RTOS_private.h"



Task_t RTOS_taskArray[NUM_OF_TASKS]={{NULL}};



void RTOS_voidCreateTask(u16 Copy_u16Periodicity, u8 Copy_u8Priority, void(*Copy_pfTaskFunction)(void),u8 Copy_u8FirstDelay){
	if(RTOS_taskArray[Copy_u8Priority].TaskFunction==NULL)
	{
		RTOS_taskArray[Copy_u8Priority].periodicity=Copy_u16Periodicity;
		RTOS_taskArray[Copy_u8Priority].TaskFunction=Copy_pfTaskFunction;
		RTOS_taskArray[Copy_u8Priority].TaskState=RESUMED;
		RTOS_taskArray[Copy_u8Priority].FirstDelay=Copy_u8FirstDelay;
	}
	else
	{
		/*Do Nothing*/
	}
}
void RTOS_voidRunRtos(void){

	/*Enable Global Interrupt*/
	GIE_voidEnableGlobalInterrupt();

	/*Call Timer0 to generate an interrupt every 1msec*/
	TIMR0_voidRunTimer0CTCAsync(RTOS_voidScheduler);

}
void RTOS_voidScheduler(void){

	u8 Local_u8iterator=0;
	/*Looping over task*/
	for(Local_u8iterator=0; Local_u8iterator<NUM_OF_TASKS;Local_u8iterator++)
	{
		// check if the task is not Suspended
		if(RTOS_taskArray[Local_u8iterator].TaskState==RESUMED)
		{
			if(RTOS_taskArray[Local_u8iterator].FirstDelay==0)
			{
				//Check if Pointer not equal NUll
				if(RTOS_taskArray[Local_u8iterator].TaskFunction!=NULL)
				{
					/*Calling the task function*/
					RTOS_taskArray[Local_u8iterator].TaskFunction();
					RTOS_taskArray[Local_u8iterator].FirstDelay=RTOS_taskArray[Local_u8iterator].periodicity-1;
				}
			}
			else
			{
				RTOS_taskArray[Local_u8iterator].FirstDelay--;
			}
		}
		else
		{
			/*Task is suspended Do Nothing*/
		}
	}
}

void RTOS_voidSuspendTask(u8 Copy_u8Priority){
	RTOS_taskArray[Copy_u8Priority].TaskState=SUSPENDED;
}
void Rtos_voidResumeTask(u8 Copy_u8Priority){
	RTOS_taskArray[Copy_u8Priority].TaskState=RESUMED;
}

void RTOS_voidDeleteTask(u8 Copy_u8Priority){
	RTOS_taskArray[Copy_u8Priority].TaskFunction=NULL;
}
