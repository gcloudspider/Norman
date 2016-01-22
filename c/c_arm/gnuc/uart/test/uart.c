#include "../include/nv_arm.h"

void delay(int n)
{
	while(n--);
}

int main()
{
    init_clock();
    init_uart0();
    put_string("\n");

    put_string("init_led\n");
	init_led();
    led_on_all();

    put_string("init_beep\n");
    init_beep();

	char ch;
	while(1){
        put_string("waitting input char....\n");
        ch = get_char();
        put_string("your char is:");
        put_char(ch);
        put_string("\n");
	}
	return 0;
}
