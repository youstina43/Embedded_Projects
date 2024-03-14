/*
 * TIMER0_Private.h
 *
 * Created: 9/17/2023 11:26:56 AM
 *  Author: youstina
 */ 


#ifndef TIMER0_PRIVATE_H_
#define TIMER0_PRIVATE_H_

#define TCCR0   (*((volatile u8 *)0x53))
#define TCNT0   (*((volatile u8 *)0x52))
#define OCR0    (*((volatile u8 *)0x5C))
#define TIMSK   (*((volatile u8 *)0x59))
#define TIFR    (*((volatile u8 *)0x58))

//Timer/Counter Control Register – TCCR0
#define  WGM00 6
#define WGM01  3

#define CS00  0
#define CS01  1
#define CS02   2

#define COM00  4
#define COM01  5

//Timer/Counter Interrupt Mask Register – TIMSK
#define TOIE0  0
#define OCIE0  1

//Timer/Counter Interrupt Flag Register – TIFR
#define TOV0  0
#define OCF0  1


#define TMR0_CTC_MODE      2
#define TMR0_NORMAL_MODE   1

#define TMR0_FAST_PWM_MODE 3

#define TMR0_NON_INVERTED 0
#define TMR0_INVERTED      1

#endif /* TIMER0_PRIVATE_H_ */