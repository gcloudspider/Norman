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


	printf("%s\n",name1);
}
