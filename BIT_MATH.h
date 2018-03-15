#ifndef _BIT_MATH_H
#define _BIT_MATH_H

#define SET_BIT(var,bitno)       (var|=(1<<bitno))
#define CLR_BIT(var,bitno)       (var&=~(1<<bitno))
#define TOG_BIT(var,bitno)    	 (var^=(1<<bitno))
#define GET_BIT(var,bitno)       (1&(var>>bitno))

#define BIT_CONC(B7,B6,B5,B4,B3,B2,B1,B0) CONC_HELP(B7,B6,B5,B4,B3,B2,B1,B0)
#define CONC_HELP(B7,B6,B5,B4,B3,B2,B1,B0) 0b##B7##B6##B5##B4##B3##B2##B1##B0


#endif
