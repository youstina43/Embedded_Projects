/*
 * Sound_Player_TMR1.c
 *
 * Created: 9/21/2023 3:40:12 PM
 * Author : YOUSTINA ATEF
 */ 
#define __DELAY_BACKWARD_COMPATIBLE__

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_Interface.h"
#include "TMR1_Interface.h"

#define F_CPU 16000000UL
#include <util/delay.h>

#define DutyCycle 50
#define REST 0
// Defining frequency of each music note
#define NOTE_C4 262
#define NOTE_D4 294
#define NOTE_E4 330
#define NOTE_F4 349
#define NOTE_G4 392
#define NOTE_A4 440
#define NOTE_B4 494
#define NOTE_C5 523
#define NOTE_D5 587
#define NOTE_E5 659
#define NOTE_F5 698
#define NOTE_G5 784
#define NOTE_A5 880
#define NOTE_B5 988
int melody[] = {
	NOTE_E4, NOTE_G4, NOTE_A4, NOTE_A4, REST,
	NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, REST,
	NOTE_C5, NOTE_D5, NOTE_B4, NOTE_B4, REST,
	NOTE_A4, NOTE_G4, NOTE_A4, REST,
	
	NOTE_E4, NOTE_G4, NOTE_A4, NOTE_A4, REST,
	NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, REST,
	NOTE_C5, NOTE_D5, NOTE_B4, NOTE_B4, REST,
	NOTE_A4, NOTE_G4, NOTE_A4, REST,
	
	NOTE_E4, NOTE_G4, NOTE_A4, NOTE_A4, REST,
	NOTE_A4, NOTE_C5, NOTE_D5, NOTE_D5, REST,
	NOTE_D5, NOTE_E5, NOTE_F5, NOTE_F5, REST,
	NOTE_E5, NOTE_D5, NOTE_E5, NOTE_A4, REST,
	
	NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, REST,
	NOTE_D5, NOTE_E5, NOTE_A4, REST,
	NOTE_A4, NOTE_C5, NOTE_B4, NOTE_B4, REST,
	NOTE_C5, NOTE_A4, NOTE_B4, REST,
	NOTE_A4, NOTE_A4,
	//Repeat of first part
	NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, REST,
	NOTE_C5, NOTE_D5, NOTE_B4, NOTE_B4, REST,
	NOTE_A4, NOTE_G4, NOTE_A4, REST,
	
	NOTE_E4, NOTE_G4, NOTE_A4, NOTE_A4, REST,
	NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, REST,
	NOTE_C5, NOTE_D5, NOTE_B4, NOTE_B4, REST,
	NOTE_A4, NOTE_G4, NOTE_A4, REST,
	
	NOTE_E4, NOTE_G4, NOTE_A4, NOTE_A4, REST,
	NOTE_A4, NOTE_C5, NOTE_D5, NOTE_D5, REST,
	NOTE_D5, NOTE_E5, NOTE_F5, NOTE_F5, REST,
	NOTE_E5, NOTE_D5, NOTE_E5, NOTE_A4, REST,
	
	NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, REST,
	NOTE_D5, NOTE_E5, NOTE_A4, REST,
	NOTE_A4, NOTE_C5, NOTE_B4, NOTE_B4, REST,
	NOTE_C5, NOTE_A4, NOTE_B4, REST,
	//End of Repeat
	NOTE_E5, REST, REST, NOTE_F5, REST, REST,
	NOTE_E5, NOTE_E5, REST, NOTE_G5, REST, NOTE_E5, NOTE_D5, REST, REST,
	NOTE_D5, REST, REST, NOTE_C5, REST, REST,
	NOTE_B4, NOTE_C5, REST, NOTE_B4, REST, NOTE_A4,
	
	NOTE_E5, REST, REST, NOTE_F5, REST, REST,
	NOTE_E5, NOTE_E5, REST, NOTE_G5, REST, NOTE_E5, NOTE_D5, REST, REST,
	NOTE_D5, REST, REST, NOTE_C5, REST, REST,
	NOTE_B4, NOTE_C5, REST, NOTE_B4, REST, NOTE_A4
};

int durations[] = {
	8, 8, 4, 8, 8,
	8, 8, 4, 8, 8,
	8, 8, 4, 8, 8,
	8, 8, 4, 8,	
	8, 8, 4, 8, 8,
	8, 8, 4, 8, 8,
	8, 8, 4, 8, 8,
	8, 8, 4, 8,	
	8, 8, 4, 8, 8,
	8, 8, 4, 8, 8,
	8, 8, 4, 8, 8,
	8, 8, 8, 4, 8,	
	8, 8, 4, 8, 8,
	4, 8, 4, 8,
	8, 8, 4, 8, 8,
	8, 8, 4, 4,	
	4, 8,
	//Repeat of First Part
	8, 8, 4, 8, 8,
	8, 8, 4, 8, 8,
	8, 8, 4, 8,	
	8, 8, 4, 8, 8,
	8, 8, 4, 8, 8,
	8, 8, 4, 8, 8,
	8, 8, 4, 8,	
	8, 8, 4, 8, 8,
	8, 8, 4, 8, 8,
	8, 8, 4, 8, 8,
	8, 8, 8, 4, 8,	
	8, 8, 4, 8, 8,
	4, 8, 4, 8,
	8, 8, 4, 8, 8,
	8, 8, 4, 4,
	//End of Repeat	
	4, 8, 4, 4, 8, 4,
	8, 8, 8, 8, 8, 8, 8, 8, 4,
	4, 8, 4, 4, 8, 4,
	8, 8, 8, 8, 8, 2,	
	4, 8, 4, 4, 8, 4,
	8, 8, 8, 8, 8, 8, 8, 8, 4,
	4, 8, 4, 4, 8, 4,
	8, 8, 8, 8, 8, 2
};

int main(void)
{   DIO_init();
	TMR1_voidInit();
	
	u32 I=0,duration=0;
	
    while (1) 
    {
		//while (melody[I]!='\0')
		//{
			TMR1_SetValueICR1(melody[I]);
			TMR1_voidSetOutputCompareMatchValueA(DutyCycle);
			TMR1_voidStart();
			duration = 1000/durations[I];
			_delay_ms(duration);
			I++;
		//}
    }
	 return 0;
	 
}

