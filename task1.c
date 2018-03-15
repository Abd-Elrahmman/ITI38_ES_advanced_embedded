/*
 * task1.c
 *
 *  Created on: Mar 8, 2018
 *      Author: Ahmed
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_int.h"
#include "DIO_reg.h"
#include "task1.h"
#include "KP_int.h"

u8 u8SegNum[]={ZERO, ONE, TWO, THREE,
				FOUR, FIVE, SIX,
				SEVEN, EIGHT, NINE};

 u8 Sec1,Sec2,Min1,Min2,Hr1,Hr2;
 u8 counterSec = 0;
 u8 countermin = 0;
 u8 counterhr = 0;

void voidTask1(void)
{

	counterSec++;
	if(counterSec<60)
	{
		Sec1 = counterSec/10;// Left 7Seg
		Sec2 = counterSec%10;// Right 7Seg
	}
	else
	{
		counterSec=0;
		countermin++;
	}
	if(countermin<60)
	{
		Min1 = countermin/10;
		Min2 = countermin%10;
	}
	else
	{
		countermin =0;
		counterhr++;
	}
	if(counterhr<24)
	{
		Hr1 = counterhr/10;
		Hr2 = counterhr%10;
	}
	else
	{
		counterhr=0;
	}
}
