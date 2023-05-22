


#define PB_PULL_UP       1
#define PB_PULL_DOWN     2

#define PB_PU_RELEASED   1
#define PB_PU_PRESSED    2

#define PB_PD_RELEASED   3
#define PB_PD_PRESSED    4




/*************************************************************************/
/*************************Functions' prototypes***************************/
/*************************************************************************/
u8 PB_void_Init(u8 Copy_u8PBPortID,u8 Copy_u8PBPin,u8 Copy_PBConnection);
u8 PB_u8_GetState(u8 Copy_u8PBPortID,u8 Copy_u8PBPin,u8 Copy_PBConnection);
