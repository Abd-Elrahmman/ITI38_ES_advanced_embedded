/*
 * Clock_adjust.c
 *
 *  Created on: Mar 9, 2018
 *      Author: Ahmed
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_int.h"
#include "DIO_reg.h"
#include "task1.h"
#include "task2.h"
#include "KP_int.h"
#include "protocol.h"
#include "UART.h"

#define NORMAL_STATE        0
#define ADJUSTING_STATE     5
#define ADJUST_SS_STATE     (1 << 3)
#define ADJUST_MM_STATE     (1 << 7)
#define ADJUST_HH_STATE     (1 << 11)

extern u8 counterSec;
extern u8 countermin;
extern u8 counterhr ;
/* display mode */
extern u8 u8CurrentMode;
static u8 u8Byte;


u8 u8GetNum(void)
{
	u8 i = 10;
	switch(KP_u16GetStatus())
	{
	case (1 << 0):
		i = 1;
		break;

	case (1 << 1):
		i = 2;
		break;

	case (1 << 2):
		i = 3;
		break;

	case (1 << 4):
		i = 4;
		break;

	case (1 << 5):
		i = 5;
		break;

	case (1 << 6):
		i = 6;
		break;

	case (1 << 8):
		i = 7;
		break;

	case (1 << 9):
		i = 8;
	    break;

	case (1 << 10):
		i = 9;
		break;

	case (1 << 13):
		i = 0;
	 	break;

	}
	return i;
}


void voidClockAdjust(void)
{
	static u16 u16AdjustState  = NORMAL_STATE;   /* current state indicator          */
	static u8 u8DigitCounter;                    /* number of digit has been entered */
	static u8 u8AdjustValue;                     /* new adjust value                 */
	static u16 u16AdjustStateTimeout;            /* Amount of time that the adjust mode can be active in*/
	static u16 u16KeypadStoredValue;             /* holds last pressed key value */
	static u8 u8digit[2];

	switch(u16AdjustState)
	{
		case NORMAL_STATE:
		/* check if the kp got pressed */
		u16KeypadStoredValue= KP_u16GetStatus();

		switch(u16KeypadStoredValue)
		{
		case ADJUST_SS_STATE:
		case ADJUST_MM_STATE:
		case ADJUST_HH_STATE:
			/* prepare for the adjust mode*/
			u16AdjustStateTimeout = 6;
			u8DigitCounter = 0;
			u8AdjustValue  = 0;
			/* go to adjusting mode */
			u16AdjustState = ADJUSTING_STATE;
			/* set display mode for adjusting mode */
			u8CurrentMode = 0xFF;
			/* clear 7 segm display*/
			PORTC = u8SegNum[0];
			PORTA = u8SegNum[0];

			break;
		}
		break;

		case ADJUSTING_STATE:
			/* allow user to enter tow digits only as long as the adjust event didn't timeout */
			if(u16AdjustStateTimeout && u8DigitCounter < 2)
			{
				u8 u8num = u8GetNum();
                /* if got number from 0 to 9 */
				if(u8num < 10)
				{
					u8digit[u8DigitCounter] = u8num;
					/* combine the tow digits in one decimal value*/
					if(u8DigitCounter == 0)
					{
						PORTA = u8SegNum[u8num];
						u16AdjustStateTimeout = 6;
					}
					else
					{
						PORTC = u8SegNum[u8num];
					}
					u8DigitCounter++;
				}
				u16AdjustStateTimeout--;
			}
			/* if adjust has been completed successfully go apply it */
			else if(u16AdjustStateTimeout && u8DigitCounter == 2)
			{
				u16AdjustState = u16KeypadStoredValue;
			}
			/* if adjust has'nt been completed successfully dismiss it */
			else
			{
				u16AdjustState = NORMAL_STATE;
				u8CurrentMode = 0; /* to display seconds by default */

			}
			break;

		case ADJUST_SS_STATE:
			/* update seconds with the u8AdjustValue*/
			if (u8AdjustValue < 60){

				/* Stores the Keyboard Number ID, and place it in the higher nibble - 4 bits -*/
				/* send adjust command */
				u8Byte = (ID_KP_ADJUST<<4)|(0U);
				UART_Transmit(&u8Byte, 1);
				/* send the first digit */
				u8Byte = (ID_KP_VALUE<<4)|(u8digit[0]);
				UART_Transmit(&u8Byte, 1);
				/* send the second digit */
				u8Byte = (ID_KP_VALUE<<4)|(u8digit[1]);
				UART_Transmit(&u8Byte, 1);
			}
			else
						{
							/* DO NOTHING */
						}

			u8CurrentMode = 0; /* to display seconds */
			u16AdjustState = NORMAL_STATE;
			break;
		case ADJUST_MM_STATE:

			/* update minutes with the u8AdjustValue*/
			if (u8AdjustValue < 60){
				u8Byte = (ID_KP_ADJUST<<4)|(1U);
				UART_Transmit(&u8Byte, 1);
				/* send the first digit */
				u8Byte = (ID_KP_VALUE<<4)|(u8digit[0]);
				UART_Transmit(&u8Byte, 1);
				/* send the second digit */
				u8Byte = (ID_KP_VALUE<<4)|(u8digit[1]);
				UART_Transmit(&u8Byte, 1);
			}
			else
						{
							/* DO NOTHING */
						}

			u8CurrentMode = 0; /* to display minutes */
			u16AdjustState = NORMAL_STATE;
			break;
		case ADJUST_HH_STATE:
			/* update hours with the u8AdjustValue*/
			if (u8AdjustValue < 24){
				u8Byte = (ID_KP_ADJUST<<4)|(2U);
				UART_Transmit(&u8Byte, 1);
				/* send the first digit */
				u8Byte = (ID_KP_VALUE<<4)|(u8digit[0]);
				UART_Transmit(&u8Byte, 1);
				/* send the second digit */
				u8Byte = (ID_KP_VALUE<<4)|(u8digit[1]);
				UART_Transmit(&u8Byte, 1);
			}
			else
			{
				/* DO NOTHING */
			}
			u8CurrentMode = 0; /* to display hours */
			u16AdjustState = NORMAL_STATE;
			break;
	}
}
