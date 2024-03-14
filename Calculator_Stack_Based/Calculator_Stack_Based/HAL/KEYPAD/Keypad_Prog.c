
#include "Keypad_Config.h"
#include "Keypad_Interface.h"
#include "Keypad_Private.h"
#define PORTC_REG    *(volatile u8*)0x35

u8 Local_U8_KeypadRowPins[4] = { KEYPAD_R0_PIN , KEYPAD_R1_PIN , KEYPAD_R2_PIN , KEYPAD_R3_PIN };
u8 Local_U8_KeypadColPins[4] = { KEYPAD_C0_PIN , KEYPAD_C1_PIN , KEYPAD_C2_PIN , KEYPAD_C3_PIN };
#if   KEYPAD_MODEL   ==   KEYPAD_MODEL_A
	u8 Local_U8_KeypadValue [4][4] = {{ '1' , '2' , '3' , 'A' },
			                          { '4' , '5' , '6' , 'B' },
							          { '7' , '8' , '9' , 'C' },
						         	  { '*' , '0' , '#' , 'D' }};
#elif KEYPAD_MODEL   ==   KEYPAD_MODEL_B
	u8 Local_U8_KeypadValue [4][4] = {{ '7' , '8' , '9' , '/' },
			                          { '4' , '5' , '6' , '*' },
							          { '1' , '2' , '3' , '-' },
							          { '(' , ')' , '=' , '+' }};
#endif
	u8 Local_U8_Reading    = KEYPAD_RELEASED;
	u8 Local_U8_RowCounter = 0;
	u8 Local_U8_ColCounter = 0;

void H_KeyPad_Void_KeyPadInit(void)
{
	M_DIO_Void_SetPinDirection(KEYPAD_R0_PIN,OUTPUT);
	M_DIO_Void_SetPinDirection(KEYPAD_R1_PIN,OUTPUT);
	M_DIO_Void_SetPinDirection(KEYPAD_R2_PIN,OUTPUT);
	M_DIO_Void_SetPinDirection(KEYPAD_R3_PIN,OUTPUT);

	M_DIO_Void_SetPinValue(KEYPAD_R0_PIN,HIGH);
	M_DIO_Void_SetPinValue(KEYPAD_R1_PIN,HIGH);
	M_DIO_Void_SetPinValue(KEYPAD_R2_PIN,HIGH);
	M_DIO_Void_SetPinValue(KEYPAD_R3_PIN,HIGH);

	M_DIO_Void_SetPinDirection(KEYPAD_C0_PIN,INPUT);
	M_DIO_Void_SetPinDirection(KEYPAD_C1_PIN,INPUT);
	M_DIO_Void_SetPinDirection(KEYPAD_C2_PIN,INPUT);
	M_DIO_Void_SetPinDirection(KEYPAD_C3_PIN,INPUT);
}

u8   H_KeyPad_U8_KeyPadRead(void)
{

	for(Local_U8_RowCounter = 0 ; Local_U8_RowCounter <= 3 ; Local_U8_RowCounter++)
	{
		  M_DIO_Void_SetPinValue(Local_U8_KeypadRowPins[Local_U8_RowCounter],LOW);


		for(Local_U8_ColCounter = 0 ; Local_U8_ColCounter <= 3 ; Local_U8_ColCounter++)
		{
			if(M_DIO_Void_GetPinValue(Local_U8_KeypadColPins[Local_U8_ColCounter]) == KEYPAD_PRESSED)
			{
				_delay_ms(30);
				if(M_DIO_Void_GetPinValue(Local_U8_KeypadColPins[Local_U8_ColCounter]) == KEYPAD_PRESSED)
				{
					 while(M_DIO_Void_GetPinValue(Local_U8_KeypadColPins[Local_U8_ColCounter]) == KEYPAD_PRESSED);
					 return Local_U8_KeypadValue[Local_U8_RowCounter][Local_U8_ColCounter];
					 break;
				}

			}
		}
		  M_DIO_Void_SetPinValue(Local_U8_KeypadRowPins[Local_U8_RowCounter],HIGH);
		 //SET_BIT(PORTC_REG,Local_U8_KeypadRowPins[Local_U8_RowCounter]);


	}
return Local_U8_Reading;
}


