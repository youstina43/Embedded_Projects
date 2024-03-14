/*
 * Calculator_Stack_Based.c
 *
 * Created: 9/28/2023 7:32:18 PM
 * Author : youstina 
 */ 
#include "STD.h"
#include "BitMath.h"

#include "DIO_Interface.h"

#include "LCD_Interface.h"
#include "Keypad_Interface.h"

#include "CALC_Interface.h"


int main(void)
{
    u8 ret=0;                                     
    u8 infix_index=0;                                                       
    u8 lcd_infix_pos=0;                            

    H_KeyPad_Void_KeyPadInit(); 
    H_Lcd_Void_LCDInit();       

    H_Lcd_Void_LCDWriteString(" ENTER EXPRESSION ");
    _delay_ms(5500);

   H_Lcd_Void_LCDClear();                         
 

    while(1){

	    ret=H_KeyPad_U8_KeyPadRead();

	    if(ret=='1'||ret=='2'||ret=='3'||ret=='4'||ret=='5'||   
	    ret=='6'||ret=='7'||ret=='8'||ret=='9'||
	    ret=='*'||ret=='/'||ret=='+'||ret=='-'||
	    ret=='('||ret==')')
	    {
		    H_Lcd_Void_LCDGoTo(0, lcd_infix_pos+1);
		    lcd_infix_pos++;
		    if(ret=='*'||ret=='/'||ret=='+'||ret=='-')  // IF FUNCTION TO CHECK IF OPERATOR IS ENTERD
		    {
			    H_Lcd_Void_LCDWriteCharacter(ret);
			    infix[infix_index++]=ret;
			    infix[infix_index++]=' ';
		    }
		    else
		    {
			    infix[infix_index++]=ret;
			    H_Lcd_Void_LCDWriteCharacter(ret);
		    }
	    }

	    else if(ret=='=')                
	    {
		    s8* postfix = infixToPostfix(infix);		
		    H_Lcd_Void_LCDGoTo(2, 1);
			H_Lcd_Void_LCDWriteString("ANS=");
		    H_Lcd_Void_LCDWriteNumber(evaluatePostfix(postfix));

	    }
	    else
	    {

	    }

    }


    return 0;
}

