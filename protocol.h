/*
 * protocole.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Mousa
 */

#ifndef PROTOCOL_H_
#define PROTOCOL_H_

/* UART standard MSGs     */
#define ID_B1             0U
#define ID_B2             1U
#define ID_KP_VALUE       2U
#define ID_KP_ADJUST      3U
#define ID_MOD_SWITCH     4U


void protcole_task(void);


#endif /* PROTOCOL_H_ */
