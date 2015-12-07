/*########################################################
##File Name: point_struct.c
##Created Time:2015年12月07日 星期一 12时32分44秒
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

struct faction{
    int num;
    int daemon;
};

int main(){
    int i = 37;
    float f = *(float*)&i;
    printf("%f\n",f);
    double d = 30;
    short s = *(short*)&d;
    //printf("");
    //
    struct faction pi;
    pi.num = 22;
    pi.daemon = 7;

    printf("%d\t%d\n",pi.num,pi.daemon);

    ((struct faction*)(&pi.num))->num = 12;
    
    printf("%d\t%d\n",pi.num,pi.daemon);

}

