/*########################################################
##File Name: array_charcount.c
##Created Time:2015年11月22日 星期日 16时11分18秒
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
    char s[] = "4567fghjkswfghjfghgh";

    int sum =0;
    int i,j;
    int len = sizeof(s)/sizeof(s[0])-1;

    //26个字母每个都遍历统计次数
    for(i='a';i<='z';i++) {
        sum = 0;
        for(j=0;j<len;j++) {
            if(i==s[j]) {
                sum++;
            }
        }
        if(sum) {
            printf("'%c'    %d\n",i,sum);
        }
    }

    return 0;
}
