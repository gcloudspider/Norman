#include <stdio.h>
#include <signal.h>

/*
	系统调用:用户程序调用内核提供的函数接口
	回调函数:内核调用用户程序的函数接口
*/

void func(int i) {
	printf("hello world!\n");
	alarm(1);
}

int main() {
	
	signal(SIGALRM,func);
	alarm(1);				//发出信号
	while(1);
	
	return 0;
}
