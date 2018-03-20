/*
 * UART_Rx_TEST.c
 *
 *  Created on: Mar 19, 2018
 *      Author: Ahmed
 */
#include "STD_TYPES.h"
#include "DIO_int.h"
#include "UART.h"


void voidRecieveFunc(void){
	u8 data;
	u16 len;
	UART_Receive(&data, &len);
	if (0xFF == data)
	{
		DIO_voidSetPinValue(8, DIO_u8_HIGH);
	}
	else
	{
		DIO_voidSetPinValue(8, DIO_u8_LOW);
	}
}

void voidSendFunc(void)
{
	u8 data = 0xFF;
	u16 len = 1; // Length in Byte
	UART_Transmit(&data, len);
}
