/***********************************************************************/
/****************   Author   : Shehab Emad Ali   ***********************/
/****************   Layer    : RTOS_STACK	     ***********************/
/****************   Version  : 1.00      	     ***********************/
/****************   SWC      : RTOS              ***********************/
/***********************************************************************/






/*************************************************************************/
/*************************Functions' prototypes***************************/
/*************************************************************************/


void RTOS_voidCreateTask(u16 Copy_u16Periodicity, u8 Copy_u8Priority, void(*Copy_pfTaskFunction)(void),u8 Copy_u8FirstDelay);
void RTOS_voidRunRtos(void);
void RTOS_voidScheduler(void);
void RTOS_voidSuspendTask(u8 Copy_u8Priority);
void Rtos_voidResumeTask(u8 Copy_u8Priority);
void RTOS_voidDeleteTask(u8 Copy_u8Priority);
