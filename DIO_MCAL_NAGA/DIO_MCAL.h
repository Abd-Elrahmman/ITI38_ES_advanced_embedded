/*
 * DIO_MCAL.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: AltAWKEl
 */

#ifndef DIO_MCAL_H_
#define DIO_MCAL_H_

#include "STD_TYPES.h"
#include "DIO_config.h"

#define DIO_HIGH 1
#define DIO_LOW  0

/******************** Function to initialize DIO Pins *********/
void DIO_voidInitialize();

/******************** Function to Write on  DIO Pins *********/
void DIO_voidWritePin(DIO_PIN_NAME_T PinName,u8 value);

/******************** Function to Read from  DIO Pins *********/
u8 DIO_u8ReadPin(DIO_PIN_NAME_T PinName);




#endif /* DIO_MCAL_H_ */
