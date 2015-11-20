#include <stdio.h>
#include <string.h>
/*
明确问题:
	查找第一次出现子字符串的位置

分析:
	1.遍历src++ 
	2.判断字符是否与dst相同
	3.相同src++,dst++继续比较
	4.若相同则继续
	5.若不同则src++ dst回到原来的位置
	6.若找到dst++到最后则返回S原来指针位置

归纳:
	1.相同时记录s位置 d位置 并同时后移
	2.s与d第一个字符相同,s++后移d回到原来位置
	3.s一直后移!

总结:

*/
char* my_strstr(const char* src,const char *dst) {
	
	char* p = (char*)src;
	char* q = (char*)dst;
	
	printf("before:%p\n",p);
	printf("before:%p\n",src);
	printf("before:%p\n",dst);

	while(*p) {
		
		if(!(*p-*q)) {
			*q++;
		}
	
		*p++;
		printf("moving:%p\t%c\n",p,*p);
		printf("After:%p\t%c\n",src,*src);
	}

	return NULL;

}

int main() {
	
	char src[] = "asdfghjkl";
	char dst[] = "sdf";

	printf("C Library strstr:%s\n",strstr(src,dst));

	printf("My_strstr:%s\n",my_strstr(src,dst));
	
	return 0;
}
