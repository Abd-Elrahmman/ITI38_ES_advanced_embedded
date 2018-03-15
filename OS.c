/*
 * OS_prog.c
 *
 *  Created on: Mar 6, 2018
 *      Author: Ahmed
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_int.h"
#include "TIM_int.h"
#include "OS_cfg.h"
#include "OS.h"
#include "avr/interrupt.h"
#include "KP_int.h"


#define InitialValue  0

volatile u32 u32Tick_counter = InitialValue;
volatile u8	 u8Tick_Flag = InitialValue;

void OS_voidInitialization(void){

}

void OS_voidStart(void)
{
	static u8 u8LoopCounterLoc;
	while(1){
		if (1 == u8Tick_Flag)
		{
			u8Tick_Flag = 0;
			for(u8LoopCounterLoc = InitialValue ; u8LoopCounterLoc < u8NumberOfTasks; u8LoopCounterLoc++)
			{
				if((u32Tick_counter % OS_cfg[u8LoopCounterLoc].u16Periodicity) == InitialValue)
				{
					OS_cfg[u8LoopCounterLoc].pfTask();
				}
			}
		}
	}
}


/* Tick Timer */
ISR (TIMER0_COMP_vect)
{
	u32Tick_counter++;
	u8Tick_Flag = 1 ;
}
