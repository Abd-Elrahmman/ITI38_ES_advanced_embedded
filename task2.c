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
#include "protocol.h"
#define Seconds		12
#define Minutes     14
#define Hours 		15

u8 u8CurrentMode;
void voidCheckModeUART(void)
{
	u16 u32KeypadStoredValue;
	u32KeypadStoredValue = KP_u16GetStatus();
	if(GET_BIT(u32KeypadStoredValue, Minutes))
	{
		u8 u8Byte = (ID_KP_ADJUST<<4)|(1U);
		UART_Transmit(&u8Byte, 1);
	}
	else if (GET_BIT(u32KeypadStoredValue, Hours))
	{
		u8 u8Byte = (ID_KP_ADJUST<<4)|(2U);
		UART_Transmit(&u8Byte, 2);
	}
	else if (GET_BIT(u32KeypadStoredValue, Seconds))
	{
		u8 u8Byte = (ID_KP_ADJUST<<4)|(0U);
		UART_Transmit(&u8Byte, 0);
	}
}

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
void voidDisplay(void)
{
	switch(u8CurrentMode)
	{
	case 0:
		voidDisplaySeconds();
	break;
	case 1:
		voidDisplayMinutes();
	break;
	case 2:
		voidDisplayHours();
	break;
	}
}
/********************** Prev View Hrs, Min, Sec *****************************************/

void voidTask2(void)
{
	static u32 u32KeypadStoredValue;
	static u8 u8Flag = Seconds;
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

