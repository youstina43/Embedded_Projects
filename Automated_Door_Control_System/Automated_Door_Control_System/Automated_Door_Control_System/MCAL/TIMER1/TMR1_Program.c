

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "TMR1_Interface.h"
#include "TMR1_Private.h"


void TMR1_voidInit(void)
{  //MODE14
	CLEAR_BIT(TCCR1A,WGM10);
	SET_BIT (TCCR1A,WGM11);
	SET_BIT (TCCR1B,WGM12);
	SET_BIT (TCCR1B,WGM13);
	//NON INVERTING MODE 14
	CLEAR_BIT(TCCR1A,COM1A0);
	SET_BIT (TCCR1A,COM1A1);
	
	//ICR
	ICR1_u16 = 4999;
	
}

void TMR1_voidStart(void)
{
	SET_BIT (TCCR1B,CS10);
	SET_BIT (TCCR1B,CS11);
	SET_BIT (TCCR1B,CS12);
}

void TMR1_voidStop(void)
{
	CLEAR_BIT (TCCR1B,CS10);
	CLEAR_BIT (TCCR1B,CS11);
	CLEAR_BIT (TCCR1B,CS12);
}

void TMR1_voidSetOutputCompareMatchValueA(u16 copy_u16compareValue)
{
	OCR1A_u16 = copy_u16compareValue;
}