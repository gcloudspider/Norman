#include <stdio.h>

int main() {
	char c='A';
	char *p = &c;

	//指针地址
	printf("%p\n",p);
	printf("%p\n",&c);
	
	//指针地址变量值
	printf("%d\n",*p);
	printf("%d\n",c);

	const char* name = "chen";

	char* const name1 = "chen";

	const char* const name2 = "chen";

	name = "norman";
	printf("%s\n",name);

	//err: name[1] = 'N';

	//err: name1 = "Norman";

	//name1[0] = 'N';

	printf("%s\n",name1);

	printf("%s\n",name2);


	int *ptr;				指针类型为int*		指针所指向的类型int
	char *ptr;				指针类型为char*		指针所指向的类型char

	int **ptr;				指针类型为int **	指针所指向的类型int*
	int (*ptr)[3];			指针类型为int(*)[3]	指针所指向的类型int()[3]
	int* (*ptr)[4];			指针类型为int*(*)[4] 指针所指向的类型是int*()[4]
}
