/*
 * lcd.c
 *
 * Created: 02-Jan-25 5:44:27
 *  Author: TAINV
 */ 

// datasheet and instruction: https://www.waveshare.com/datasheet/LCD_en_PDF/LCD1602.pdf

#include "lcd.h"

void LCD_Command(unsigned char cmnd) {
	LCD_PORT = cmnd;             // Send command to LCD port
	LCD_CONTROL_PORT &= ~(1 << RS); // RS = 0, command mode
	LCD_CONTROL_PORT &= ~(1 << RW); // RW = 0, write mode
	LCD_CONTROL_PORT |= (1 << EN);  // Enable pulse
	_delay_us(1);
	LCD_CONTROL_PORT &= ~(1 << EN);
	_delay_ms(2);                // Wait for command execution
}

void LCD_Char(unsigned char data) {
	LCD_PORT = data;             // Send data to LCD port
	LCD_CONTROL_PORT |= (1 << RS);  // RS = 1, data mode
	LCD_CONTROL_PORT &= ~(1 << RW); // RW = 0, write mode
	LCD_CONTROL_PORT |= (1 << EN);  // Enable pulse
	_delay_us(1);
	LCD_CONTROL_PORT &= ~(1 << EN);
	_delay_ms(2);                // Wait for data execution
}

void LCD_Init() {
	LCD_DDR = 0xFF;              // Set LCD data port as output
	LCD_CONTROL_DDR |= (1 << RS) | (1 << RW) | (1 << EN); // Set control pins as output
	_delay_ms(20);               // Wait for LCD to power up

	// Initialize LCD in 8-bit mode
	LCD_Command(0x38);           // Function set: 8-bit mode, 2 lines, 5x8 font
	LCD_Command(0x0C);           // Display ON, cursor OFF
	LCD_Command(0x01);           // Clear display
	_delay_ms(2);
	LCD_Command(0x06);           // Entry mode set: Increment cursor, no shift
}

void LCD_String(char *str) {
	while (*str) {
		LCD_Char(*str++);        // Send each character of string to LCD
	}
}

void LCD_Clear() {
	LCD_Command(0x01);           // Clear display
	_delay_ms(2);
}

void LCD_String_xy(char row, char pos, char *str) {
	if (row == 0) {
		LCD_Command((pos & 0x0F) | 0x80); // Command for row 0
		} else if (row == 1) {
		LCD_Command((pos & 0x0F) | 0xC0); // Command for row 1
	}
	LCD_String(str);              // Send string to specified position
}

void LCD_Set_Cursor(char row, char col){
	if (row == 0){
		col |= 0x80;
	}
	else if (row == 1){
		col |= 0xC0;
	}
	LCD_Command(col);
}