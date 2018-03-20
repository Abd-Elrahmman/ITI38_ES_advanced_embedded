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
#include "UART.h"

void taskSwitch1Led(void)
{
	u8 u8ByteSW1;
	if (SW_u8GetState(0))
	{
		/* Stores the button1 ID, and place it in the higher nibble - 4 bits - , PRESSED*/
		u8ByteSW1 = (ID_B1<<4)|(0U);

	}
	else
	{
		/* Stores the button1 ID, and place it in the higher nibble - 4 bits - , RELEASED*/
		u8ByteSW1 = (ID_B1<<4)|(1U);
	}
	UART_Transmit(&u8ByteSW1, 1);


}
void taskSwitch2Led(void)
{
	u8 u8ByteSW2;
	if (SW_u8GetState(1))
	{
		/* Stores the button1 ID, and place it in the higher nibble - 4 bits - , RELEASED*/
		u8ByteSW2 = (ID_B2<<4)|(0U);
	}
	else
	{
		/* Stores the button1 ID, and place it in the higher nibble - 4 bits - , RELEASED*/
		u8ByteSW2 = (ID_B2<<4)|(1U);
	}
	UART_Transmit(&u8ByteSW2, 1);
}

/* Functions handles the UART Recieving the signal for the switch*/
void taskReciever(void)
{
	u8 dataRecieved;
	u16 length;

	UART_Receive(&dataRecieved,&length);
	if(dataRecieved == 0x00) /*led1  on */
	{
		DIO_voidSetPinValue(DIO_u8_PIN_16,DIO_u8_HIGH);
	}
	else
	{
		DIO_voidSetPinValue(DIO_u8_PIN_16,DIO_u8_LOW);
	}

	if(dataRecieved == 0x10)/*led2 on*/
	{
		DIO_voidSetPinValue(DIO_u8_PIN_23,DIO_u8_HIGH);
	}
	else
	{
		DIO_voidSetPinValue(DIO_u8_PIN_23,DIO_u8_LOW);
	}
}
