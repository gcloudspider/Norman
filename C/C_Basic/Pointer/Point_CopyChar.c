/*
	问题:
		1.将字符串数组用指针拷贝到另一个字符串指针
		2.指定长度的拷贝
		3.用指针实现两个字符串的比较

	分析:
		1.获取指针的值 赋值给
		2.
		3.

	归纳:
		
	总结:
*/


#include <stdio.h>

int main() {
	
	char s[] = "123456";
	char d[1024] = {0};
	char *ps = s;
	char *pd = d;
	int len ;
	int i=0;
	//printf("%s\n",s);
	//printf("%s\n",ps);
	/*
	while(*ps) {
		printf("%p\t%c\t",ps,*ps);
		*pd=*ps;
		printf("%p\t%c",pd,*pd);
		ps++;
		pd++;
		printf("\n");
	}
	*/

/*
	scanf("%d",&len);


	while(*ps) {
		printf("%p\t",ps);
		printf("%c\t",*ps);
		if(i<len) {
			*pd=*ps;
			i++;
		}else {
			break;
		}
		printf("%p\t",pd);
		printf("%c",*pd);
		ps++;
		pd++;
		printf("\n");
	}
*/

	char j[] = "3455112";
	char k[] = "3482912";
	char* pj = j;
	char* pk = k;

	while(*pj) {
		printf("%c",*pj);
		pj++;
	}

	printf("%s\n",pd);
	printf("%s\n",d);
	
	return 0;
}
