/*
 * TIM_reg.h
 *
 *  Created on: Feb 28, 2018
 *      Author: Ahmed, Mousa, Hager
 */

#ifndef _TIM_REG_H
#define _TIM_REG_H

#define TCCR0  	 *((volatile u8*) 0x53)
#define TCNT0  	 *((volatile u8*) 0x52)
#define TIMSK 	 *((volatile u8*) 0x59)
#define TIFR	 *((volatile u8*) 0x58)
#define OCR0     *((volatile u8*) 0x5C)

/****************************** important bits **************************************/
/* wave form generator mode */
/* CTC Mode*/
#define WGM01          3
/* pre-scaler bits */
#define CS00           0
#define CS01           1
#define CS02           2
/* O/p compare interrupt enable*/
#define OCIE0          1

#endif /* TIMER0_REG_H_ */
