/*
 * TACTILE_prog.c
 *
 *  Created on: Feb 25, 2016
 *      Author: 7ossam
 */


#include "../Shared library/Conc.h"
#include "../Shared library/util.h"
#include "../Shared library/Types.h"

#include "../../MCAL/DIO/DIO_config.h"
#include "../../MCAL/DIO/DIO_private.h"
#include "../../MCAL/DIO/DIO_interface.h"

#include "TACTILE_config.h"
#include "TACTILE_private.h"
#include "TACTILE_interface.h"


/*Comment!: Initialization function */
extern void TACTILE_voidInit(void)
{

}

const u8 TACTILE_u8TactilePins[TACTILE_u8MAXNUM]=	{TACTILE_u8Switch1Pin ,TACTILE_u8Switch2Pin ,TACTILE_u8Switch3Pin ,TACTILE_u8Switch4Pin
													,TACTILE_u8Switch5Pin ,TACTILE_u8Switch6Pin ,TACTILE_u8Switch7Pin ,TACTILE_u8Switch8Pin
													,TACTILE_u8Switch9Pin ,TACTILE_u8Switch10Pin,TACTILE_u8Switch11Pin,TACTILE_u8Switch12Pin
													,TACTILE_u8Switch13Pin,TACTILE_u8Switch14Pin,TACTILE_u8Switch15Pin,TACTILE_u8Switch16Pin};

const u8 TACTILE_u8TactileType[TACTILE_u8MAXNUM]=	{TACTILE_u8Switch1Type ,TACTILE_u8Switch2Type ,TACTILE_u8Switch3Type ,TACTILE_u8Switch4Type
													,TACTILE_u8Switch5Type ,TACTILE_u8Switch6Type ,TACTILE_u8Switch7Type ,TACTILE_u8Switch8Type
													,TACTILE_u8Switch9Type ,TACTILE_u8Switch10Type,TACTILE_u8Switch11Type,TACTILE_u8Switch12Type
													,TACTILE_u8Switch13Type,TACTILE_u8Switch14Type,TACTILE_u8Switch15Type,TACTILE_u8Switch16Type};

/*Comment!: Get Tactile State */
extern u8 TACTILE_u8GetState(u8 Copy_u8SwitchNumber, u8* Copy_u8PtrToVal)
{
	u8 Local_u8Error=OK;
	u8 Local_u8TactileVal;
//	u8 TACTILE_u8=TACTILE_u8TactileType[Copy_u8SwitchNumber];
	static u8 TACTILE_u8State[TACTILE_u8SWITCHNUM]		=	{TACTILE_u8RELEASED};
	static u8 TACTILE_u8CounterUp[TACTILE_u8SWITCHNUM]	= 	{u8ZERO};
	static u8 TACTILE_u8CounterDown[TACTILE_u8SWITCHNUM]= 	{u8ZERO};
	static u8 TACTILE_u8TactileVal[TACTILE_u8SWITCHNUM]= 	{TACTILE_u8RELEASED};
	if(Copy_u8SwitchNumber > TACTILE_u8MAXNUM)
	{
		Local_u8Error=ERROR;
	}
	else{
		DIO_u8ReadPinVal(TACTILE_u8TactilePins[Copy_u8SwitchNumber],&Local_u8TactileVal);
		switch(TACTILE_u8State[Copy_u8SwitchNumber])
		{
		case TACTILE_u8RELEASED:
			if(Local_u8TactileVal==TACTILE_u8TactileType[Copy_u8SwitchNumber])
			{
				TACTILE_u8State[Copy_u8SwitchNumber]=TACTILE_u8BOUNCING;
				TACTILE_u8CounterDown[Copy_u8SwitchNumber]=u8ZERO;
            }
			else if (Local_u8TactileVal!=TACTILE_u8TactileType[Copy_u8SwitchNumber])
            {
				TACTILE_u8TactileVal[Copy_u8SwitchNumber]=TACTILE_u8RELEASED;
			}
			else{
			}
			*Copy_u8PtrToVal=TACTILE_u8TactileVal[Copy_u8SwitchNumber];
			break;
		case TACTILE_u8BOUNCING:
			if(Local_u8TactileVal==TACTILE_u8TactileType[Copy_u8SwitchNumber])
			{
				TACTILE_u8CounterUp[Copy_u8SwitchNumber]++;
				TACTILE_u8CounterDown[Copy_u8SwitchNumber]=u8ZERO;
			}
			else if (Local_u8TactileVal!=TACTILE_u8TactileType[Copy_u8SwitchNumber])
            {
                TACTILE_u8CounterDown[Copy_u8SwitchNumber]++;
				TACTILE_u8CounterUp[Copy_u8SwitchNumber]=u8ZERO;
			}
			else{
			}
			if(TACTILE_u8CounterUp[Copy_u8SwitchNumber]>=TACTILE_u8MAXCOUNT)
			{
				TACTILE_u8State[Copy_u8SwitchNumber]=TACTILE_u8PRESSED;
			}
			else{
			}
			if(TACTILE_u8CounterDown[Copy_u8SwitchNumber]>=TACTILE_u8MAXCOUNT)
			{
				TACTILE_u8State[Copy_u8SwitchNumber]=TACTILE_u8RELEASED;
			}
			else{
			}
			break;
		case TACTILE_u8PRESSED:
			if (Local_u8TactileVal!=TACTILE_u8TactileType[Copy_u8SwitchNumber])
            {
				TACTILE_u8CounterUp[Copy_u8SwitchNumber]=u8ZERO;
				TACTILE_u8State[Copy_u8SwitchNumber]=TACTILE_u8BOUNCING;
			}
			else if (Local_u8TactileVal==TACTILE_u8TactileType[Copy_u8SwitchNumber])
            {
                TACTILE_u8TactileVal[Copy_u8SwitchNumber]=TACTILE_u8PRESSED;
			}
			else{
			}
			*Copy_u8PtrToVal=TACTILE_u8TactileVal[Copy_u8SwitchNumber];
			break;
		default:
			break;
		}
	}

	return Local_u8Error;
}
