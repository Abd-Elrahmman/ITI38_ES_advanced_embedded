/*
 * DIO_MCAL.c
 *
 *  Created on: 27/3/2018
 *      Author: Ahmed Abdelghany
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO.h"

#define Number_of_Pins 			8

#define PORT_A_Num				0
#define PORT_B_Num				1
#define PORT_C_Num				2
#define PORT_D_Num				3

#define OUTPUT_VALUE			1

/******************** Function to initialize DIO Pins *********/
void DIO_voidInitialize()
{

	static u8 u8LoopCounter;
	for (u8LoopCounter = 0; u8LoopCounter < total_pins_count; u8LoopCounter++)
	{

		switch (DIO_MODE[u8LoopCounter])
		{
		case OUTPUT:
			switch (u8LoopCounter / Number_of_Pins)  /* know which PORT */
			{
			case PORT_A_Num:
				DDRA |= (OUTPUT_VALUE <<(u8LoopCounter % Number_of_Pins)); /* know which PIN*/
				//SET_BIT(DDRA,(u8LoopCounter % Num_of_Pins));
				break;
			case PORT_B_Num:
				DDRB |= (OUTPUT_VALUE <<(u8LoopCounter % Number_of_Pins));
				//SET_BIT(DDRB,(u8LoopCounter % Num_of_Pins));
				break;
			case PORT_C_Num:
				DDRC |= (OUTPUT_VALUE <<(u8LoopCounter % Number_of_Pins));
				//SET_BIT(DDRC,(u8LoopCounter % Num_of_Pins));
				break;
			case PORT_D_Num:
				DDRD |= (OUTPUT_VALUE <<(u8LoopCounter % Number_of_Pins));
				//SET_BIT(DDRD,(u8LoopCounter % Num_of_Pins));
				break;
			} //switch_PIN
			break;
		case INPUT_WITHOUT_INTERNAL:
			switch (u8LoopCounter / Number_of_Pins)
			{
			case PORT_A_Num:
				DDRA &= ~(OUTPUT_VALUE <<(u8LoopCounter % Number_of_Pins));
				//CLR_BIT(DDRA,(u8LoopCounter % Num_of_Pins));
				break;
			case PORT_B_Num:
				DDRB &= ~(OUTPUT_VALUE <<(u8LoopCounter % Number_of_Pins));
				//CLR_BIT(DDRB,(u8LoopCounter % Num_of_Pins));
				break;
			case PORT_C_Num:
				DDRC &= ~(OUTPUT_VALUE <<(u8LoopCounter % Number_of_Pins));
				//CLR_BIT(DDRC,(u8LoopCounter % Num_of_Pins));
				break;
			case PORT_D_Num:
				DDRD &= ~(OUTPUT_VALUE <<(u8LoopCounter % Number_of_Pins));
				//CLR_BIT(DDRD,(u8LoopCounter % Num_of_Pins));
				break;
			} //switch_PIN
			break;
		case INPUT_WITH_INTERNAL_PUR:
			switch (u8LoopCounter / Number_of_Pins)
			{
			case PORT_A_Num:
				DDRA &= ~(OUTPUT_VALUE << (u8LoopCounter % Number_of_Pins));
				//CLR_BIT(DDRA,(u8LoopCounter % Num_of_Pins));
				/** SET one to PIN to make it interinal pull up **/
				PORTA |= (OUTPUT_VALUE <<(u8LoopCounter % Number_of_Pins));
				//SET_BIT(PORTA,(u8LoopCounter % Num_of_Pins));
				break;
			case PORT_B_Num:
				DDRB &= ~(OUTPUT_VALUE << (u8LoopCounter % Number_of_Pins));
				//CLR_BIT(DDRB,(u8LoopCounter % Num_of_Pins));
				/** SET one to PIN to make it interinal pull up **/
				PORTB |= (OUTPUT_VALUE <<(u8LoopCounter % Number_of_Pins));
				//SET_BIT(PORTB,(u8LoopCounter % Num_of_Pins));
				break;
			case PORT_C_Num:
				DDRC &= ~(OUTPUT_VALUE << (u8LoopCounter % Number_of_Pins));
				//CLR_BIT(DDRC,(u8LoopCounter % Num_of_Pins));
				PORTC |= (OUTPUT_VALUE <<(u8LoopCounter % Number_of_Pins));
				//SET_BIT(PORTC,(u8LoopCounter % Num_of_Pins));
				break;
			case PORT_D_Num:
				DDRD &= ~(OUTPUT_VALUE << (u8LoopCounter % Number_of_Pins));
				//CLR_BIT(DDRD,(u8LoopCounter % Num_of_Pins));
				PORTD |= (OUTPUT_VALUE <<(u8LoopCounter % Number_of_Pins));
				//SET_BIT(PORTD,(u8LoopCounter % Num_of_Pins));
				break;
			} //switch_PIN
			break;
		} //switch_Mode
	} //for

}


/******************** Function to Write on  DIO Pins *********/
void DIO_voidWritePin(DIO_PIN_NAME_T PinName,u8 value)
{

	if(DIO_HIGH == value)
	{

		switch (PinName / Number_of_Pins) /* know which PORT */
		{
		case PORT_A_Num:
			//PORTA |= (OUTPUT_VALUE << (PinName % Num_of_Pins));
			SET_BIT(PORTA,(PinName % Number_of_Pins));
			break;
		case PORT_B_Num:
			//PORTB |= (OUTPUT_VALUE << (PinName % Num_of_Pins));
			SET_BIT(PORTB,(PinName % Number_of_Pins));
			break;
		case PORT_C_Num:
			PORTC |= (OUTPUT_VALUE << (PinName % Number_of_Pins));
			//SET_BIT(PORTC,(PinName % Num_of_Pins));
			break;
		case PORT_D_Num:
			PORTD |= (OUTPUT_VALUE << (PinName % Number_of_Pins));
			//SET_BIT(PORTD,(PinName % Num_of_Pins));
			break;
		} //switch_PIN
	}//if
	else if (DIO_LOW == value)
	{
		switch (PinName / Number_of_Pins)
		{
		case PORT_A_Num:
			PORTA &= ~(OUTPUT_VALUE << (PinName % Number_of_Pins));
			//CLR_BIT(PORTA,(u8LoopCounter % Num_of_Pins));
			break;
		case PORT_B_Num:
			PORTB &= ~(OUTPUT_VALUE << (PinName % Number_of_Pins));
			//CLR_BIT(PORTB,(u8LoopCounter % Num_of_Pins));
			break;
		case PORT_C_Num:
			PORTC &= ~(OUTPUT_VALUE << (PinName % Number_of_Pins));
			//CLR_BIT(PORTC,(u8LoopCounter % Num_of_Pins));
			break;
		case PORT_D_Num:
			PORTD &= ~(OUTPUT_VALUE << (PinName % Number_of_Pins));
			//CLR_BIT(PORTD,(u8LoopCounter % Num_of_Pins));
			break;
		} //switch_PIN
	}//else
}

/******************** Function to Read from  DIO Pins *********/
u8 DIO_u8ReadPin(DIO_PIN_NAME_T PinName)
{
	static u8 Pin_Value = 0;
	switch (PinName / Number_of_Pins)
	{
	case PORT_A_Num:
		Pin_Value = GET_BIT(PINA,(PinName % Number_of_Pins));
		break;
	case PORT_B_Num:
		Pin_Value = GET_BIT(PINB,(PinName % Number_of_Pins));
		break;
	case PORT_C_Num:
		Pin_Value = GET_BIT(PINC,(PinName % Number_of_Pins));
		break;
	case PORT_D_Num:
		Pin_Value = GET_BIT(PIND,(PinName % Number_of_Pins));
		break;
	} //switch_PIN
	return Pin_Value;
}
