#include"STD_TYPES.h"

#define freq_ms 8000             //time in ms
#define freq_us  8					//time in us
#define oneTimeCycles 32
#define callCycles 45
#define equationCycles 797
#define loopingTime 43

void Delay_ms(u32 ms)
{
	u32 i, countLoop  ;
	countLoop = ((freq_ms * ms) - (oneTimeCycles + callCycles + equationCycles)) / loopingTime;
	for(i=0;i<countLoop;i++)
				{
					asm("NOP");
				}
}//delay_ms

void Delay_us(u32 us)
{
	u32 i, countLoop  ;
	countLoop = ((freq_us * us) - (oneTimeCycles + callCycles + equationCycles)) / loopingTime;
	for(i=0;i<countLoop;i++)
				{
					asm("NOP");
				}
}//delay_ms
