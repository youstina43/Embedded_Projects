/*
 * KEY_Confg.h
 *
 * Created: 9/14/2023 2:22:25 AM
 *  Author: youstina atef
 */ 


#ifndef KEY_CONFG_H_
#define KEY_CONFG_H_

#include "DIO_Interface.h"


#define ROWS_PORT       DIO_PORTC
#define KPD_R1_PIN 		DIO_PIN5
#define KPD_R2_PIN 		DIO_PIN4
#define KPD_R3_PIN 		DIO_PIN3
#define KPD_R4_PIN 		DIO_PIN2

#define COLS_PORT       DIO_PORTD
#define KPD_C1_PIN 		DIO_PIN7
#define KPD_C2_PIN 		DIO_PIN6
#define KPD_C3_PIN 		DIO_PIN4
#define KPD_C4_PIN 		DIO_PIN3




#define KPD_KEYS 	{{'7','8','9','/'}, {'4','5','6','*'},{'1','2','3','-'},{'C','0','=','+'}}



#define KEYPAD_COLUMN_START KPD_C1_PIN
#define KEYPAD_COLUMN_END   KPD_C4_PIN

/***************************************************************************************/

#define KEYPAD_ROW_START KPD_R1_PIN
#define KEYPAD_ROW_END   KPD_R4_PIN

/***************************************************************************************/

#define KEYPAD_ROWS_NO       (u8)4
#define KEYPAD_COLUMNS_NO    (u8)4

#define KEYPAD_NOT_PRESSED   (u8)0xff

/***************************************************************************************/

#endif /* KEY_CONFG_H_ */