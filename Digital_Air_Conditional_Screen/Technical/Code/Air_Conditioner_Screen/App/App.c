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

//#define TURNOFF		0
#define DISPLAY		3
#define MODES		2
#define TEMP		0
#define SPEED		1

#define UP_SW_PRESSED			2
#define DOWN_SW_PRESSED			1
#define SELECT_SW_PRESSED		4
//#define ESC_SW_PRESSED			8

#define DOWN_BIT		0
#define UP_BIT			1
#define SELECT_BIT		2
#define ESC_BIT			3

#define PRESSED			1
#define RELEASE			0

#define SELECT_AROW		0x3E
#define DASH			0x2D
#define EMPTY			0x20

#define TEMP_ADDRESS	0x5F
#define SPEED_ADDRESS	0x4F

void Local_voidDisplay(u8 Copy_u8Temp,u8 Copy_u8Speed);
void app(void);


int main (void){
	DIO_voidInit();
	TACTILE_voidInit();
	LCD_VoidInit();
	EEPROM_voidInit();
	//LCD_VoidData('A');
	EEPROM_voidWriteByte(20,TEMP_ADDRESS);
	EEPROM_voidWriteByte(2,SPEED_ADDRESS);
	//LCD_VoidString("sfs");
	while (1){
		 app();
	}

	return 0 ;
}

void app(void)
{
	u8 Local_u8Words[2][7]={"Temp=","Speed="};
	//u8 Local_u8Arrow[2]={DASH##SELECT_AROW"};
	u8 Select_SW_State=RELEASE,Up_SW_State=RELEASE,Down_SW_State=RELEASE,Local_u8Check;
	static u8 Local_u8State=DISPLAY;
	static u8 Local_u8ModeToState=TEMP;
	static u8 Local_u8SelectFlag=0;
	static u8 Local_u8Flag=1;
	static u8 Local_u8ModeFlag=1;
	//static u8 Local_u8UpDownFlag=RELEASE;
	u8 Local_u8Temp=EEPROM_u8ReadByte(TEMP_ADDRESS);
	u8 Local_u8Speed=EEPROM_u8ReadByte(SPEED_ADDRESS);
	if(Local_u8Flag==1)
	{
		LCD_VoidGotoxy(2,1);
		LCD_VoidString(Local_u8Words[0]);
		LCD_VoidGotoxy(2,2);
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
		switch(Local_u8Check)
		{
		case SELECT_SW_PRESSED:
			//LCD_VoidClearScreen();
			LCD_VoidGotoxy(0,1);
			LCD_VoidData(DASH);
			LCD_VoidData(SELECT_AROW);
			//LCD_VoidString(Local_u8Words[0]);
			LCD_VoidGotoxy(0,2);
			LCD_VoidData(EMPTY);
			LCD_VoidData(EMPTY);
			Local_u8SelectFlag=1;
			//LCD_VoidString(Local_u8Words[1]);
			//Local_u8State=MODES;
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
			//LCD_VoidClearScreen();
			Local_u8State=0;
			break;
		case UP_SW_PRESSED:
//			if(Local_u8Flag==0)
//			{
			Local_u8ModeToState=Local_u8ModeToState^1;
//				LCD_VoidGotoxy(0,(Local_u8ModeFlag+1)%3);
//				LCD_VoidData(DASH);
//				LCD_VoidData(SELECT_AROW);
//				LCD_VoidGotoxy(0,(Local_u8ModeFlag+1)%3);
//				LCD_VoidData(EMPTY);
//				LCD_VoidData(EMPTY);
//			}
			break;
		case DOWN_SW_PRESSED:
			LCD_VoidClearScreen();
			Local_u8Flag=1;
			Local_u8State=DISPLAY;
			break;
		default:
			LCD_VoidGotoxy(0,(Local_u8ModeToState+1)%3);
			LCD_VoidData(DASH);
			LCD_VoidData(SELECT_AROW);
			LCD_VoidGotoxy(0,(Local_u8ModeToState+1)%3);
			LCD_VoidData(EMPTY);
			LCD_VoidData(EMPTY);
			if(Local_u8ModeFlag==0)
			{
				Local_u8State=Local_u8ModeToState;
			}
			break;
		}
		break;
	case TEMP:
		switch(Local_u8Check)
		{
		case SELECT_SW_PRESSED:
			//LCD_VoidClearScreen();
			Local_u8State=MODES;
			break;
		case UP_SW_PRESSED:
			if(Local_u8Temp<=30)
			{
				Local_u8Temp++;
				EEPROM_voidWriteByte(Local_u8Temp,TEMP_ADDRESS);
				LCD_VoidClearScreen();
				Local_voidDisplay(Local_u8Temp,0x51);
			}
			else{

			}
			break;
		case DOWN_SW_PRESSED:
			if(Local_u8Temp>=16)
			{
				Local_u8Temp--;
				EEPROM_voidWriteByte(Local_u8Temp,TEMP_ADDRESS);
				LCD_VoidClearScreen();
				Local_voidDisplay(Local_u8Temp,0x51);
				//
			}
			else{

			}
			break;
		default:
			break;
		}
		break;
	case SPEED:
		switch(Local_u8Check)
		{
		case SELECT_SW_PRESSED:
			LCD_VoidInit();
			Local_u8State=MODES;
			break;
		case UP_SW_PRESSED:
			if(Local_u8Speed<=6)
			{
				Local_u8Speed++;
				LCD_VoidClearScreen();
				EEPROM_voidWriteByte(Local_u8Speed,SPEED_ADDRESS);
				Local_voidDisplay(0x51,Local_u8Speed);
								//
			}
			else{

			}
			break;
		case DOWN_SW_PRESSED:
			if(Local_u8Speed>0)
			{
				Local_u8Speed--;
				LCD_VoidClearScreen();
				EEPROM_voidWriteByte(Local_u8Speed,SPEED_ADDRESS);
				Local_voidDisplay(0x51,Local_u8Speed);
										//
			}
			else{

			}
			break;
		default:
			break;
		}
		break;
	default:
		break;
	}
}

void Local_voidDisplay(u8 Copy_u8Temp,u8 Copy_u8Speed)
{
	LCD_VoidGotoxy(8,1);
	LCD_VoidData((u8)(Copy_u8Temp/10)+48);
	LCD_VoidData((u8)(Copy_u8Temp%10)+48);
	LCD_VoidGotoxy(8,2);
	LCD_VoidData(Copy_u8Speed+48);

}

