/*########################################################
##File Name: array_subcount.c
##Created Time:2015年11月22日 星期日 14时24分59秒
##Author: Norman 
##Description: 
##
##Issue: 子串在父串中出现的次数
##
##Analyze: 
        1.统计次数变量 
        2.比较两个字符串
##
##Induction:
##
##Summary:
##
##########################################################*/

#include<stdio.h>


int main() {
    char str[] = "mZgjklrtgjyuiogjp";
    char substr[] = "gj";
    int i,j;
    int count;

    int len = sizeof(str)/sizeof(str[0]);
    int sublen = sizeof(substr)/sizeof(substr[0]);
    for(i=0;i<sublen;i++) {
        for(j=0;j<len;) {
            if(str[j] == substr[i]) {
                i++;
            }
            j++
        }
    }
    
    return 0;
}
