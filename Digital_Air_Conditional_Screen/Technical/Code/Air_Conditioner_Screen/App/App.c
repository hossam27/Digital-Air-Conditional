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

//#define TURNOFF		0
#define DISPLAY		1
#define MODES		2
#define TEMP		3
#define SPEED		4

#define UP_SW_PRESSED			2
#define DOWN_SW_PRESSED			1
#define SELECT_SW_PRESSED		4
//#define ESC_SW_PRESSED			8

#define DOWN_BIT		0
#define UP_BIT			1
#define SELECT_BIT		2
#define ESC_BIT			3

#define TEMP_ADDRESS	0x5F
#define SPEED_ADDRESS	0x4F


int main (void){
	DIO_voidInit();
	TACTILE_voidInit();
	LCD_VoidInit();
	EEPROM_voidInit();
	while (1){

	}

	return 0 ;
}

void app(void)
{
	u8 Select_SW_State,ESC_SW_State,Up_SW_State,Down_SW_State,Local_u8Check;
	static u8 Local_u8State=DISPLAY;
	static u8 Local_u8Temp=EEPROM_u8ReadByte(TEMP_ADDRESS);
	static u8 Local_u8Speed=EEPROM_u8ReadByte(SPEED_ADDRESS);
	LCD_VoidRowString(1,"Temp= ");
	LCD_VoidRowString(2,"Speed= ");
	TACTILE_u8GetState(TACTILE_u8Switch1,&Select_SW_State);
	//TACTILE_u8GetState(TACTILE_u8Switch2,&ESC_SW_State);
	TACTILE_u8GetState(TACTILE_u8Switch3,&Up_SW_State);
	TACTILE_u8GetState(TACTILE_u8Switch4,&Down_SW_State);
	Local_u8Check=(Select_SW_State<<SELECT_BIT)|(Up_SW_State<<UP_BIT)|(Down_SW_State<<DOWN_BIT);
	switch(Local_u8State)
	{
	case DISPLAY:
		LCD_VoidGotoxy(7,1);
		LCD_VoidString();
		LCD_VoidGotoxy(7,2);
		LCD_VoidString();
		switch(Local_u8Check)
		{
		case SELECT_SW_PRESSED:
			LCD_ClearLcd();
			Local_u8State=MODES;
			break;
		default:
			break;
		}
		break;
	case MODES:
		switch(Local_u8Check)
		{
		case SELECT_SW_PRESSED:
			break;
		case UP_SW_PRESSED:
			break;
		case DOWN_SW_PRESSED:
			LCD_ClearLcd();
			Local_u8State=DISPLAY;
			break;
		default:
			break;
		}
		break;
	case TEMP:
		switch(Local_u8Check)
		{
		case SELECT_SW_PRESSED:
			break;
		case UP_SW_PRESSED:

			break;
		case DOWN_SW_PRESSED:
			break;
		default:
			break;
		}
		break;
	case SPEED:
		switch(Local_u8Check)
		{
		case SELECT_SW_PRESSED:
			break;
		case UP_SW_PRESSED:
			break;
		case DOWN_SW_PRESSED:
			break;
		default:
			break;
		}
		break;
	default:
		break;
	}

}
