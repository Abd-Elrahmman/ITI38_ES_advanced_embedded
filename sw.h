/*
 * sw.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Mousa
 */

#ifndef SW_H_
#define SW_H_

/* pleas select switch pin from DIO driver */
#define SW_PIN            DIO_u8_PIN_3

/*switch modes*/
#define ACTIVE_HIGH          1
#define ACTIVE_LOW           0

/* pleas select switch mode                */
#define SW_MODE              ACTIVE_HIGH

/********************************************** interfaces ********************************************************/
/* get the switch state */
u8 SW_u8GetState(u8 u8SwitchPin);

/* returns time in ms which I have been holding the switch */
u16 SW_u16GetHoldTime(void);

/* periodic switch task */
void SW_voidSwTask(void);

/*****************************************************************************************************************/
#endif /* SW_H_ */
