/*
 * ADC_Confg.h
 *
 * Created: 9/16/2023 8:51:01 AM
 *  Author: youstina atef 
 */ 


#ifndef ADC_CONFG_H_
#define ADC_CONFG_H_


/* Main Definitions */
#define ADC_CHANNEL_ZERO_ID			0
#define ADC_CHANNEL_ONE_ID			1
#define ADC_CHANNEL_TWO_ID			2
#define ADC_CHANNEL_THREE_ID		3
#define ADC_CHANNEL_FOUR_ID			4
#define ADC_CHANNEL_FIVE_ID			5
#define ADC_CHANNEL_SIX_ID			6
#define ADC_CHANNEL_SEVEN_ID		7
#define ADC_MAXIMUM_VALUE    1023
#define ADC_REF_VOLT_VALUE   5
/* Modifiable Definitions*/
#define ADC_INPUT_PORT_ID 			DIO_PORTA
#define ADC_REF_VOLTAGE_ID			AVCC

/**-------------------------Enum Section----------------------------**/

/*
 * Description:
 * Selecting the reference voltage
 */
typedef enum
{
	AREF=0,AVCC,Reserved,Internal_Ref
}ADC_ReferenceVoltage;

/*
 * Description:
 * Selecting the clock of ADC
 */
typedef enum
{
	F_ADC2=1,F_ADC4,F_ADC8,F_ADC16,F_ADC32,F_ADC64,F_ADC128
}ADC_Prescaler;

/**-------------------------Struct Section--------------------------**/

/*
 * Description:
 * Giving Values when Initializing it
 * Configure the required ADC settings
 */
typedef struct
{
	ADC_ReferenceVoltage ref_volt;
	ADC_Prescaler prescaler;
}ADC_ConfigType;



#endif /* ADC_CONFG_H_ */