/*
 * protocol.c
 *
 *  Created on: ??�/??�/????
 *      Author: Mousa
 */
#include "STD_TYPES.h"
#include  "DIO_int.h"
#include "UART.h"
#include "UART_cfg.h"
#include "protocol.h"
#include "task2.h"
#include "KP_int.h"
void protcole_task(void)
{
	u8 u8byte = 0;
	u8 u8ID, u8Val;
	if(UART_u8DataAvilable())
	{

		/* get one received byte */
		u8byte = UART_u8ReadByte();
		/* Split it to id and value */
		u8ID = (u8byte >> 4) ;
		/* Anding the u8Val with 00001111, to eliminate the ID and extract just the value */
		u8Val = u8byte & 0x0F;

		switch(u8ID)
		{
		case ID_B1:
			if(u8Val == PRESSED)
			{
				/*Set LED High*/
				DIO_voidSetPinValue(DIO_u8_PIN_26, DIO_u8_HIGH);
			}
			else
			{
				/*Set LED LOW*/
				DIO_voidSetPinValue(DIO_u8_PIN_26, DIO_u8_LOW);
			}
			break;

		case ID_B2:
			if(u8Val == PRESSED)
			{
				/* Set LED HIGH */
				DIO_voidSetPinValue(DIO_u8_PIN_27, DIO_u8_HIGH);
			}
			else
			{
				/*Set LED LOW*/
				DIO_voidSetPinValue(DIO_u8_PIN_27, DIO_u8_LOW);
			}
			break;

		case ID_MOD_SWITCH:
			u8CurrentMode = u8Val;
			break;

		case ID_KP_ADJUST:

			break;

		case ID_KP_VALUE:
			break;

		}
	}
}
