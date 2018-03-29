/*
 * DIO_config.h
 *
 *  Created on: 27/3/2018
 *      Author: DKOSH
 */

#ifndef DIO_CONFIG_H_
#define DIO_CONFIG_H_

/* config of 32 Pins DIO */
typedef enum
{
	/***** PORT A *****/
	PIN_A0 = 0,	  //PIN_A0
	PIN_A1,       //PIN_A1
	PIN_A2,       //PIN_A2
	PIN_A3,       //PIN_A3
	PIN_A4,       //PIN_A4
	PIN_A5,       //PIN_A5
	PIN_A6,       //PIN_A6
	PIN_A7,       //PIN_A7
	/***** PORT B *****/
	PIN_B0,		//PIN_B0
	PIN_B1,        //PIN_B1
	PIN_B2,        //PIN_B2
	PIN_B3,        //PIN_B3
	PIN_B4,        //PIN_B4
	PIN_B5,        //PIN_B5
	PIN_B6,        //PIN_B6
	PIN_B7,        //PIN_B7
	/***** PORT C *****/
	PIN_C0,		//PIN_C0
	PIN_C1,			//PIN_C1
	PIN_C2,        //PIN_C2
	PIN_C3,        //PIN_C3
	PIN_C4,        //PIN_C4
	PIN_C5,        //PIN_C5
	PIN_C6,        //PIN_C6
	PIN_C7,        //PIN_C7
	/***** PORT D *****/
	PIN_D0,			//PIN_D0
	PIN_D1,        //PIN_D1
	PIN_D2,        //PIN_D2
	PIN_D3,        //PIN_D3
	PIN_D4,        //PIN_D4
	PIN_D5,        //PIN_D5
	PIN_D6,        //PIN_D6
	PIN_D7,        //PIN_D7

	total_pins_count
}DIO_PIN_NAME_T;

/* Enum for Pins Mode */
typedef enum
{
	INPUT_WITH_INTERNAL_PUR = 0,
	INPUT_WITHOUT_INTERNAL,
	OUTPUT
}DIO_PIN_MODE_T;

/* Prototype for DIO_MODE Array*/
extern const DIO_PIN_MODE_T DIO_MODE [];















///*************************** Registers ******************************///
/* Group A Registers */
#define PORTA 		*((u8*) 0x3B)
#define DDRA		*((u8*) 0x3A)
#define PINA		*((u8*) 0x39)
/* Group B Registers */
#define PORTB 	 	*((u8*) 0x38)
#define DDRB		*((u8*) 0x37)
#define PINB		*((u8*) 0x36)
/* Group C Registers */
#define PORTC  		*((u8*) 0x35)
#define DDRC		*((u8*) 0x34)
#define PINC 		*((u8*) 0x33)
/* Group D Registers */
#define PORTD  		*((u8*) 0x32)
#define DDRD		*((u8*) 0x31)
#define PIND 		*((u8*) 0x30)
/////////////////////////////////*************************************///////////////////////////////


#endif /* DIO_CONFIG_H_ */
