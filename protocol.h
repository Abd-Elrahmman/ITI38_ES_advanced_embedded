/*
 * protocole.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Mousa
 */

#ifndef PROTOCOL_H_
#define PROTOCOL_H_

/* UART standard MSGs     */
#define ID_B1             5U
#define ID_B2             7U
#define ID_KP_VALUE       9U
#define ID_KP_ADJUST      11U
#define ID_MOD_SWITCH     13U
#define PRESSED 		   0
#define RELEASED           1

void protcole_task(void);


#endif /* PROTOCOL_H_ */
