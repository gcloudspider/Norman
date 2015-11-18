#include <stdio.h>

int k = 0;				//全局变量存放在数据段
							//1.访问范围所有文件所有函数都可调用
							//2.生存周期与程序一样
static l =0;			//全局的静态变量存放在数据段
							//1.访问范围是该文件所有函数都可调用
							//2.生存周期与程序一样
void show() {
	static int i=0;		//局部的静态变量存放在数据段
							//1.生存周期和程序一样
							//2.访问范围该函数
	int j=0;			//局部变量存放在栈空间
							//1.生存周期:函数一样
							//2.使用范围:该函数内部
	
	printf("%s is call %d\n",__func__,++i);
	printf("%s is call %d\n",__func__,++j);
	printf("%s is call %d\n",__func__,++k);
}

void show1() {
	static int i=0;
	int j=0;
	printf("%s is call %d\n",__func__,++i);
	printf("%s is call %d\n",__func__,++j);
	printf("%s is call %d\n",__func__,++k);
}


int main() {
	
	while(1) {
		sleep(1);
		show();
		show1();
	}

	return 0;
}
