/*
 * TMR1_Interface.h
 *
 * Created: 9/18/2023 3:21:01 PM
 *  Author: YOUSTINA
 */ 


#ifndef TMR1_INTERFACE_H_
#define TMR1_INTERFACE_H_

void TMR1_voidInit(void);

void TMR1_voidStart(void);

void TMR1_voidStop(void);

void TMR1_voidSetOutputCompareMatchValueA(u16 Cpy_u16DutyCycle);
void TMR1_SetValueICR1(u16 copy_Frequancy);



#endif /* TMR1_INTERFACE_H_ */