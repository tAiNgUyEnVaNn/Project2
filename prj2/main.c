#include "uart.h"
#include "lcd.h"

// Initialize ADC
void ADC_Init()
{
	ADMUX = (1 << REFS1) | (1 << REFS0);				// Select Vref = 2.56V internal
	ADCSRA = (1 << ADEN) | (1 << ADPS2) | (1 << ADPS1); // Enable ADC, Prescaler = 64
}

// Read ADC value
unsigned int ADC_Read(unsigned char channel)
{
	ADMUX = (ADMUX & 0xF8) | (channel & 0x07); // Select ADC channel
	ADCSRA |= (1 << ADSC);					   // Start conversion
	while (ADCSRA & (1 << ADSC))
		; // Wait for conversion to complete
	return ADC;
}


int main(void)
{
	UART_Init(9600); // Initialize UART with baud rate 9600
	ADC_Init();		 // Initialize ADC
	LCD_Init();		// Init LCD
	
	char buff[16];
	unsigned int adc_value;
	float temperature;

	while (1)
	{
		LCD_Clear();
		adc_value = ADC_Read(1);						   // Read ADC value from channel PA1
		temperature = roundf((adc_value * 2.56 / 1024.0) * 100.0); // Calculate temperature (C)
		// Send temperature data via UART
		sprintf(buff, "Temp: %d\n", (int)(temperature));
		UART_SendString(buff);
		LCD_String_xy(0, 0, "DO AN 20241");
		LCD_String_xy(1, 0, buff);
		_delay_ms(1000); // Delay 1 second
	}
}
