/*
 * taskSwitchLed.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Mousa
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_int.h"
#include "TIM_int.h"
#include "GIE_int.h"
#include "task1.h"
#include "task2.h"
#include "Clock_adjust.h"
#include "taskSwitchLed.h"
#include "KP_int.h"
#include "sw.h"
#include "protocol.h"

void taskSwitchLed(void){
	u8 u8Byte;
	if (SW_u8GetState(0)){
		/* Stores the button1 ID, and place it in the higher nibble - 4 bits - , PRESSED*/
		u8Byte = (ID_B1<<4)|(0U);

	}
	else
	{
		/* Stores the button1 ID, and place it in the higher nibble - 4 bits - , RELEASED*/
		u8Byte = (ID_B1<<4)|(1U);
	}
	if (SW_u8GetState(1)){
		/* Stores the button1 ID, and place it in the higher nibble - 4 bits - , RELEASED*/
		u8Byte = (ID_B2<<4)|(0U);
	}
	else
	{
		/* Stores the button1 ID, and place it in the higher nibble - 4 bits - , RELEASED*/
		u8Byte = (ID_B2<<4)|(1U);
	}
}
