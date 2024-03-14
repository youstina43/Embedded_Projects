/*
 * ADC_Program.c
 *
 * Created: 9/16/2023 8:49:44 AM
 *  Author: youstina 
 */ 
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "ADC_Interface.h"
#include "ADC_Confg.h"
#include "ADC_Private.h"


void ADC_init(const ADC_ConfigType *Config_Ptr)
{
	/* Choosing the Reference voltage */
	ADMUX = (ADMUX & 0x3F) |(Config_Ptr->ref_volt<<6);

	/* Activating the ADC */
	SET_BIT(ADCSRA,ADEN);

	/* Setting F_ADC = F_CPU/x */
	ADCSRA = (ADCSRA & 0xF8) | Config_Ptr->prescaler;

}


u16 ADC_readChannel(u8 channel_num)
{
	ADMUX &= 0xE0; /* Clearing the first 5 bits */
	ADMUX = ADMUX | channel_num; /* Choosing which channel will be used*/
	SET_BIT(ADCSRA,ADSC); /* Start Conversion   */

	while(GET_BIT(ADCSRA,ADIF)==0); /* Based ON pulling method */

	SET_BIT(ADCSRA,ADIF); /* Clearing the flag register */

	return ADC; /* Read the digital value from the data register */
}
