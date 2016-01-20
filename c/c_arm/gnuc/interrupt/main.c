#include "include/gpio.h"

void delay(int n)
{
	while(n--);
}

int main()
{
	init_led();
    init_beep();
    //init_key();  轮循初始化
    init_interrupt_for_key();   //中断的方式

    //led_on_all();
    led_off_all();
	int i;
	while(1){
        //while 循环轮循方式 (另一种方法中断方式)
        /*
        i=key_press();
        if(i>=1 && i<=4){
            led_off_all();
            beep_off();
            
            led_on(i);
            beep_on();
        } else if(i == 5){
            led_off_all();
            beep_off();
            
            led_on_all();
            beep_on();
        }else {
            led_off_all();
            beep_off();
        }*/
	}
	return 0;
}
