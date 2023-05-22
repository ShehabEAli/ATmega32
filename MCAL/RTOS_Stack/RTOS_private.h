/***********************************************************************/
/****************   Author   : Shehab Emad Ali   ***********************/
/****************   Layer    : RTOS_STACK	     ***********************/
/****************   Version  : 1.00      	     ***********************/
/****************   SWC      : RTOS              ***********************/
/***********************************************************************/
#ifndef RTOS_PRIVATE_H_
#define RTOS_PRIVATE_H_


typedef struct
{
	void(*TaskFunction)(void);
	u16 periodicity;
	u8 TaskState;
	u16 FirstDelay;
}Task_t;

#define SUSPENDED    1
#define RESUMED      0
#endif /* RTOS_PRIVATE_H_ */
