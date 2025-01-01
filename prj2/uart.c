/*
 * uart.c
 *
 * Created: 02-Jan-25 5:32:57
 *  Author: TAINV
 */
// Initialize UART

#include "uart.h"
void UART_Init(unsigned int baud)
{
	unsigned int ubrr = F_CPU / 16 / baud - 1;
	UBRRH = (unsigned char)(ubrr >> 8);	 // Upper byte of UBRR
	UBRRL = (unsigned char)ubrr;		 // Lower byte of UBRR
	UCSRB = (1 << RXEN) | (1 << TXEN);	 // Enable TX and RX
	UCSRC = (1 << URSEL) | (3 << UCSZ0); // Configure 8-bit data
}

// Transmit a single character via UART
void UART_Transmit(unsigned char data)
{
	while (!(UCSRA & (1 << UDRE)))
		;		// Wait until buffer is empty
	UDR = data; // Send the data
}

// Send a string via UART
void UART_SendString(const char *str)
{
	while (*str)
	{
		UART_Transmit(*str++);
	}
}