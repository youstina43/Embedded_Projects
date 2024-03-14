/*
 * ADC_Private.h
 *
 * Created: 9/16/2023 8:50:38 AM
 *  Author: youstina atef 
 */ 


#ifndef ADC_PRIVATE_H_
#define ADC_PRIVATE_H_

#define  ADMUX (*( (volatile u8 *) 0x27))

#define  REFS1		7
#define  REFS0		6
#define  ADLAR		5
#define  MUX4		4
#define  MUX3	    3
#define  MUX2	   	2
#define  MUX1		1
#define  MUX0		0

#define  ADCSRA  (*((volatile u8 *)0x26))
#define  ADCH  (*((volatile u8 *)0x25))
#define  ADCL  (*((volatile u8 *)0x24))


#define  ADEN		7
#define  ADSC		6
#define  ADATE		5
#define  ADIF		4
#define  ADIE	    3
#define  ADPS2	   	2
#define  ADPS1		1
#define  ADPS0		0

#define ADC (*(volatile u16 *) (0x24) )	  // ADCL  + ADCH

#define  SFIOR (*((volatile u8 *)(0x50)))

#define  ADTS2 7
#define  ADTS1 6
#define  ADTS0 5


#define ADC_BIT_MASKING_PRESCALER     0xF8
#define ADC_BIT_MASKING_CHANNEL       0x07
#define ADC_BIT_MASKING_REG_CHANNEL   0xE0


#endif /* ADC_PRIVATE_H_ */