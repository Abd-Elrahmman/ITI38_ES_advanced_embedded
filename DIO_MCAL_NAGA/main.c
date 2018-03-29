/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: AltAWKEl
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DELAY.h"
#include "DIO_MCAL.h"


int main(void)
{
	DIO_voidInitialize();
	//DDRB = 0xff;
while(1)
{
	DIO_voidWritePin(PIN_A0,1);
	//Delay_ms(500);
	//DIO_voidWritePin(PIN_A1,1);
	//Delay_ms(500);
	if(DIO_u8ReadPin(PIN_A1) == 1)
	{
		DIO_voidWritePin(PIN_B0,1);
		DIO_voidWritePin(PIN_C0,1);
		DIO_voidWritePin(PIN_D0,1);
	}
	else
	{
		DIO_voidWritePin(PIN_B0,0);
		DIO_voidWritePin(PIN_C0,0);
		DIO_voidWritePin(PIN_D0,0);
	}

}




	return 0;
}
