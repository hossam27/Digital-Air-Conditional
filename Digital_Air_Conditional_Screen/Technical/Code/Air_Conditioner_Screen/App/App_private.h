/*
 * App_private.h
 *
 *  Created on: Apr 8, 2016
 *      Author: 7ossam
 */

#ifndef APP_PRIVATE_H_
#define APP_PRIVATE_H_

#define EMPTY 		0

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
#define FLAG_ADDRESS	0x3F
#endif /* APP_PRIVATE_H_ */
