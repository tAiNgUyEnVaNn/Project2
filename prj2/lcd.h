/*
 * lcd.h
 *
 * Created: 02-Jan-25 5:44:39
 *  Author: TAINV
 */ 


#ifndef LCD_H_
#define LCD_H_
#define F_CPU 8000000UL  // 8 MHz Clock Frequency

#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>

#define LCD_PORT PORTC     // Define LCD Port (data lines connected to PORTC)
#define LCD_DDR  DDRC      // Define LCD Port Direction Register
#define RS PD6             // Define Register Select Pin
#define RW PD5             // Define Read/Write Pin
#define EN PD7             // Define Enable Pin
#define LCD_CONTROL_PORT PORTD // Control lines connected to PORTD
#define LCD_CONTROL_DDR  DDRD

void ADC_Init();
void LCD_Command(unsigned char cmnd);
void LCD_Char(unsigned char data);
void LCD_Init();
void LCD_String(char *str);
void LCD_Clear();
void LCD_String_xy(char row, char pos, char *str);
void LCD_Set_Cursor(char row, char col);


#endif /* LCD_H_ */