#include <stdio.h>
#include <string.h>

int test(int iA,int iB) {
	int iC = iA+iB;
	printf("test:%p\n",test);
	return iC;
}

int main(int argc,const char* argv[]) {		//1.main函数压栈
	int a = 3;
	int b = 4;
	printf("main:%p\n",main);
	test(a,b);								//调用test指令,test函数压栈
	return 0;
}
