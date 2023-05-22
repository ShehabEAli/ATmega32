/***********************************************************************/
/****************   Author   : Shehab Emad Ali   ***********************/
/****************   File Name: WDT_private.h  ***********************/
/****************   Layer    : MCAL	             ***********************/
/****************   Date     : 5 April 2023      ***********************/
/*Description :This file contains interfacing parameters of GIE module*/
/***********************************************************************/

/*preprocessor header file guard*/
#ifndef WDT_PRIVATE_H_
#define WDT_PRIVATE_H_


/****************************************/
/*********  WDT  Registers   ************/
/****************************************/

#define WDTCR (*(volatile u8*)(0x41))
#define WDP0             0
#define WDP1             1
#define WDP2             2
#define WDE              3
#define WDTOE            4

#endif /* WDT_PRIVATE_H_ */
