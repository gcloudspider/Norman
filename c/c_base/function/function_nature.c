#include <stdio.h>
/*
	函数本质:相同的函数名调用再多次编译过后
*/
void print_hello() {
	printf("hello world!\n");
}

void func() {
	printf("hello\n");
}

int main() {
	
	print_hello();
	
	void (*pf)() = func;			//function pointer

	printf("%p\n",pf);

	(*pf)();
	
	pf();

	return 0;
}
