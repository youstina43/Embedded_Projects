/*
 * TIMER0_Interface.h
 *
 * Created: 9/17/2023 11:27:15 AM
 *  Author: youstina
 */ 


#ifndef TIMER0_INTERFACE_H_
#define TIMER0_INTERFACE_H_

void TMR0_voidInit(void);

void TMR0_voidStart(void);

void TMR0_voidStop(void);

void TMR0_voidSetDelay_ms_usingCTC(u16 COPY_delayTime);

void TMR0_voidSetCallBack(void(*ptrfun)(void));

void TMR0_voidSetCallBackCTC(void(*ptrfun)(void));

void TMR0_voidSetCompareMatchValue(u8 copy_compareValue);

void TMR0_voidSetDutyCycleFastPWM(u8 copy_DutyCycle);


#endif /* TIMER0_INTERFACE_H_ */