/*
 * App.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Belal
 */

#include "../BSW/Shared library/Types.h"
#include "../BSW/Switch/TACTILE_interface.h"
#include "../BSW/lcd/LCD_Interface.h"
#include "../MCAL/DIO/DIO_interface.h"
#include "../MCAL/EEPROM/EEPROM_interface.h"
#include "../BSW/Shared library/delay.h"
#include "App_private.h"
#include "App_config.h"


const u8 Local_u8ArowPlace[2]={1,2};

void Local_voidDisplay(u8 Copy_u8Temp,u8 Copy_u8Speed);
void app(void);


int main (void){
	DIO_voidInit();
	TACTILE_voidInit();
	LCD_VoidInit();
	EEPROM_voidInit();
	u8 Local_FirstCheck;
	EEPROM_u8ReadByte(FLAG_ADDRESS,&Local_FirstCheck);
	if(Local_FirstCheck==0xFF)
	{
		EEPROM_voidWriteByte(20,TEMP_ADDRESS);
		EEPROM_voidWriteByte(2,SPEED_ADDRESS);
		EEPROM_voidWriteByte(0,FLAG_ADDRESS);
	}
	//LCD_VoidString("sfs");
	while (1){
		 app();
	}

	return 0 ;
}

void app(void)
{
	u8 Local_u8Words[2][9]={"  Temp=","  Speed="};
	//u8 Local_u8Arrow[2]={DASH##SELECT_AROW"};
	u8 Select_SW_State=RELEASE,Up_SW_State=RELEASE,Down_SW_State=RELEASE,Local_u8Check;
	static u8 Local_u8State=DISPLAY;
	static u8 Local_u8ModeToState=TEMP;
	static u8 Local_u8SelectFlag=0;
	static u8 Local_u8Flag=1;
	static u8 Local_u8UpFlag=0;
	static u8 Local_u8DownFlag=0;
	static u8 Local_u8ModeFlag=1;
	static u8 Local_u8SWFlag=0;
	u8 Local_u8Temp;
	u8 Local_u8Speed;
	//static u8 Local_u8UpDownFlag=RELEASE;
	EEPROM_u8ReadByte(TEMP_ADDRESS,&Local_u8Temp);
	EEPROM_u8ReadByte(SPEED_ADDRESS,&Local_u8Speed);
	if(Local_u8Flag==1)
	{
		LCD_VoidGotoxy(0,1);
		LCD_VoidString(Local_u8Words[0]);
		LCD_VoidGotoxy(0,2);
		LCD_VoidString(Local_u8Words[1]);
		Local_u8Flag=0;
	}
	TACTILE_u8GetState(TACTILE_u8Switch1,&Select_SW_State);
	TACTILE_u8GetState(TACTILE_u8Switch2,&Up_SW_State);
	TACTILE_u8GetState(TACTILE_u8Switch3,&Down_SW_State);
	Local_u8Check=(Select_SW_State<<SELECT_BIT)|(Up_SW_State<<UP_BIT)|(Down_SW_State<<DOWN_BIT);
	//DIO_u8WritePortVal(1,Local_u8Check);
	switch(Local_u8State)
	{
	case DISPLAY:
		Local_voidDisplay(Local_u8Temp,Local_u8Speed);
	//	LCD_VoidSendStringxy("         ",0,1);
		switch(Local_u8Check)
		{
		case SELECT_SW_PRESSED:
			LCD_VoidGotoxy(0,1);
			LCD_VoidData(DASH);
			LCD_VoidData(SELECT_AROW);
			LCD_VoidGotoxy(0,2);
			LCD_VoidData(EMPTY);
			LCD_VoidData(EMPTY);
			Local_u8SelectFlag=1;
			break;
		default:
			if(Local_u8SelectFlag==1)
			{
				Local_u8State=MODES;
				Local_u8SelectFlag=0;
			}
			break;
		}
		break;
	case MODES:
		switch(Local_u8Check)
		{
		case SELECT_SW_PRESSED:
			Local_u8ModeFlag=0;
			break;
		case UP_SW_PRESSED:
			Local_u8UpFlag=1;
			break;
		case DOWN_SW_PRESSED:
			Local_u8Flag=1;
			Local_u8State=DISPLAY;
			break;
		default:

			if(Local_u8UpFlag==1)
			{
				Local_u8ModeToState=Local_u8ModeToState^1;
				LCD_VoidGotoxy(0,(Local_u8ArowPlace[Local_u8ModeToState]));
				LCD_VoidData(DASH);
				LCD_VoidData(SELECT_AROW);
				LCD_VoidGotoxy(0,(Local_u8ArowPlace[(Local_u8ModeToState+1)%2]));
				LCD_VoidData(EMPTY);
				LCD_VoidData(EMPTY);
				Local_u8UpFlag=0;
			}
			else{
			}
			if(Local_u8ModeFlag==0)
			{
				Local_u8State=Local_u8ModeToState;
				LCD_VoidSendStringxy("           ",0,Local_u8ArowPlace[Local_u8ModeToState]-1);
				Local_u8ModeFlag=1;
			}
			else{
			}
			break;
		}
		break;
	case TEMP:
		switch(Local_u8Check)
		{
		case SELECT_SW_PRESSED:
			Local_u8SWFlag=1;
			break;
		case UP_SW_PRESSED:
			Local_u8UpFlag=1;
			break;
		case DOWN_SW_PRESSED:
			Local_u8DownFlag=1;
			break;
		default:
			if(Local_u8UpFlag==1)
			{
			if(Local_u8Temp<MAX_TEMP)
			{
				Local_u8Temp++;
				EEPROM_voidWriteByte(Local_u8Temp,TEMP_ADDRESS);
				Local_voidDisplay(Local_u8Temp,EMPTY);
			}
			else{
			}
			Local_u8UpFlag=0;
			}
			if(Local_u8DownFlag==1)
			{
			if(Local_u8Temp>MIN_TEMP)
			{
				Local_u8Temp--;
				EEPROM_voidWriteByte(Local_u8Temp,TEMP_ADDRESS);
				Local_voidDisplay(Local_u8Temp,EMPTY);
			}
			else{
			}

			Local_u8DownFlag=0;
			}

			if(Local_u8SWFlag==1)
			{
				Local_u8State=MODES;
				Local_u8SWFlag=0;
			}
			else{
			}
			break;
		}
		break;
	case SPEED:
		switch(Local_u8Check)
		{
		case SELECT_SW_PRESSED:
			Local_u8SWFlag=1;
			break;
		case UP_SW_PRESSED:
			Local_u8UpFlag=1;
			break;
		case DOWN_SW_PRESSED:
			Local_u8DownFlag=1;
			break;
		default:
			if(Local_u8UpFlag==1)
			{
			if(Local_u8Speed<SPEEDs_NUM)
			{
				Local_u8Speed++;
				EEPROM_voidWriteByte(Local_u8Speed,SPEED_ADDRESS);
				Local_voidDisplay(EMPTY,Local_u8Speed);
			}
			else{
			}
			Local_u8UpFlag=0;
			}
			if(Local_u8DownFlag==1)
			{
			if(Local_u8Speed>0)
			{
				Local_u8Speed--;
				EEPROM_voidWriteByte(Local_u8Speed,SPEED_ADDRESS);
				Local_voidDisplay(EMPTY,Local_u8Speed);
			}
			else{
			}
			Local_u8DownFlag=0;
			}
			if(Local_u8SWFlag==1)
			{
				Local_u8State=MODES;
				Local_u8SWFlag=0;
				Local_u8ModeToState=TEMP;
			}
			else{
			}
			break;
		}
		break;
	default:
		break;
	}
}

void Local_voidDisplay(u8 Copy_u8Temp,u8 Copy_u8Speed)
{
	if(Copy_u8Temp!=EMPTY)
	{
	LCD_VoidGotoxy(8,1);
	LCD_VoidData((u8)(Copy_u8Temp/10)+48);
	LCD_VoidData((u8)(Copy_u8Temp%10)+48);
	}
	if(Copy_u8Speed!=EMPTY)
	{
	LCD_VoidGotoxy(8,2);
	LCD_VoidData(Copy_u8Speed+48);
	}
}

