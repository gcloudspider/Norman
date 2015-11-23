/*########################################################
##File Name: point_mudflap.c
##Created Time:2015年11月23日 星期一 08时54分39秒
##Author: Norman 
##Description: mudflap 内存泄漏检测 
## The mudflap run time checker was removed in GCC 4.9 and it is superseded ##by Address Sanitizer. The mudflap options remain, but do nothing. This ##page applies only to earlier versions of GCC
##GCC 4.9开始就mudflap就被Address Sanitizer(GCC 4.8引入)给替代了
##Issue: 
##
##Analyze: 
##
##Induction:
##
##Summary:
##
##########################################################*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {
    printf("%s:%d-------------------------\n",__FILE__,__LINE__);
    
    //char p1[256]                      //栈越界测试
    char *p1 = (char*) malloc(256);     //堆越界测试
    p1[256] = '0';                      //下地址越界

    sleep(1);

    printf("\n%s:%d-----------------------\n",__FILE__,__LINE__);
    memset(p1,0,257);                   //函数赋值长度过长

    sleep(1);

    printf("\n%s:%d-------------------------\n",__FILE__,__LINE__);

    char *pTest1 = p1+256;

    *pTest1 = '0';                      //下地址越界

    sleep(1);

    printf("\n%s:%d-----------------------------\n",__FILE__,__LINE__);

    char *pTest2 = p1-1;                //上地址越界
    *pTest2='0';

    printf("\n%s:%d-----------------------------\n",__FILE__,__LINE__);

    sleep(10);

    return 0;
}
