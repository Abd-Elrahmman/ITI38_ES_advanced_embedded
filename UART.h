/*
 * UART.h
 *
 *  Created on: Mar 14, 2018
 *      Author: Hager
 */

#ifndef _UART_H
#define _UART_H
/* Bit Definitions */
#define RXEN 	4
#define URSEL 	7
#define TXEN 	3
#define USBS 	3
#define UCSZ0 	1
#define UDRE 	5
#define RXC 	7
#define RXCIE   7

/* registers */
#define UBRRH         *((volatile u8*) 0x40)
#define UBRRL         *((volatile u8*) 0x29)
#define UCSRA         *((volatile u8*) 0x2B)
#define UCSRB         *((volatile u8*) 0x2A)
#define UCSRC         *((volatile u8*) 0x40)
#define UDR           *((volatile u8*) 0x2C)

typedef struct {
	u8 RxBuffer[10];
	u8 RxBufferSize;
}UART_t;
extern void UART_Init(void);

extern void UART_Transmit(u8* data, u16 Len);

extern void UART_Receive(u8 *data, u16 *len);

#endif /* UART_H_ */
