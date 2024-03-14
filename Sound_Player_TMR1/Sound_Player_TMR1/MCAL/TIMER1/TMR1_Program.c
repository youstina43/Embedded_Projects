/*
 * TMR1_Program.c
 *
 * Created: 9/18/2023 3:21:40 PM
 *  Author: YOUSTINA
 */ 

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "TMR1_Interface.h"
#include "TMR1_Confg.h"
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
}

void TMR1_SetValueICR1(u16 copy_Frequancy)
{    
	//ICR
	ICR1_u16 = (((u32)1000000/(u32)copy_Frequancy) / 4)-1;
}

void TMR1_voidStart(void)
{
	SET_BIT (TCCR1B,CS10);
	SET_BIT (TCCR1B,CS11);
	CLEAR_BIT (TCCR1B,CS12);
}

void TMR1_voidStop(void)
{
	CLEAR_BIT (TCCR1B,CS10);
	CLEAR_BIT (TCCR1B,CS11);
	CLEAR_BIT (TCCR1B,CS12);
}

void TMR1_voidSetOutputCompareMatchValueA( u16 Cpy_u16DutyCycle)
{
	OCR1A_u16 = (u16)(((u32)Cpy_u16DutyCycle*(u32)(ICR1_u16+1))/100);
}