/*########################################################
##File Name: array_aligncenter.c
##Created Time:2015年11月22日 星期日 21时03分32秒
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

    char s[] = "1234567890";
    int i,j,left,right;
    char tmp;

    i=left=0;
    j=right=sizeof(s)-2;

    while(i<j) {
        while(i<=right && s[i]%2)
            i++;
        while(j>=left && s[j]%2 ==0)
            j--;
        if(i<j) {
            tmp = s[i];
            s[i] = s[j];
            s[j] =tmp;
        }
    }

    printf("%s\n",s);
    
    return 0;
}
