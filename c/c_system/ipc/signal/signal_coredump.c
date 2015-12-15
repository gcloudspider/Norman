/*########################################################
##File Name: signal_coredump.c
##Created Time:2015年12月15日 星期二 09时38分44秒
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

int func(int *p){
    int y = *p;
    return y;
}

int main(){
    int *p = NULL;
    return func(p);
}
