/*
 * Automated_Door_Control_System.c
 *
 * Created: 9/28/2023 9:39:50 AM
 * Author : youstina atef
 */ 

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_Interface.h"
#include "TMR1_Interface.h"

#include "LCD_interface.h"
#include "KEY_Interface.h"
#include "KEY_Confg.h"
#include "ServoM_Interface.h"

#define F_CPU 16000000UL
#include <util/delay.h>
int main(void)
{
    DIO_init();
    TMR1_voidInit();
    LCD_init();
    KEY_VoidInit();
    u8 Predefined_Pass[6] = "12345";
    u8 pass_array[6] = "";
    u8 counter = 0;
    u8 Iterator = 0;
    u8 correctCount = 0;
    u8 falsecount = 0;
    u8 PASS = 0;
    LCD_Clear();
	LCD_GoTo(0,3);
	LCD_WriteString("Enter Password");
	_delay_ms(1500);
	    LCD_Clear();

    while (1)
    {


        if (Iterator < 5)
        {
            if (Key_U8PressedKey() != KEYPAD_NOT_PRESSED)
            {
                PASS = Key_U8PressedKey();
                _delay_ms(350);
                LCD_Write_CHAR(PASS);
                pass_array[Iterator] = PASS;

                if (Predefined_Pass[Iterator] == pass_array[Iterator])
                {
                    correctCount++;
                }
                else
                {
                    falsecount++;
                }

                Iterator++;
            }
        }

        if (Iterator == 5)
        {
            _delay_ms(1000);
            pass_array[5] = '\0';

            if (falsecount > 0)
            {
                LCD_Clear();
                LCD_GoTo(1, 3);
                LCD_WriteString("WRONG PASSWORD");
                LCD_GoTo(2, 3);
                LCD_WriteString("TRY again");
                _delay_ms(1000);
                LCD_Clear();
                counter++;
            }

            if (correctCount == 5)
            {
				LCD_Clear();
                LCD_GoTo(1, 3);
                LCD_WriteString("Welcome");
                DIO_setPinValue(DIO_PORTA, DIO_PIN4, DIO_PIN_HIGH);
				TMR1_voidStart();
				 SRVM_voidOn(180);
                _delay_ms(3500);
				SRVM_voidOn(90);
                LCD_Clear();
				 DIO_setPinValue(DIO_PORTA, DIO_PIN4, DIO_PIN_LOW);
            }
            if (counter == 3)
                {
                    DIO_setPinValue(DIO_PORTB, DIO_PIN7, DIO_PIN_HIGH);
                    DIO_setPinValue(DIO_PORTC, DIO_PIN6, DIO_PIN_HIGH);
                    LCD_GoTo(1, 3);
                    LCD_WriteString("FAILED");
                    _delay_ms(3500);
					DIO_setPinValue(DIO_PORTB, DIO_PIN7, DIO_PIN_LOW);
					DIO_setPinValue(DIO_PORTC, DIO_PIN6, DIO_PIN_LOW);
                    LCD_Clear();
                    counter = 0;
                }
            Iterator = 0;
            correctCount = 0;
            falsecount = 0;
        }
    }

    return 0;
}