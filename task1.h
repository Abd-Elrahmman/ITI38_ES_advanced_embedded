/*
 * task1.h
 *
 *  Created on: Mar 8, 2018
 *      Author: Ahmed
 */

#ifndef _TASK1_H
#define _TASK1_H


#define ZERO 	0b11000000
#define ONE  	0b11111001
#define TWO  	0b10100100
#define THREE 	0b10110000
#define FOUR 	0b10011001
#define FIVE 	0b10010010
#define SIX 	0b10000010
#define SEVEN 	0b11111000
#define EIGHT 	0b10000000
#define NINE 	0b10010000


extern  u8 Sec1,Sec2,Min1,Min2,Hr1,Hr2;
extern  u8 counterSec;
extern  u8 countermin;
extern  u8 counterhr;
extern  u8 u8SegNum[];

extern void voidTask1(void);
extern void voidDisplaySeconds(void);
extern void voidDisplayMinutes(void);
extern void voidDisplayHours(void);


#endif /* TASK1_H_ */
