/*
###########################################
##
##create date:2015-11-18
##
##Author:Norman
##Description: factory model
##
###########################################
	
*/


#include <stdio.h>

void init_cpu() {
	printf("%s() called!\n",__func__);
}

void init_mem() {
	printf("%s() called!\n",__func__);
}

void init_nand() {		//NAND闪存是一种比硬盘驱动器更好的存储方案
	printf("%s() called!\n",__func__);
}

void init_usb() {
	printf("%s() called!\n",__func__);
}

void init_net() {
	printf("%s() called!\n",__func__);
}

void init_serial() {
	printf("%s() called!\n",__func__);
}

void init_I2S() {		//I2S(Inter—IC Sound)总线,集成电路内置音频总线
	printf("%s() called!\n",__func__);
}

void init_I2C() {		//I2C（Inter－Integrated Circuit）两线式串行总线,用于连接微控制器及其外围设备
	printf("%s() called!\n",__func__);
}

void init_SPI() {		//SPI(Serial Peripheral Interface--串行外设接口)总线系统是一种同步串行外设接口，它可以使MCU与各种外围设备以串行方式进行通信以交换信息
	printf("%s() called!\n",__func__);
}

typedef int int32;
typedef void(*INIT)();

INIT init_all[]={
	init_cpu,init_mem,
	init_nand,init_usb,
	init_I2S,init_I2C,
	init_SPI,init_net,
	init_serial,NULL
};

int main() {
	int32 a = 10;
	INIT *pf = init_all;

	while(*pf)
		(*pf++)();

	return 0;
}
