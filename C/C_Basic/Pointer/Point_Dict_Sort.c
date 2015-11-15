/*
##########################################################
##
##Create Date:2015-11-14
##Author:Norman
##
##Descript:
##
##########################################################
问题:

一个指针数组，将数组中字符串元素按字典序排列

分析:
	1.char *s 是一个指针地址
	2.该指针地址存储着每个字符串的地址
	3.遍历char*s 的地址找到每个字符串的值
	4.首先按字典序找第一个字符
	5.然后再找到第一个相同的字符再按字典序找第二个,以此类推
	6.

归纳:
	1.冒泡排序
	2.交换(指针重新指向值)
	3.

总结:

*/

#include <stdio.h>

int main() {

	char *s[] = {
		"words","books","colors","students",
		"apples","car"
	};

	//printf("%p\n",s);
	//printf("%p\n",*s);
	//printf("%s\n",*s);
	int i,j;
	char *tmp;
	char *next;
	for(i=1;i<6;i++) {
		//printf("%p\n",s[i]);
		//printf("%p\n",s[i+1]);
		//printf("first and second memory address:\n");
		for(j=0;j<6-i;j++ ) {
			//printf("%c\n",*s[j]);
			//printf("%c\n",*s[j+1]);
			if(*s[j] > *s[j+1]) {
				tmp = s[j];
				s[j] = s[j+1];
				s[j+1] = tmp;
			} else if(*s[j] == *s[j+1]) {
				next = s[j+1];
				while(*s[j]) {
					if(*s[j] > *s[j+1]){
						printf("aa\n");
					}
					*s[j+1]++;
					*s[j]++;
				}
			}
		}
		//printf("\n");
	}

	for(i=0;i<6;i++) {
		printf("%s\n",s[i]);
	}
	return 0;
}
