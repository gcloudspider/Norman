#include <stdio.h>

class MyInt{
public:
	int MyValue;
};


//存放在栈中
int ReturnValue() {
	int x;
	x = 3;
	int y;
	y = x;
	y = 4;
	return x;
}

//class 引用类型存放在堆中

int ReturnValue2() {
	MyInt *x = new MyInt();
	x->MyValue = 3;
	MyInt *y = new MyInt();
	y = x;
	y->MyValue = 4;
	return x->MyValue;
}

int main() {
	int x,y;
	x=ReturnValue();
	printf("%d\n",x);

	y=ReturnValue2();
	printf("%d\n",y);

	return 0;
}
