//Ahmed samir el dakak  "E.s"

#ifndef   _BITMATH_h
#define  _BITMATH_h

//typedef unsigned short int u8
#define SET_BIT(var,bitnum)     var|=(1<<bitnum)
#define CLR_BIT(var,bitnum)     var&=(~(1<<bitnum))
#define TOGGLE(var,bitnum)		var^=(1<<bitnum)
#define GET_BIT(var,bitnum)		((var&(1<<bitnum))>>bitnum)
#define SHIFT_LEFT(var,shift)   var=((var<<shift) | (var>>(sizeof(var)-shift)))
#define BIT_CONC(B7,B6,B5,B4,B3,B2,B1,B0)		CONC_HELP(B7,B6,B5,B4,B3,B2,B1,B0)
#define CONC_HELP(B7,B6,B5,B4,B3,B2,B1,B0)		0b##B7##B6##B5##B4##B3##B2##B1##B0


void MATH_ShiftUp_arr(u8* ArrPtrCpy);
void MATH_ShiftDown_arr(u8* ArrPtrCpy);


#endif

