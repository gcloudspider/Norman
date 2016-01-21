#include "include/gpio.h"

void delay(int n)
{
	while(n--);
}
char a[2048] ={0};   //*TODO:设置该全局变量值 2K 将flag写入数据段2K之后
                    //原因:(可判断坏道)实验时由于nandflash该数据段区域有坏道
int flag = 0;
int main()
{
	init_led();
    init_beep();
    //init_key();  轮循初始化
    //init_interrupt_for_key();   //中断的方式

    led_off_all();
    if(flag){
        led_on_all();
        beep_on();
    }
	int i;
	while(1){
	}
	return 0;
}
