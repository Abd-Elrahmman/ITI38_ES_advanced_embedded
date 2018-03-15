/*
 * task2.c
 *
 *  Created on: Mar 8, 2018
 *      Author: Hager
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_int.h"
#include "DIO_reg.h"
#include "task1.h"
#include "task2.h"
#include "Clock_adjust.h"
#include "KP_int.h"

#define Seconds		12
#define Minutes     14
#define Hours 		15

void voidDisplaySeconds(void)
{
	PORTB = u8SegNum[Sec2];
	PORTA = u8SegNum[Sec1];
}
void voidDisplayMinutes(void)
{
	PORTB = u8SegNum[Min2];
	PORTA = u8SegNum[Min1];
}
void voidDisplayHours(void)
{
	PORTB = u8SegNum[Hr2];
	PORTA = u8SegNum[Hr1];
}
void voidTask2(void)
{
	static u32 u32KeypadStoredValue;
	static u8 u8Flag = Seconds;
	u32KeypadStoredValue = KP_u16GetStatus();
	if(Seconds == u8Flag)
	{
		if(GET_BIT(u32KeypadStoredValue, Minutes))
		{
			u8Flag = Minutes;
		}
		else if (GET_BIT(u32KeypadStoredValue, Hours))
		{
			u8Flag = Hours;
		}
		else if (u8FlagAdjustmentMode == 1)
		{

		}
		else
		{
			voidDisplaySeconds();
		}

	}
	else if(Minutes == u8Flag)
	{
		if(GET_BIT(u32KeypadStoredValue, Seconds))
		{
			u8Flag = Seconds;
		}
		else if (GET_BIT(u32KeypadStoredValue, Hours))
		{
			u8Flag = Hours;
		}
		else if (u8FlagAdjustmentMode == 1) {}
		else
		{
			voidDisplayMinutes();
		}
	}
	else if(Hours == u8Flag)
	{
		if(GET_BIT(u32KeypadStoredValue, Seconds))
		{
			u8Flag = Seconds;
		}
		if(GET_BIT(u32KeypadStoredValue, Minutes))
		{
			u8Flag = Minutes;
		}
		else if (u8FlagAdjustmentMode == 1) {}
		else
		{
			voidDisplayHours();
		}
	}

}


