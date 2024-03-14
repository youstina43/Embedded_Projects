/*
 * LCD_private.h
 *
 * Created: 9/30/2022 9:49:13 PM
 *  Author: Youstina Atef
 */ 


#ifndef LCD_PRIVATE_H_
#define LCD_PRIVATE_H_

#define CMD_Clear_Display						             0x01
#define FOUR_MODE         0
#define EIGHT_MODE         1

void Private_VidWriteHalfPort(u8 Cpy_u8HalfData);





#endif /* LCD_PRIVATE_H_ */