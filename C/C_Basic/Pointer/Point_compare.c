/*
#########################################################
##
##Create Date:2015-11-14
##Author:Norman
##
##
#########################################################
问题:用指针对两个字符串进行比较

分析:
	1.字符串赋值指针(得到字符串第一个元素指针位置)
	2.循环指针获取指针的值
	3.判断两个指针位置值是否相同
	4.相同向后移动
	5.不相同打印两个字符串不相同
归纳:

总结:

	指针位置移动的同时比较字符

*/

#include <stdio.h>

int main() {
	char first[] = "ckeiwl";
	char second[] = "acbieic";

	char *pf = first;
	char *ps = second;

	while(*pf) {
		//printf("%p\n",pf);
		//printf("%p\n",ps);
		//printf("%c\n",*pf);
		//printf("%c\n",*ps);
		if(*pf==*ps) {
			*pf++;
			*ps++;
		} else {
			printf("Two char is different:first=%c second=%c\n",*pf,*ps);
			break;
		}
		printf("the same as two char :%c\n",*pf);
	}

	return 0;
}
