/*
 * protocol.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Mousa
 */
#include "STD_TYPES.h"
#include  "DIO_int.h"
#include "UART.h"
#include "UART_cfg.h"
#include "protocol.h"
#include "task2.h"
#include "KP_int.h"
#include "DIO_reg.h"
#include "task1.h"

static u8 u8AdjustMode;

static u8 u8MsgBufferData[5] = {0};
static u16 u16MsgBufferSize;
static u8 u8DigitOrder;
u8 u8AdjustValue;
void protcole_task(void)
{
	u8 u8ID, u8Val;
	if(UART_u8DataAvilable())
	{
		u8 counterLoopLoc;
		/* Listen to UART recieved message */
		UART_Receive(&u8MsgBufferData, &u16MsgBufferSize);
		/**/
		/* get one received byte */
		//u8byte = UART_u8ReadByte();
		/* Loop to start getting what's inside UART which is the message buffer */
		for (counterLoopLoc = 0; counterLoopLoc < u16MsgBufferSize ; counterLoopLoc++)
		{
			/* Split it to id and value */
			u8ID = (u8MsgBufferData[counterLoopLoc] >> 4) ;
			/* Anding the u8Val with 00001111, to eliminate the ID and extract just the value */
			u8Val = u8MsgBufferData[counterLoopLoc] & 0x0F;

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
				u8AdjustMode = u8Val;
				u8DigitOrder = 0;

				break;

			case ID_KP_VALUE:

				/* combine the two digits in one decimal value*/
				if(u8DigitOrder == 0)
				{
					PORTA = u8SegNum[u8Val];
					u8AdjustValue = u8Val * 10;
				}
				else
				{
					PORTC = u8SegNum[u8Val];
					u8AdjustValue += u8Val;
				}
				/* Increasing the number of digit as the user pressed a ID_KP_VALUE*/
				u8DigitOrder++;
				switch(u8AdjustMode)
				{
				case 0:
					if (u8AdjustValue < 60)
					{
						counterSec = u8AdjustValue ;
					}
					break;
				case 1:
					if (u8AdjustValue < 60)
					{
						countermin = u8AdjustValue;
					}
					break;
				case 2:
					if (u8AdjustValue < 24)
					{
						counterhr = u8AdjustValue;
					}
					break;
				}
				break;


			}

		}

	}
}
