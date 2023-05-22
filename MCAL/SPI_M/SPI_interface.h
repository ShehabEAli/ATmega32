/**********************************************************/
/*           Author  : Shehab Emad                        */
/*           Layer   : MCAL                               */
/*           Version : 1.00                               */
/*           SWC     : SPI		                          */
/**********************************************************/

/*preprocessor header file guard*/
#ifndef SPI_INTERFACE_H_
#define SPI_INTERFACE_H_


/*****************************************************************************************/
/**********************************Interfacing macros*************************************/
/*****************************************************************************************/


/*****************************************************************************************/
/*********************************Functions' prototype************************************/
/*****************************************************************************************/

/*This function shall initialize the master in the network*/
void SPI_voidMasterInit(void);

/*This function shall initialize the slave in the network*/
void SPI_voidSlaveInit(void);

/*This function shall shift a transmitted byte and receive a byte from the slave*/
u8 SPI_u8Transceive(u8 Copy_u8TransmittedByte);




#endif /* SPI_INTERFACE_H_ */
