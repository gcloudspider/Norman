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
	
	int i,j;
	char *s1,*s2,*tmp;
	printf("s=%p\n",s);
	printf("sizeof(s)=%d\n",sizeof(s));
	printf("sizeof(s[0])%d\n",sizeof(s[0]));

	int len = sizeof(s)/sizeof(s[0]);

	for(i=0;i<len;i++) {
		printf("s[%d]=\"%s\"\t%p\n",i,s[i],s[i]);
	}

	printf("Sorting...\n\n");

	for(i=0;i<len;i++) {
		for(j=0;j<len-i-1;j++) {
			//printf("%p\n",s[j]);
			s1=s[j];
			s2=s[j+1];
			while(*s1&&*s1==*s2) {
				s1++;s2++;
			}
			if(*s1>*s2) {
				tmp = s[j];
				s[j] = s[j+1];
				s[j+1] = tmp;
			}
		}
	}
	
	for(i=0;i<len;i++) {
		printf("s[%d]=\"%s\"\t%p\n",i,s[i],s[i]);
	}
	return 0;
}
