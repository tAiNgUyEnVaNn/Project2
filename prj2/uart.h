/*
 * uart.h
 *
 * Created: 02-Jan-25 5:32:43
 *  Author: TAINV
 */

#ifndef UART_H_
#define UART_H_

#define F_CPU 8000000UL // Microcontroller clock frequency (8 MHz)
#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>

/**
 * @brief Init UART transmission
 */
void UART_Init();

/**
 * @brief Send data via UART
 */
void UART_Transmit(unsigned char data);

/**
 * @brief Send string via UART
 */
void UART_SendString(const char *str);

#endif /* UART_H_ */