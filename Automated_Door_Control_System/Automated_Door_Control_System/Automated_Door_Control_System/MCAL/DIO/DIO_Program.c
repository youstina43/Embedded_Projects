/*
 * DIO_Program.c
 *
 * Created: 9/13/2023 11:52:39 PM
 *  Author: Youstina Atef
 */ 
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_Interface.h"
#include "DIO_Confg.h"
#include "DIO_Private.h"

void DIO_init(void)
{
	/*Set Initial Directions FOR Pins */
	DDRA = CONC(DIO_PA7_INITIAL_DIRECTION,DIO_PA6_INITIAL_DIRECTION,DIO_PA5_INITIAL_DIRECTION,DIO_PA4_INITIAL_DIRECTION,
	DIO_PA3_INITIAL_DIRECTION,DIO_PA2_INITIAL_DIRECTION,DIO_PA1_INITIAL_DIRECTION,DIO_PA0_INITIAL_DIRECTION);
	
	DDRB = CONC(DIO_PB7_INITIAL_DIRECTION,DIO_PB6_INITIAL_DIRECTION,DIO_PB5_INITIAL_DIRECTION,DIO_PB4_INITIAL_DIRECTION,
	DIO_PB3_INITIAL_DIRECTION,DIO_PB2_INITIAL_DIRECTION,DIO_PB1_INITIAL_DIRECTION,DIO_PB0_INITIAL_DIRECTION);
	
	DDRC = CONC(DIO_PC7_INITIAL_DIRECTION,DIO_PC6_INITIAL_DIRECTION,DIO_PC5_INITIAL_DIRECTION,DIO_PC4_INITIAL_DIRECTION,
	DIO_PC3_INITIAL_DIRECTION,DIO_PC2_INITIAL_DIRECTION,DIO_PC1_INITIAL_DIRECTION,DIO_PC0_INITIAL_DIRECTION);
	
	DDRD = CONC(DIO_PD7_INITIAL_DIRECTION,DIO_PD6_INITIAL_DIRECTION,DIO_PD5_INITIAL_DIRECTION,DIO_PD4_INITIAL_DIRECTION,
	DIO_PD3_INITIAL_DIRECTION,DIO_PD2_INITIAL_DIRECTION,DIO_PD1_INITIAL_DIRECTION,DIO_PD0_INITIAL_DIRECTION);
	
	/*Set Initial Values FOR Pins */
	PORTA = CONC(DIO_PA7_INITIAL_VALUE,DIO_PA6_INITIAL_VALUE,DIO_PA5_INITIAL_VALUE,DIO_PA4_INITIAL_VALUE,
	DIO_PA3_INITIAL_VALUE,DIO_PA2_INITIAL_VALUE,DIO_PA1_INITIAL_VALUE,DIO_PA0_INITIAL_VALUE);
	
	PORTB = CONC(DIO_PB7_INITIAL_VALUE,DIO_PB6_INITIAL_VALUE,DIO_PB5_INITIAL_VALUE,DIO_PB4_INITIAL_VALUE,
	DIO_PB3_INITIAL_VALUE,DIO_PB2_INITIAL_VALUE,DIO_PB1_INITIAL_VALUE,DIO_PB0_INITIAL_VALUE);
	
	PORTC = CONC(DIO_PC7_INITIAL_VALUE,DIO_PC6_INITIAL_VALUE,DIO_PC5_INITIAL_VALUE,DIO_PC4_INITIAL_VALUE,
	DIO_PC3_INITIAL_VALUE,DIO_PC2_INITIAL_VALUE,DIO_PC1_INITIAL_VALUE,DIO_PC0_INITIAL_VALUE);
	
	PORTD = CONC(DIO_PD7_INITIAL_VALUE,DIO_PD6_INITIAL_VALUE,DIO_PD5_INITIAL_VALUE,DIO_PD4_INITIAL_VALUE,
	DIO_PD3_INITIAL_VALUE,DIO_PD2_INITIAL_VALUE,DIO_PD1_INITIAL_VALUE,DIO_PD0_INITIAL_VALUE);
}

void DIO_setPinDirection(u8 PortId, u8 PinId, u8 PinDirection)
{
	if((PortId<=3)&&(PinId<=7)&&((DIO_PIN_OUTPUT==PinDirection)||(DIO_PIN_INPUT==PinDirection)))
	{
		switch(PortId)
		{
			case DIO_PORTA:
			if(DIO_PIN_OUTPUT == PinDirection)
			{
				SET_BIT(DDRA,PinId);
			}
			else
			{
				CLEAR_BIT(DDRA,PinId);
			}
			break;

			case DIO_PORTB:
			if(DIO_PIN_OUTPUT == PinDirection)
			{
				SET_BIT(DDRB,PinId);
			}
			else
			{
				CLEAR_BIT(DDRB,PinId);
			}
			break;

			case DIO_PORTC:
			if(DIO_PIN_OUTPUT == PinDirection)
			{
				SET_BIT(DDRC,PinId);
			}
			else
			{
				CLEAR_BIT(DDRC,PinId);
			}
			break;

			case DIO_PORTD:
			if(DIO_PIN_OUTPUT == PinDirection)
			{
				SET_BIT(DDRD,PinId);
			}
			else
			{
				CLEAR_BIT(DDRD,PinId);
			}
			break;
		}
	}

	else
	{
		// Do Nothing
	}
}


void DIO_setPinValue(u8 PortId, u8 PinId, u8 PinValue)
{
	switch(PortId)
	{
		case DIO_PORTA:
		if(DIO_PIN_HIGH == PinValue)
		{
			SET_BIT(PORTA,PinId);
		}
		else
		{
			CLEAR_BIT(PORTA,PinId);
		}
		break;

		case DIO_PORTB:
		if(DIO_PIN_HIGH == PinValue)
		{
			SET_BIT(PORTB,PinId);
		}
		else
		{
			CLEAR_BIT(PORTB,PinId);
		}
		break;

		case DIO_PORTC:
		if(DIO_PIN_HIGH == PinValue)
		{
			SET_BIT(PORTC,PinId);
		}
		else
		{
			CLEAR_BIT(PORTC,PinId);
		}
		break;

		case DIO_PORTD:
		if(DIO_PIN_HIGH == PinValue)
		{
			SET_BIT(PORTD,PinId);
		}
		else
		{
			CLEAR_BIT(PORTD,PinId);
		}
		break;
	}
}


void DIO_getPinValue(u8 PortId, u8 PinId, u8* PinValue)
{
	switch(PortId)
	{
		case DIO_PORTA:
		*PinValue = GET_BIT(PINA,PinId);
		break;

		case DIO_PORTB:
		*PinValue = GET_BIT(PINB,PinId);
		break;

		case DIO_PORTC:
		*PinValue = GET_BIT(PINC,PinId);
		break;

		case DIO_PORTD:
		*PinValue = GET_BIT(PIND,PinId);
		break;
	}
}


void DIO_togglePinValue(u8 PortId, u8 PinId)
{
	switch(PortId)
	{
		case DIO_PORTA:
		TOG_BIT(PORTA,PinId);
		break;

		case DIO_PORTB:
		TOG_BIT(PORTB,PinId);
		break;

		case DIO_PORTC:
		TOG_BIT(PORTC,PinId);
		break;

		case DIO_PORTD:
		TOG_BIT(PORTD,PinId);
		break;
	}
}


void DIO_activePinInPullUpResistance(u8 PortId, u8 PinId)
{
	switch(PortId)
	{
		case DIO_PORTA:
		SET_BIT(PORTA,PinId);
		break;

		case DIO_PORTB:
		SET_BIT(PORTB,PinId);
		break;

		case DIO_PORTC:
		SET_BIT(PORTC,PinId);
		break;

		case DIO_PORTD:
		SET_BIT(PORTD,PinId);
		break;
	}
}


/* Port Apis */
void DIO_setPortDirection(u8 PortId, u8 PortDirection)
{
	if((PortId<=3) && ((DIO_PORT_OUTPUT == PortDirection) || (DIO_PORT_INPUT == PortDirection)))
	{
		switch(PortId)
		{
			case 0:
			if(DIO_PORT_OUTPUT == PortDirection)
			{
				DDRA = 0xff;
			}
			else
			{
				DDRA = 0x00;
			}
			break;

			case 1:
			if(DIO_PORT_OUTPUT == PortDirection)
			{
				DDRB = 0xff;
			}
			else
			{
				DDRB = 0x00;
			}
			break;

			case 2:
			if(DIO_PORT_OUTPUT == PortDirection)
			{
				DDRC = 0xff;
			}
			else
			{
				DDRC = 0x00;
			}
			break;

			case 3:
			if(DIO_PORT_OUTPUT == PortDirection)
			{
				DDRD = 0xff;
			}
			else
			{
				DDRD = 0x00;
			}
			break;
		}
	}
}


void DIO_setPortValue(u8 PortId, u8 PortValue)
{
	if(PortId<=3)
	{
		switch(PortId)
		{
			case 0:
			PORTA = PortValue;
			break;

			case 1:
			PORTB = PortValue;
			break;

			case 2:
			PORTC = PortValue;
			break;

			case 3:
			PORTD = PortValue;
			break;
		}
	}
}


void DIO_getPortValue(u8 PortId, u8* PortValue)
{
	if((PortId<=3) && (PortValue != 0))
	{
		switch(PortId)
		{
			case 0:
			*PortValue = PINA;
			break;

			case 1:
			*PortValue = PINB;
			break;

			case 2:
			*PortValue = PINC;
			break;

			case 3:
			*PortValue = PIND;
			break;
		}
	}
}


void DIO_togglePortValue(u8 PortId)
{
	if(PortId<=3)
	{
		switch(PortId)
		{
			case 0:
			PORTA = ~PORTA;
			break;

			case 1:
			PORTB = ~PORTB;
			break;

			case 2:
			PORTC = ~PORTC;
			break;

			case 3:
			PORTD = ~PORTD;
			break;
		}
	}
}


void DIO_activePortInPullUpResistance(u8 PortId)
{
	if(PortId<=3)
	{
		switch(PortId)
		{
			case 0:
			PORTA = 0xff;
			break;

			case 1:
			PORTB = 0xff;
			break;

			case 2:
			PORTC = 0xff;
			break;

			case 3:
			PORTD = 0xff;
			break;
		}
	}
}