/*########################################################
##File Name: array_upper.c
##Created Time:2015年11月22日 星期日 16时02分59秒
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
    char s[] = "afghjk";

    int len = sizeof(s)/sizeof(s[0]);
    int i;

    for(i=0;i<len;i++) {
        if(s[i]>='a'&& s[i] <='z') {
            s[i] = (s[i]-32);
        }
    }


    printf("%s\n",s);
 
    return 0;
}
