/*
 * TIMER0_prog.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Mousa
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "TIM_int.h"
#include "TIM_reg.h"

/* set timer0 to work in CTC mode */
void TIMER0_voidInit()
{
	/* clear tmr1 flag */
	/* Activating Compare PIN 1*/
	SET_BIT(TIFR, 1);

	/*to select CTC mode */
	SET_BIT(TCCR0, WGM01);

	/*  set the pre-scaler to: 1024 */
	SET_BIT(TCCR0, CS00);
	CLR_BIT(TCCR0, CS01);
	SET_BIT(TCCR0, CS02);
	/* set OCR0 compare register */
	OCR0 = 156; // OS Tick = 20 MS

	/* enable tmr0 interrupt */
	SET_BIT(TIMSK, OCIE0);
}
