/*
 * ServoM_Program.c
 *
 * Created: 9/23/2023 3:48:12 AM
 *  Author: youstina
 */ 

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_Interface.h"

#include "TMR1_Interface.h"
#include "TMR1_Private.h"

#include "ServoM_Interface.h"

void SRVM_voidOn(u8 Copy_u8Angle)
{
	/* TMR1 init at pwm mode 14 */
//MODE14
CLEAR_BIT(TCCR1A,WGM10);
SET_BIT (TCCR1A,WGM11);
SET_BIT (TCCR1B,WGM12);
SET_BIT (TCCR1B,WGM13);
//NON INVERTING MODE 14
CLEAR_BIT(TCCR1A,COM1A0);
SET_BIT (TCCR1A,COM1A1);


	/* Set pwm fre. = 50 */
        //ICR
        ICR1_u16 = 4999;
		
	/* Set pwm duty cycle between 5 : 10
	 depend on desired angle[0 : 180] */
	
		f32 Duty_Cycle = 5.0 +  (Copy_u8Angle * 5.0 / 180.0); // if angle -90-->0-->90

		OCR1A_u16 = ( (Duty_Cycle/100.0) * (ICR1_u16+1)) - 1;
	
	

	/* TMR1 start */
	TMR1_voidStart();
}


void SRVM_voidOff(void)
{
	/* TMR1 stop */
	TMR1_voidStop();
	
}


