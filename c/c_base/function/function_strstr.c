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
    
    1.循环src
    2.循环dst 判断dst是否等于src 等于继续循环遍历直到不等于

*/
char* my_strstr(const char* src,const char *dst) {
	
    if(*src == '0') {
       if(*dst) return (char*)NULL;
        return (char*)src;
    }

    while(*src){
        int i=0;
        while(1) {
            if(dst[i]==0) return (char*)src;
            if(dst[i]!=src[i])break;
            i++;
        }
        *src++;
    }
    return (char*) NULL;

}

int main() {
	
	char src[] = "asdfghjkl";
	char dst[] = "sdf";

	printf("C Library strstr:%s\n",strstr(src,dst));

	printf("My_strstr:%s\n",my_strstr(src,dst));
	
	return 0;
}
