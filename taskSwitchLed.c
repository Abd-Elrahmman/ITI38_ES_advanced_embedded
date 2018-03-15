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

void taskSwitchLed(void){

	if (SW_u8GetState(0)){
		/* PC1 High Led */
		DIO_voidSetPinValue(DIO_u8_PIN_16, DIO_u8_HIGH);
	}
	else
	{
		DIO_voidSetPinValue(DIO_u8_PIN_16, DIO_u8_LOW);
	}
	if (SW_u8GetState(1)){
		/* PC1 High Led */
		DIO_voidSetPinValue(DIO_u8_PIN_23, DIO_u8_HIGH);
	}
	else
	{
		DIO_voidSetPinValue(DIO_u8_PIN_23, DIO_u8_LOW);
	}
}
