#include <avr/io.h>
#include <util/delay.h>
#include "peri.h"

int main()
{
	uint16_t res;
        init_peripheral();
	while(1)
	{
	    res=read_adc(PC4)/128;
	    set_led_value(res);
	}  
}

