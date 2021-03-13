/*
 * 25_feb_external_interrupt.c
 *
 * Created: 2/25/2021 12:22:57 PM
 * Author : lenovo
 */ 

#include <avr/io.h>
#include <stdint.h>

#define F_CPU 16000000UL
#include <avr/interrupt.h>

volatile uint8_t tick_signal=0;


ISR(INT0_vect)
{
	if(tick_signal)
	{
		PORTD |= (1<<PORTD5);
	}
	else
	{
		PORTD &= (1<<PORTD5);
	}
}
int main(void)
{

DDRD &= ~(1 << DDD2);   // PD2 (PCINT0 pin) is now an input
PORTD |= (1 << PORTD2);   

EIMSK |= (1 << INT0);    
EICRA |= (1 << ISC00)|(1 << ISC01);

sei();

	while (1)
	{
		
	}
}

