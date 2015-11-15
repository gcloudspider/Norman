/*

明确问题:使用指针反转字符串

分析:
	1.移动到字符串最后位置(指针)
	2.向前移动得到每一个值赋值给变量tmp
	3.将
归纳:

总结:


*/


#include <stdio.h>

int main() {
	char str[] = "acbickwiwlsos";
	printf("Str:%s\n",str);
	char *pStr = str;
	char tmp;

	//printf("before Reverse Str:%p\t%c\n",pStr,*pStr);

	while(*pStr)
		*pStr++;

	char* pstar = str;
	printf ("Reverse Str:%p\t%c\n",pStr,*--pStr);
	
	while(*pstar) {
		printf("Before Exchange:%c\n",*pstar);
		tmp = *pstar;
		*pstar = *pStr;
		*pStr = tmp;
		printf("After Exchange:%c\n",*pstar);
		*pStr--;
		*pstar++;
	}

	printf("Finished Exchange:%s\n",str);
	
	return 0;
}
