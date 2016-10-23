#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

int main()
{
    DDRD= 0b00001000;

    while(1)
    {
	PORTD = 0b00001000;
	_delay_ms(1000);
	PORTD = 0b00000000;
	_delay_ms(1000);
    }
}
