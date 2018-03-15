/*
 * keypad.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Mousa
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_int.h"

#include "KP_int.h"
#include "KP_priv.h"
#include "KP_config.h"
/************************************************/
/*  this functions gets you all pressed buttons */
/************************************************/
static u16 KP_u16Status = 0;

u16 KP_u16GetStatus(void)
{
	KP_u16Status = 0;
	/* activate column 1 */
	DIO_voidSetPinValue (KP_u8_OUT_1, DIO_u8_LOW);
	DIO_voidSetPinValue (KP_u8_OUT_2, DIO_u8_HIGH);
	DIO_voidSetPinValue (KP_u8_OUT_3, DIO_u8_HIGH);
	DIO_voidSetPinValue (KP_u8_OUT_4, DIO_u8_HIGH);
	KP_voidGetColStatus(0);

	/* activate column 2 */
	DIO_voidSetPinValue (KP_u8_OUT_1, DIO_u8_HIGH);
	DIO_voidSetPinValue (KP_u8_OUT_2, DIO_u8_LOW);
	DIO_voidSetPinValue (KP_u8_OUT_3, DIO_u8_HIGH);
	DIO_voidSetPinValue (KP_u8_OUT_4, DIO_u8_HIGH);
	KP_voidGetColStatus(1);

	/* activate column 3 */
	DIO_voidSetPinValue (KP_u8_OUT_1, DIO_u8_HIGH);
	DIO_voidSetPinValue (KP_u8_OUT_2, DIO_u8_HIGH);
	DIO_voidSetPinValue (KP_u8_OUT_3, DIO_u8_LOW);
	DIO_voidSetPinValue (KP_u8_OUT_4, DIO_u8_HIGH);
	KP_voidGetColStatus(2);

	/* activate column 4 */
	DIO_voidSetPinValue (KP_u8_OUT_1, DIO_u8_HIGH);
	DIO_voidSetPinValue (KP_u8_OUT_2, DIO_u8_HIGH);
	DIO_voidSetPinValue (KP_u8_OUT_3, DIO_u8_HIGH);
	DIO_voidSetPinValue (KP_u8_OUT_4, DIO_u8_LOW);
	KP_voidGetColStatus(3);
	return KP_u16Status;
}

void KP_voidGetColStatus(u8 col)
{
	/* check for key 0 + n */
	if(DIO_u8GetPinValue(KP_u8_IN_1) == DIO_u8_LOW)
	{
		SET_BIT(KP_u16Status,  col);
	}
	/* check for key 0 + n */
	if(DIO_u8GetPinValue(KP_u8_IN_2) == DIO_u8_LOW)
	{
		SET_BIT(KP_u16Status, 4 + col);
	}
	/* check for key 0 + n */
	if(DIO_u8GetPinValue(KP_u8_IN_3) == DIO_u8_LOW)
	{
		SET_BIT(KP_u16Status, 8 + col);
	}

	/* check for key 0 + n */
	if(DIO_u8GetPinValue(KP_u8_IN_4) == DIO_u8_LOW)
	{
		SET_BIT(KP_u16Status, 12 + col);
	}
}
