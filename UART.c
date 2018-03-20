/*
 * UART.c
 *
 *  Created on: Mar 14, 2018
 *      Author: Hager
 */

#include "STD_TYPES.h"
#include "DIO_int.h"
#include "UART.h"
#include  "UART_cfg.h"
#include "GIE_int.h"

static UART_t UART_data = {{0}, 0};
void UART_Init(void)
{
	/* Set baud rate */
	u16 baud = 51;
	/* baud = ((u16)((u32)F_CPU/(u32)(16 * BAUD_RATE)) -1);*/
	UBRRH = (u8)(baud>>8);
	UBRRL = (u8)baud;
	/* Enable receiver and transmitter */
	UCSRB |= (1<<RXEN)|(1<<TXEN);
	/* Set frame format: 8data, 2stop bit */
	UCSRC |= (1<<URSEL)|(1<<USBS)|(3<<UCSZ0);
	/* Enable RX Interrupt */
	UCSRB |= (1<<RXCIE);
}

void UART_Transmit(u8* data, u16 Len)
{
	/* Loop that */
	u16 u16CountrLoopLoc;
	for (u16CountrLoopLoc = 0; u16CountrLoopLoc < Len; u16CountrLoopLoc++)
	{

		/* Wait for empty transmit buffer */
		while ( !( UCSRA & (1<<UDRE)));
		/* Put data into buffer, sends the data */
		UDR = data[u16CountrLoopLoc];
	}
}


void UART_Receive(u8 *data, u16 *len)
{
	u16 u16CountrLoopLoc;
	/* Disabling the Global interrupt to ensure*/
	GIE_DISABLE();
	/* Disable RX Interrupt */
	UCSRB &= ~(1<<RXCIE);


	/* return the size of received data */
	*len = UART_data.RxBufferSize;

	/* return the received data into our given array */
	for (u16CountrLoopLoc = 0; u16CountrLoopLoc < UART_data.RxBufferSize; u16CountrLoopLoc++)
	{
		data[u16CountrLoopLoc] = UART_data.RxBuffer[u16CountrLoopLoc];
	}

	/* reset the buffer counter */
	UART_data.RxBufferSize = 0;

	/* Enable RX Interrupt */
	UCSRB |= (1<<RXCIE);
	/* Enabling the global interrupt */
	GIE_ENABLE();
}

/* Enabling USART, Rx Complete Based on vector table from data sheet page 42*/
void __vector_13 (void) __attribute__((signal, used));
void __vector_13 (void)
{
	if(UART_data.RxBufferSize < 9)
	{
		UART_data.RxBuffer[UART_data.RxBufferSize] = UDR;
		UART_data.RxBufferSize++;
	}
}




