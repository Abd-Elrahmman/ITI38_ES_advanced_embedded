#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_int.h"
#include "UART.h"
#include "TIM_int.h"
#include "GIE_int.h"
#include "task1.h"
#include "task2.h"
#include "Clock_adjust.h"
#include "taskSwitchLed.h"
#include "KP_int.h"
#include "sw.h"
#include "protocol.h"
#include "UART_Rx_TEST.h"
void main(void)
{
	DIO_voidInitialize();

	TIMER0_voidInit();
	/*enable uart*/
	UART_Init();
	/*Setting Internal PullUp Resistor for The keypad INPUT ROWS */
	DIO_voidSetPinValue(DIO_u8_PIN_28, DIO_u8_HIGH);
	DIO_voidSetPinValue(DIO_u8_PIN_29, DIO_u8_HIGH);
	DIO_voidSetPinValue(DIO_u8_PIN_30, DIO_u8_HIGH);
	DIO_voidSetPinValue(DIO_u8_PIN_31, DIO_u8_HIGH);
	/*Setting Internal PullUp Resistor for The Switch1, 2 INPUT */
	DIO_voidSetPinValue(DIO_u8_PIN_17, DIO_u8_HIGH);
	DIO_voidSetPinValue(DIO_u8_PIN_18, DIO_u8_HIGH);


	GIE_ENABLE();
	OS_voidStart();

}
