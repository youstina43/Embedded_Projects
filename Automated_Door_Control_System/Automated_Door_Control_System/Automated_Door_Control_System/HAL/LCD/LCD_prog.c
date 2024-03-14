/*
* LCD_prog.c
*
* Created: 9/30/2022 9:50:14 PM
*  Author: Youstina Atef
*/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_Interface.h"

#include "LCD_interface.h"

void LCD_init(){
	DIO_setPinDirection(LCD_CMD_PORT,RS_PIN,DIO_PIN_OUTPUT);
	DIO_setPinDirection(LCD_CMD_PORT,RW_PIN,DIO_PIN_OUTPUT);
	DIO_setPinDirection(LCD_CMD_PORT,E_PIN,DIO_PIN_OUTPUT);
	
	DIO_setPinDirection(LCD_DATA_PORT,LCD_D4_Pin,DIO_PIN_OUTPUT);
	DIO_setPinDirection(LCD_DATA_PORT,LCD_D5_Pin,DIO_PIN_OUTPUT);
	DIO_setPinDirection(LCD_DATA_PORT,LCD_D6_Pin,DIO_PIN_OUTPUT);
	DIO_setPinDirection(LCD_DATA_PORT,LCD_D7_Pin,DIO_PIN_OUTPUT);
	
	_delay_ms(35);

	//Setting RS pin to low to write "Command"
	DIO_setPinValue(LCD_CMD_PORT,RS_PIN,DIO_PIN_LOW);
	Private_VidWriteHalfPort(0b0010);
	/* Enable Pulse *//* H => L */
	DIO_setPinValue(LCD_CMD_PORT,E_PIN,DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_setPinValue(LCD_CMD_PORT,E_PIN,DIO_PIN_LOW);


	LCD_Write_CMD(0b00101000);
	_delay_us(45);

	// Display on off Control (DisplayOn, Cursor on, Blink on)
	LCD_Write_CMD(0b00001111);
	_delay_us(45);

	// Clear Display
	LCD_Write_CMD(0b00000001);
	_delay_ms(2);

	// Set Entry Mode
	LCD_Write_CMD(0b00000110);
	
}

void LCD_Write_CMD(u8 CMD){
	
	
	//Setting RS pin to low to write "Command"
DIO_setPinValue(LCD_CMD_PORT,RS_PIN,DIO_PIN_LOW);
	//Sending The 4 MSB
	Private_VidWriteHalfPort(CMD>>4);
	//Enable for sending command confirmation
	DIO_setPinValue(LCD_CMD_PORT,E_PIN,DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_setPinValue(LCD_CMD_PORT,E_PIN,DIO_PIN_LOW);
	//Sending The 4 LSB
	Private_VidWriteHalfPort(CMD);
	//Enable for sending command confirmation
	DIO_setPinValue(LCD_CMD_PORT,E_PIN,DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_setPinValue(LCD_CMD_PORT,E_PIN,DIO_PIN_LOW);	
}

void LCD_Write_CHAR(u8 CHAR){
	
	//Setting RS pin to low to write "Command"
DIO_setPinValue(LCD_CMD_PORT,RS_PIN,DIO_PIN_HIGH);
	//Sending The 4 MSB
	Private_VidWriteHalfPort(CHAR>>4);
	//Enable for sending command confirmation
	DIO_setPinValue(LCD_CMD_PORT,E_PIN,DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_setPinValue(LCD_CMD_PORT,E_PIN,DIO_PIN_LOW);
	
	//Sending The 4 LSB
	Private_VidWriteHalfPort(CHAR);
	//Enable for sending command confirmation
	DIO_setPinValue(LCD_CMD_PORT,E_PIN,DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_setPinValue(LCD_CMD_PORT,E_PIN,DIO_PIN_LOW);
	
	
	
}


void LCD_GoTo(u8 ROW, u8 COL)
{
	switch (ROW)
	{
		//Sending Move Cursor command + DDRAM Row Position + DDRAM Row Position
		case 0: LCD_Write_CMD(0b10000000 + 0x00 + COL);
		break;
		case 1: LCD_Write_CMD(0b10000000 + 0x40 + COL);
		break;
		case 2: LCD_Write_CMD(0b10000000 + 0x14 + COL);
		break;
		case 3:LCD_Write_CMD(0b10000000 + 0x54 + COL);
		break;
		default: //Error
		break;
	}
}


void LCD_Clear(void)
{
	LCD_Write_CMD(CMD_Clear_Display);
}

void LCD_WriteString(const u8 * str){
	
	while( (*str) !='\0'){
		
		
		LCD_Write_CHAR(*str);
		str++;
		
	}
	
	
}

void LCD_WriteNUM(s64 NUM){
	u64 Multiplier=1;
	
	if(NUM == 0){	LCD_Write_CHAR('0'); 	}
	
	else
	{
		if(NUM < 0) {	LCD_Write_CHAR('-');
		NUM *= -1;		 }
		
		if(NUM > 0){
			
			while( (s64)(NUM/Multiplier) != 0){	Multiplier*=10;	}

			do
			{
				Multiplier/=10;
				LCD_Write_CHAR( NUM/Multiplier +'0');
				NUM %=Multiplier;
			}
			while(Multiplier != 1 );
			
		}
	}
}

void LCD_WriteFLOAT(f64 num,u8 Percision)
{
	u64 val,i;
	val = (u64) num;
	LCD_WriteNUM(val);
	LCD_Write_CHAR('.');
	num -= val;
	for (i = 0; i < Percision; i++)
	{
		num *=10;
		val = (int)num;
		LCD_Write_CHAR(val+'0');
		num -=val;
	}
}




void Private_VidWriteHalfPort(u8 Cpy_u8HalfData)
{
	DIO_setPinValue(LCD_DATA_PORT,LCD_D4_Pin,GET_BIT(Cpy_u8HalfData,0));
	DIO_setPinValue(LCD_DATA_PORT,LCD_D5_Pin,GET_BIT(Cpy_u8HalfData,1));
	DIO_setPinValue(LCD_DATA_PORT,LCD_D6_Pin,GET_BIT(Cpy_u8HalfData,2));
	DIO_setPinValue(LCD_DATA_PORT,LCD_D7_Pin,GET_BIT(Cpy_u8HalfData,3));
}




