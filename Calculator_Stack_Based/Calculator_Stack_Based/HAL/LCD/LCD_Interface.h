

#ifndef HAL_LCD_LCD_INTERFACE_H_
#define HAL_LCD_LCD_INTERFACE_H_

#include "STD.h"
#include "DIO_Interface.h"
#include <util/delay.h>

void H_Lcd_Void_LCDInit(void);
void H_Lcd_Void_LCDWriteCharacter(u8);
void H_Lcd_Void_LCDWriteCommand(u8);
void H_Lcd_Void_LCDWriteString(u8*);
void H_Lcd_Void_LCDClear(void);
void H_Lcd_Void_LCDWriteNumber(s32);
void H_Lcd_Void_LCDGoTo(u8,u8);

#endif /* HAL_LCD_LCD_INTERFACE_H_ */
