/*
 * TIMER0_Programc.c
 *
 * Created: 9/17/2023 11:26:33 AM
 *  Author: youstina
 */ 
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "TIMER0_Interface.h"
#include "TIMER0_Confg.h"
#include "TIMER0_Private.h"

u16 private_counterCTC;
static void(*Private_callbackPTR)(void)=NULL;
static void(*Private_callbackCTCPTR)(void)=NULL;

void TMR0_voidInit(void)
{   
#if TMR0_MODE == TMR0_NORMAL_MODE
	//NORMAL MODE
	CLEAR_BIT (TCCR0,WGM00);
	CLEAR_BIT (TCCR0,WGM01);
	
	TCNT0 = PRELOAD_VALUE;
	//ENABLE INTERRUPT
	SET_BIT (TIMSK,TOIE0);
#elif TMR0_MODE == TMR0_CTC_MODE
CLEAR_BIT (TCCR0,WGM00);
SET_BIT (TCCR0,WGM01);
SET_BIT (TIMSK,OCIE0);

#elif TMR0_MODE == TMR0_FAST_PWM_MODE
SET_BIT (TCCR0,WGM00);
SET_BIT (TCCR0,WGM01);
  #if TMR0_PWM_ACTION == TMR0_INVERTED
  SET_BIT (TCCR0,COM00);
  SET_BIT (TCCR0,COM01);
  #elif TMR0_PWM_ACTION == TMR0_NON_INVERTED
  CLEAR_BIT (TCCR0,COM00);
  SET_BIT (TCCR0,COM01);
  #endif

#endif
}
void TMR0_voidSetDutyCycleFastPWM(u8 copy_DutyCycle)
{
	if (copy_DutyCycle<=100)
	{
		#if TMR0_PWM_ACTION == TMR0_NON_INVERTED
	OCR0 = (((u16)copy_DutyCycle*256)/100)-1;
			#elif TMR0_PWM_ACTION == TMR0_INVERTED
	copy_DutyCycle =100-copy_DutyCycle;
		OCR0 = (((u16)copy_DutyCycle*256)/100)-1;
#endif
	

	}
}
void TMR0_voidStart(void)
{   //64 PRESCALLER
	SET_BIT(TCCR0,CS00);
	SET_BIT(TCCR0,CS01);
	CLEAR_BIT(TCCR0,CS02);

}

void TMR0_voidStop(void)
{
	CLEAR_BIT(TCCR0,CS00);
	CLEAR_BIT(TCCR0,CS01);
	CLEAR_BIT(TCCR0,CS02);
}

void TMR0_voidSetCompareMatchValue(u8 copy_compareValue)
{
	OCR0=copy_compareValue;
}
void TMR0_voidSetCallBack(void(*ptrfun)(void))
{     if (ptrfun != NULL)
		
		{ 
			Private_callbackPTR = ptrfun;
		}
}
void TMR0_voidSetCallBackCTC(void(*ptrfun)(void))
{
	if (ptrfun != NULL)
	
	{
		Private_callbackCTCPTR = ptrfun;
	}
}

void TMR0_voidSetDelay_ms_usingCTC(u16 COPY_delayTime)
{   //shoud presacler 64 tick time 4
	OCR0=TMR0_CTC_COUNTER;
	private_counterCTC = COPY_delayTime;
	
	
}
void __vector_11(void) __attribute__ ((signal));
void __vector_11(void) 
{
	static u16 count=0;
	count++;
	if(count == TMR0_OVER_FLOW_COUNTER)
	{
		count=0;
		TCNT0=PRELOAD_VALUE;
		if (Private_callbackPTR != NULL)
		{
			Private_callbackPTR();
		}
		
	}
}


void __vector_10(void) __attribute__ ((signal));
void __vector_10(void)
{
	static u16 CTC_count=0;
	CTC_count++;
	if(CTC_count == private_counterCTC)
	{
		CTC_count=0;
		
		if (Private_callbackCTCPTR != NULL)
		{
			Private_callbackCTCPTR();
		}
		
	}
}