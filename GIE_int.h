/*
 * GIE_int.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Mousa
 */
#include "GIE_reg.h"

#ifndef GIE_INT_H_
#define GIE_INT_H_

#define GIE_ENABLE()		(SREG |=  (1 << 7))
#define GIE_DISABLE()		(SREG &= ~(1 << 7))

#endif /* GIE_INT_H_ */
