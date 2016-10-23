#include<avr/io.h>
#include "peri.h"

void init_peripheral()
{
    DDRC|=(1)|(1<<1)|(1<<2);
    DDRC&=~((1<<3)|(1<<4));
    PORTC|=(1<<3);
    PORTC&=~((1)|(1<<1)|(1<<2)|(1<<4));
}

void set_led(uint8_t pin,uint8_t state)
{
    if(state!=0){
	PORTC|=(1<<pin);
    }
    else{
	PORTC&=~(1<<pin);
    }
}

void set_led_value(uint8_t x)
{
    x%=8;
    PORTC=(PORTC|x)&(x|0xF8);
}

uint16_t read_adc(uint8_t channel)
{
    ADMUX = (0<<REFS1)|(1<<REFS0)|(0<<ADLAR)|(channel&0b1111);
    ADCSRA = (1<<ADEN)|(1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0)|(1<<ADSC);

    while((ADCSRA&(1<<ADSC)));
    return ADC;
}
