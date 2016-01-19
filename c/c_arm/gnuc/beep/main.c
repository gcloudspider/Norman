#include "include/led.h"
#include "include/beep.h"

void delay(int n)
{
	while(n--);
}

int main()
{
	init_led();
    init_beep();
	int i;
	while(1)
	{
		for(i=1;i<=4;i++)
		{
            beep_on();
			led_on(i);
			delay(0xffff);
            beep_off();
			led_off(i);
			delay(0xffff);
		}
	}
	 return 0;
}
