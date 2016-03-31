/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: ahmed
 */
#include "Types.h"
#include "DIO_interface.h"
#include "LCD_interface.h"
#include "DIO-utilites.h"
#include "DIO_Private.h"
#include "delay.h"

int main(void)
{
	u16 i=20;
	DIO_VoidInit();
	LCD_VoidInit();
	while(1)
	{
		//i++;
		//LCD_VoidGotoxy(0,1);
		//LCD_VoidString(LCD_u16ReturnString(i));
		//LCD_VoidClearScreen();
		LCD_VoidData('4');
		//Delay_ms_Max1s(1000);
	}
return 0;
}
