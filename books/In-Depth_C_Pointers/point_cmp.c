/*########################################################
##File Name: point_cmp.c
##Created Time:2015年12月06日 星期日 19时55分08秒
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
    int vector[] = {28,41,7};

    int *p0 = vector;

    int *p1 = vector + 1;
    int *p2 = vector + 2;

    printf("p2>p0: %d\n",p2>p0);
    printf("p2<p0: %d\n",p2<p0);
    printf("p0>p1: %d\n",p0>p1);



}
