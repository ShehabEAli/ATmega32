

#ifndef SSD_INTERFACE_H_
#define SSD_INTERFACE_H_

#define NUMBER_ZERO      0b00111111
#define NUMBER_ONE       0b00000110
#define NUMBER_TWO       0b01011011
#define NUMBER_THREE     0b01001111
#define NUMBER_FOUR      0b01100110
#define NUMBER_FIVE      0b01101101
#define NUMBER_SIX       0b01111101
#define NUMBER_SEVEN     0b00000111
#define NUMBER_EIGHT     0b01111111
#define NUMBER_NINE      0b01101111

#define  COM_Cathode         1
#define  COM_Anode           2
/*************************************************************************************/
/*********************function of seven segment***************************************/
/************************************************************************************/


void SSD_void_Init(u8 Copy_u8PortID,u8 Copy_u8Comport,u8 Copy_u8Compin);
void SSD_voidOn(u8 Copy_u8connection,u8 Copy_u8Comport,u8 Copy_u8Compin);
void SSD_voidDisplay(u8 Copy_u8PortID,u8 Copy_u8connection,u8 Copy_u8number);
void SSD_voidOff(u8 Copy_u8connection,u8 Copy_u8Comport,u8 Copy_u8Compin);

#endif
