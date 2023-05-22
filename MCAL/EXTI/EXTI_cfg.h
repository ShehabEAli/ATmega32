#ifndef EXTI_CONFIF_H_
#define EXTI_CONFIF_H_
/*Options
 	 	 	 * 1- LOW_LEVEL
 	 	 	 * 2- ON_CHANGE
 	 	 	 * 3- FALLING_EDGE
 	 	 	 * 4- RISING_EDGE
 * */
#define INT0_SENSE RISING_EDGE


/*Options
 	 	 	 * 1- LOW_LEVEL
 	 	 	 * 2- ON_CHANGE
 	 	 	 * 3- FALLING_EDGE
 	 	 	 * 4- RISING_EDGE
 * */
#define INT1_SENSE ON_CHANGE

/*Options
 	 	 	 * 1- FALLING_EDGE
 	 	 	 * 2- RISING_EDGE
 * */
#define INT2_SENSE FALLING_EDGE


#define INT_EN  INT0


#endif
