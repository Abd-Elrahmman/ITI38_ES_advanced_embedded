

#include "STD_TYPES.h"
#include "sw.h"
#include "DIO_int.h"

#define NUMBER_OF_SW    2
#define NUMBER_OF_SAMPLES 2

static u8  u8SwState [NUMBER_OF_SW] = {0};
static u16 SW_u16wHoldTime  = 0;


u8 const u8Link_To_Dio [] = {DIO_u8_PIN_29, DIO_u8_PIN_28};
/* get the switch state */
u8 SW_u8GetState(u8 u8SwitchPin)
{
	return (u8SwState [u8SwitchPin] == SW_MODE);
}

/* returns time in ms which I have been holding the switch */
u16 SW_u16GetHoldTime(void)
{
	return SW_u16wHoldTime;
}

/* periodic switch task */
void SW_voidSwTask(void)
{
	static u8 u8CounterLoop1 ;
	static u16 u8Cnt [NUMBER_OF_SW] = {0};
	static u8 u8PrevState [NUMBER_OF_SW] = {0};

	for(u8CounterLoop1 = 0; u8CounterLoop1 < NUMBER_OF_SW; u8CounterLoop1++){
		u8 u8CurrentState = DIO_u8GetPinValue(u8Link_To_Dio[u8CounterLoop1]);
			if(u8CurrentState == u8PrevState[u8CounterLoop1])
			{
				if(u8Cnt[u8CounterLoop1] >= NUMBER_OF_SAMPLES)
				{
					u8SwState [u8CounterLoop1] = u8CurrentState;
					if(u8SwState [u8CounterLoop1] == SW_MODE)
					{
						SW_u16wHoldTime += NUMBER_OF_SAMPLES;
					}
					else
					{
						SW_u16wHoldTime = 0;
					}
				}
				else
				{
					u8Cnt[u8CounterLoop1]++;
				}
			}
			else
			{
				u8Cnt[u8CounterLoop1] = 1;
			}
			u8PrevState[u8CounterLoop1] = u8CurrentState;
	}


}
