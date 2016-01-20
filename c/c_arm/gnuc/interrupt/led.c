#include "include/gpio.h"
void init_led()
{
	rGPBCON |= GPB5_OUT|GPB6_OUT|GPB7_OUT|GPB8_OUT;
}
void led_on(int num)//num:1-4
{
	switch(num)
	{
	case 1:
		rGPBDAT &= ~(1<<5);
		break;
	case 2:
		rGPBDAT &= ~(1<<6);
		break;
	case 3:
		rGPBDAT &= ~(1<<7);
		break;
	case 4:
		rGPBDAT &= ~(1<<8);
		break;
	default:
		break;
	}
}
void led_off(int num)
{
	switch(num)
	{
	case 1:
		rGPBDAT |= (1<<5);
		break;
	case 2:
		rGPBDAT |= (1<<6);
		break;
	case 3:
		rGPBDAT |= (1<<7);
		break;
	case 4:
		rGPBDAT |= (1<<8);
		break;
	default:
		break;
	}

}
void led_on_all()
{
	rGPBDAT &= ~(0xf<<5);
}
void led_off_all()
{
	rGPBDAT |= (0xf<<5);
}


