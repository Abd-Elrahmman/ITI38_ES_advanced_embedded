#ifndef _DIO_REG_H
#define _DIO_REG_H

/* PORTA I/O */
#define PINA   *((volatile u8*) 0x39)
#define DDRA   *((volatile u8*) 0x3A)
#define PORTA  *((volatile u8*) 0x3B)

/* PORTB I/O */
#define PINB   *((volatile u8*) 0x36)
#define DDRB   *((volatile u8*) 0x37)
#define PORTB  *((volatile u8*) 0x38)

/* PORTC I/O */
#define PINC   *((volatile u8*) 0x33)
#define DDRC   *((volatile u8*) 0x34)
#define PORTC  *((volatile u8*) 0x35)
 
/* PORTD I/O */
#define PIND   *((volatile u8*) 0x30)
#define DDRD   *((volatile u8*) 0x31)
#define PORTD  *((volatile u8*) 0x32)


#endif
