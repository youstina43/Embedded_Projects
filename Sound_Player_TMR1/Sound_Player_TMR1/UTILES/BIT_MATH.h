/*
 * BIT_MATH.h
 *
 * Created: 9/13/2023 11:33:06 PM
 *  Author: Youstina Atef
 */ 


#ifndef BIT_MATH_H_
#define BIT_MATH_H_


#define SET_BIT(REG, BIT_NO)		((REG) |= (1<<(BIT_NO)))
#define CLEAR_BIT(REG, BIT_NO)		((REG) &= (~(1<<(BIT_NO))))
#define TOGGLE_BIT(REG, BIT_NO)		((REG) ^= (1<<(BIT_NO)))
#define GET_BIT(REG, BIT_NO)		(((REG)>>(BIT_NO)) & 1)
#define TOG_BIT(REG,BIT_NO)    REG^=(1<<BIT_NO)


#endif /* BIT_MATH_H_ */