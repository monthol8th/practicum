#include <avr/io.h>
#include <util/delay.h>
#include "peri.h"

int main()
{
	uint16_t res;
        init_peripheral();
	while(1)
	{
	    res=read_adc(PC4)/342;
	    set_led(RED,res==0);
	    set_led(YELLOW,res==1);
	    set_led(GREEN,res==2);
	}  
}

