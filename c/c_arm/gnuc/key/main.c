#include "include/gpio.h"

void delay(int n)
{
	while(n--);
}

int main()
{
	init_led();
    init_beep();
    init_key();
	int i;
	while(1)
	{
        //while 循环轮循方式 (另一种方法中断方式)
        i=key_press();
        if(i>=1 && i<=4){
            led_on(i);
            beep_on();
        } else if(i == 5){
            led_on_all();
            beep_on();
        }else {
            led_off_all();
            beep_off();
        }
	}
	return 0;
}
