#include <avr/io.h>
#include <util/delay.h>
#include "peri.h"

int main()
{
	int x=0;
        init_peripheral();
	    while (1)
    	    {
		        set_led_value(x);
	    	        _delay_ms(500);
			x++;
	     }
   }

