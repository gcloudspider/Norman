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
	int i=0,j=0;
	//printf("before Reverse Str:%p\t%c\n",pStr,*pStr);

	while(*pStr) {
		j++;
		*pStr++;
	}

	printf ("Reverse Str:%p\t%c\n",pStr,*--pStr);
	
	while(i<j) {
		printf("Before Exchange:%c\n",*pStr);
		tmp = str[i];
		str[i] = *pStr;
		*pStr = tmp;
		printf("After Exchange:%c\n",*pStr);
		*pStr--;
	}

	printf("Finished Exchange:%s\n",str);
	
	return 0;
}
