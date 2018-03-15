#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "DIO_config.h"
#include "DIO_priv.h"
#include "DIO_int.h"
#include "DIO_reg.h"

void DIO_voidInitialize(void)
{
	DDRA=DIO_u8_PORTA_DIRECTION;
	DDRB=DIO_u8_PORTB_DIRECTION;
	DDRC=DIO_u8_PORTC_DIRECTION;
	DDRD=DIO_u8_PORTD_DIRECTION;
	
}

void DIO_voidSetPinValue(u8 u8PinIndexcpy,u8 u8PinValueCpy)
{
	
	/*check if the pin index in  PORTA	range*/
	if(  (u8PinIndexcpy >=DIO_u8_PORTA_START )&& (u8PinIndexcpy <=DIO_u8_PORTA_END))
	{
		if(u8PinValueCpy == DIO_u8_HIGH)
		{
			SET_BIT(PORTA, u8PinIndexcpy);
		}
		else
		{
			CLR_BIT(PORTA, u8PinIndexcpy);
		}
	}
	else if(  (u8PinIndexcpy >= DIO_u8_PORTB_START )&& (u8PinIndexcpy <= DIO_u8_PORTB_END))
	{
		u8PinIndexcpy-= DIO_PORTA_SIZE;
		if(u8PinValueCpy == DIO_u8_HIGH)
		{
			SET_BIT(PORTB, u8PinIndexcpy);
		}
		else
		{
			CLR_BIT(PORTB, u8PinIndexcpy);
		}
		
	}
	else if((u8PinIndexcpy >= DIO_u8_PORTC_START )&& (u8PinIndexcpy <= DIO_u8_PORTC_END))
	{
		    u8PinIndexcpy -= DIO_PORTA_SIZE+DIO_PORTB_SIZE;
			if(u8PinValueCpy == DIO_u8_HIGH)
			{
				SET_BIT(PORTC, u8PinIndexcpy);
			}
			else
			{
				CLR_BIT(PORTC, u8PinIndexcpy);
			}
	}
	else if((u8PinIndexcpy >=DIO_u8_PORTD_START )&& (u8PinIndexcpy <= DIO_u8_PORTD_END))
	{
		    u8PinIndexcpy -= DIO_PORTA_SIZE+DIO_PORTB_SIZE+DIO_PORTC_SIZE;
			if(u8PinValueCpy == DIO_u8_HIGH)
			{
				SET_BIT(PORTD, u8PinIndexcpy);
			}
			else
			{
				CLR_BIT(PORTD,u8PinIndexcpy);
			}
	}
		
}

 u8 DIO_u8GetPinValue(u8 u8PinIndexcpy)
{
	 u8 u8ReturnValue;
	if(  (u8PinIndexcpy >= DIO_u8_PORTA_START )&& (u8PinIndexcpy <= DIO_u8_PORTA_END))
	{
		if(GET_BIT(PINA, u8PinIndexcpy) == 1)
		{
			u8ReturnValue=DIO_u8_HIGH;
		}
		else
		{
			u8ReturnValue=DIO_u8_LOW;
		}

	}
	else if(  (u8PinIndexcpy >=DIO_u8_PORTB_START )&& (u8PinIndexcpy <=DIO_u8_PORTB_END))
	{
		u8PinIndexcpy-=DIO_PORTA_SIZE;
		if(GET_BIT(PINB,u8PinIndexcpy) == 1)
		{
			u8ReturnValue=DIO_u8_HIGH;
		}
		else
		{
			u8ReturnValue=DIO_u8_LOW;
		}

	}
	else if((u8PinIndexcpy >=DIO_u8_PORTC_START )&& (u8PinIndexcpy <=DIO_u8_PORTC_END))
	{
		u8PinIndexcpy-=DIO_PORTA_SIZE+DIO_PORTB_SIZE;
		if(GET_BIT(PINC,u8PinIndexcpy) == 1)
		{
			u8ReturnValue=DIO_u8_HIGH;
		}
		else
		{
			u8ReturnValue=DIO_u8_LOW;
		}
	}
	else if((u8PinIndexcpy >=DIO_u8_PORTD_START )&& (u8PinIndexcpy <=DIO_u8_PORTD_END))
	{
		u8PinIndexcpy-=DIO_PORTA_SIZE+DIO_PORTB_SIZE+DIO_PORTC_SIZE;
		if(GET_BIT(PIND,u8PinIndexcpy) == 1)
		{
			u8ReturnValue=DIO_u8_HIGH;
		}
		else
		{
			u8ReturnValue=DIO_u8_LOW;
		}


	}
	return u8ReturnValue;
}


