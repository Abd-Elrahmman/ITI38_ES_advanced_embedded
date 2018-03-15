/*
 * protocol.c
 *
 *  Created on: ??�/??�/????
 *      Author: Mousa
 */

#include "protocol.h"
#include "UART.h"
/* Dependencies */
#include "task1.h"
#include "task2.h"
#include "Clock_adjust.h"
#include "taskSwitchLed.h"

void protcole_task(void)
{
	u8 u8byte = 0;
	u8 u8ID, u8Val;
	/* get one received byte */
	UART_Receive(&u8byte, 1);
	/* Split it to id and value */
	u8ID = (u8byte >> 4) & 0x0F;
	u8Val = u8byte & 0x0F;

	switch(u8ID)
	{
	case ID_B1:

	break;

	case ID_B2:
	break;

	case ID_MOD_SWITCH:
	break;

	case ID_KP_ADJUST:
	break;

	case ID_KP_VALUE:
	break;
	}
}
