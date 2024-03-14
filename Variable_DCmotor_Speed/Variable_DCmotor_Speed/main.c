/*
 * Variable_DCmotor_Speed.c
 *
 * Created: 9/21/2023 5:51:12 PM
 * Author : youstina
 */ 

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_Interface.h"
#include "ADC_Interface.h"
#include "ADC_Confg.h" 
#include "TIMER0_Interface.h"

#include <util/delay.h>

int main(void)
{   ADC_ConfigType ADC0 ;
	ADC0.prescaler = F_ADC64;
	ADC0.ref_volt = AVCC;
	
	DIO_init();
	ADC_init(&ADC0);
	TMR0_voidInit();
	TMR0_voidStart();
	u16 AdcReading=0;
	u8 FastDuty=0;
    while (1) 
    {
		AdcReading = ADC_readChannel(ADC_CHANNEL_ZERO_ID);
		FastDuty = (u8)(((f32)(AdcReading*100))/1023);
		TMR0_voidSetDutyCycleFastPWM(FastDuty);
				_delay_ms(1000);

    }
}

