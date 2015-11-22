/*########################################################
##File Name: array_converstr.c
##Created Time:2015年11月22日 星期日 19时12分27秒
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
    int m;
    char s[1024] = {0};
    int i=0,j=0;
    char tmp;

    scanf("%d",&m);

    do{
        s[i++] = m%10+'0';
        m/=10;
    }while(m);

    s[i] = '\0';

    i--;

    while(j<i) {
        tmp = s[i];
        s[i] = s[j];
        s[j] = tmp;
        j++;i--;
    }

    printf("%s\n",s);

    return 0;
}
