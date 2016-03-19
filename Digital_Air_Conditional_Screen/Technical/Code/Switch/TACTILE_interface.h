/*
 * TACTILE_interface.h
 *
 *  Created on: Feb 25, 2016
 *      Author: 7ossam
 */

#ifndef TACTILE_INTERFACE_H_
#define TACTILE_INTERFACE_H_

/***********************************************************/
/******************Public Definitions***********************/
/***********************************************************/

/*Comment!: Switch States  */
#define TACTILE_u8RELEASED 		0
#define TACTILE_u8PRESSED 		1




/*Comment!: Switch Index values  */
#define TACTILE_u8Switch1	0
#define TACTILE_u8Switch2	1
#define TACTILE_u8Switch3	2
#define TACTILE_u8Switch4	3
#define TACTILE_u8Switch5	4
#define TACTILE_u8Switch6	5
#define TACTILE_u8Switch7	6
#define TACTILE_u8Switch8	7
#define TACTILE_u8Switch9	8
#define TACTILE_u8Switch10	9
#define TACTILE_u8Switch11	10
#define TACTILE_u8Switch12	11
#define TACTILE_u8Switch13	12
#define TACTILE_u8Switch14	13
#define TACTILE_u8Switch15	14
#define TACTILE_u8Switch16	15
#define TACTILE_u8Switch17	16
#define TACTILE_u8Switch18	17
#define TACTILE_u8Switch19	18
#define TACTILE_u8Switch20	19
#define TACTILE_u8Switch21	20
#define TACTILE_u8Switch22	21
#define TACTILE_u8Switch23	22
#define TACTILE_u8Switch24	23
#define TACTILE_u8Switch25	24
#define TACTILE_u8Switch26	25
#define TACTILE_u8Switch27	26
#define TACTILE_u8Switch28	27
#define TACTILE_u8Switch29	28
#define TACTILE_u8Switch30	29
#define TACTILE_u8Switch31	30
#define TACTILE_u8Switch32	31




/***********************************************************/
/******************Public Functions*************************/
/***********************************************************/

/*Comment!: Initialization function */
extern void TACTILE_voidInit(void);
/*Comment!: Get Tactile State */
extern u8 TACTILE_u8GetState(u8 Copy_u8SwitchNumber, u8* Copy_u8PtrToVal);


#endif /* TACTILE_INTERFACE_H_ */
