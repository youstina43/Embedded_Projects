/*
 * ADC_Interface.h
 *
 * Created: 9/16/2023 8:50:07 AM
 *  Author: EL-BOSTAN
 */ 


#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

#include "ADC_Confg.h"

void ADC_init(const ADC_ConfigType *Config_Ptr);


u16 ADC_readChannel(u8 channel_num);


#endif /* ADC_INTERFACE_H_ */