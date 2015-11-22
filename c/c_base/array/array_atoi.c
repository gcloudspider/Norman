/*########################################################
##File Name: array_atoi.c
##Created Time:2015年11月22日 星期日 20时13分12秒
##Author: Norman 
##Description: 
##
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


int main() {
    char s[] = "-123";
    int m=0;
    int i=0;
    int NV = 0;

    if(s[i] == '-') {
        NV = 1;
        i++;
    }
    
    if(s[i]<'0'||s[i] > '9') {
        printf("format error!\n");
        return -1;
    }

    for(;s[i];i++) {
        if(s[i] >='0' && s[i] <='9') {
            m=m*10+s[i]-'0';
        }else 
            break;
    }

    if(NV)
        m= -m;

    printf("m=%d\n",m);

    return 0;
}
