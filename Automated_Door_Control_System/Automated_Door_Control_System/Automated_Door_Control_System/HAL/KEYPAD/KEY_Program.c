/*
 * KEY_Program.c
 *
 * Created: 9/14/2023 2:21:41 AM
 *  Author: youstina atef
 */ 

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_Interface.h"

#include "KEY_Interface.h"
#include "KEY_Confg.h"

#include <util/delay.h>

u8 COL_ARR[4]={
	KPD_C1_PIN,KPD_C2_PIN,KPD_C3_PIN,KPD_C4_PIN
};

u8 ROW_ARR[4]={
	KPD_R1_PIN,KPD_R2_PIN,KPD_R3_PIN,KPD_R4_PIN
};
	
void KEY_VoidInit(void)
{
		//Setting Rows to Input Pullup
	DIO_setPinDirection(ROWS_PORT,KPD_R1_PIN,DIO_INITIAL_OUTPUT);
	DIO_setPinDirection(ROWS_PORT,KPD_R2_PIN,DIO_INITIAL_OUTPUT);
	DIO_setPinDirection(ROWS_PORT,KPD_R3_PIN,DIO_INITIAL_OUTPUT);
	DIO_setPinDirection(ROWS_PORT,KPD_R4_PIN,DIO_INITIAL_OUTPUT);
	
	DIO_setPinValue(ROWS_PORT,KPD_R1_PIN,DIO_INITIAL_OUTPUT_HIGH);
	DIO_setPinValue(ROWS_PORT,KPD_R2_PIN,DIO_INITIAL_OUTPUT_HIGH);
	DIO_setPinValue(ROWS_PORT,KPD_R3_PIN,DIO_INITIAL_OUTPUT_HIGH);
	DIO_setPinValue(ROWS_PORT,KPD_R4_PIN,DIO_INITIAL_OUTPUT_HIGH);
	//Setting Columns to Output High
	DIO_setPinDirection(COLS_PORT,KPD_C1_PIN,DIO_INITIAL_INPUT);
	DIO_setPinDirection(COLS_PORT,KPD_C2_PIN,DIO_INITIAL_INPUT);
	DIO_setPinDirection(COLS_PORT,KPD_C3_PIN,DIO_INITIAL_INPUT);
	DIO_setPinDirection(COLS_PORT,KPD_C4_PIN,DIO_INITIAL_INPUT);
	
    DIO_setPinValue(COLS_PORT,KPD_C1_PIN,DIO_INITIAL_INPUT_PULLUP);
    DIO_setPinValue(COLS_PORT,KPD_C2_PIN,DIO_INITIAL_INPUT_PULLUP);
    DIO_setPinValue(COLS_PORT,KPD_C3_PIN,DIO_INITIAL_INPUT_PULLUP);
    DIO_setPinValue(COLS_PORT,KPD_C4_PIN,DIO_INITIAL_INPUT_PULLUP);


}
u8 Key_U8PressedKey()
{
	u8 Local_u8PressedSwitch = KEYPAD_NOT_PRESSED;
	u8 Local_u8aKeyPadMap[KEYPAD_ROWS_NO][KEYPAD_COLUMNS_NO] = KPD_KEYS;
	u8 Local_u8CurrentCol;
	u8 Local_u8CurrentRow;
	u8 Local_u8CurrentStatus;

		for (Local_u8CurrentRow = 0 ;Local_u8CurrentRow < KEYPAD_ROWS_NO ;Local_u8CurrentRow++)

	{
		DIO_setPinValue(ROWS_PORT,ROW_ARR[Local_u8CurrentRow],DIO_PIN_LOW);
	for (Local_u8CurrentCol = 0;Local_u8CurrentCol < KEYPAD_COLUMNS_NO ;Local_u8CurrentCol++)

		{
			DIO_getPinValue(COLS_PORT,COL_ARR[Local_u8CurrentCol] , &Local_u8CurrentStatus);
			/*If Switch is pressed */
			if (Local_u8CurrentStatus == DIO_PIN_LOW   ) //as pin is pull up
			{  
				_delay_ms(2500);
				/*Wait For Debouncing*/
				/*If Switch is pressed */
			if (Local_u8CurrentStatus == DIO_PIN_LOW ) //as pin is pull up
				{
			Local_u8PressedSwitch = Local_u8aKeyPadMap[Local_u8CurrentRow][Local_u8CurrentCol];

				}
			}
		}
		/*Deactivate the column*/
		DIO_setPinValue(ROWS_PORT,ROW_ARR[Local_u8CurrentRow],DIO_PIN_HIGH);

	}
	return Local_u8PressedSwitch ;
}