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

#define NORMAL_STATE        0
#define ADJUSTING_STATE     5
#define ADJUST_SS_STATE     (1 << 3)
#define ADJUST_MM_STATE     (1 << 7)
#define ADJUST_HH_STATE     (1 << 11)

extern u8 counterSec;
extern u8 countermin;
extern u8 counterhr ;


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

u8 u8FlagAdjustmentMode;

void voidClockAdjust(void)
{
	static u16 u16AdjustState  = NORMAL_STATE;   /* current state indicator          */
	static u8 u8DigitCounter;                    /* number of digit has been entered */
	static u8 u8AdjustValue;                     /* new adjust value                 */
	static u16 u16AdjustStateTimeout;            /* Amount of time that the adjust mode can be active in*/
	static u16 u16KeypadStoredValue;             /* holds last pressed key value */

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
			u8FlagAdjustmentMode = 1;
			break;
		}
		break;

		case ADJUSTING_STATE:
			/* allow user to enter tow digits only as long as the adjust event didn't timeout */
			if(u16AdjustStateTimeout && u8DigitCounter < 2)
			{
				u8 u8digit = u8GetNum();
                /* if got number from 0 to 9 */
				if(u8digit < 10)
				{
					/* combine the tow digits in one decimal value*/
					if(u8DigitCounter == 0)
					{
						PORTC = u8SegNum[u8digit];
						u8AdjustValue = u8digit * 10;
						u16AdjustStateTimeout = 6;
					}
					else
					{
						PORTA = u8SegNum[u8digit];
						u8AdjustValue += u8digit;
					}
					u8DigitCounter++;
				}
				u16AdjustStateTimeout--;
			}
			/* if adjust has been completed successfully go apply it */
			else if(u16AdjustStateTimeout && u8DigitCounter == 2)
			{
				u16AdjustState = u16KeypadStoredValue;
				u8FlagAdjustmentMode = 0;
			}
			/* if adjust has'nt been completed successfully dismiss it */
			else
			{
				u16AdjustState = NORMAL_STATE;
				u8FlagAdjustmentMode = 0;
			}
			break;

		case ADJUST_SS_STATE:
			/* update seconds with the u8AdjustValue*/
			if (u8AdjustValue < 60){
				counterSec = u8AdjustValue;
			}
			u16AdjustState = NORMAL_STATE;
			break;
		case ADJUST_MM_STATE:
			/* update minutes with the u8AdjustValue*/
			if (u8AdjustValue < 60){
				countermin = u8AdjustValue;
			}
			u16AdjustState = NORMAL_STATE;
			break;
		case ADJUST_HH_STATE:
			/* update hours with the u8AdjustValue*/
			if (u8AdjustValue < 24){
				counterhr = u8AdjustValue;
			}
			u16AdjustState = NORMAL_STATE;
			break;
	}
}
