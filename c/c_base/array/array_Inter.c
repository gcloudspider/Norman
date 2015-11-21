/*########################################################
##File Name: array_Inter.c
##Created Time:2015年11月21日 星期六 16时57分56秒
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
    int carry =0;

    char c1[2] = {0x1,0xff};
    char c2[2] = {0x2,0x1};
    char c3[2];
    char max;

    short s1 = 0x1ff;
    short s2 = 0x201;
    short s3 = s1+s2;
    printf("s3=0x%x\n",s3);

    if(c1[1]>c2[1])
        max = c1[1];
    else 
        max = c2[1];

    c3[1] = c1[1] + c2[1];
    if(c3[1]<max)
        carry = 1;
    else 
        carry = 0;

    c3[0] = c1[0]+c2[0]+carry;

    printf("c3[]=0x%02x%02x\n",c3[0],c3[1]);
    
    return 0;
}
