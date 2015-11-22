/*########################################################
##File Name: array_float.c
##Created Time:2015年11月22日 星期日 20时23分25秒
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
    char s[] = "123.456";
    int i=0,j,dot=-1;
    int NV = 0;

    double f,fi=0.0,ff=0.0;

    if(s[i] == '-') {
        NV = 1;
        i++;
    }

    for(;s[i];i++) {
        if(s[i] >='0' && s[i]<='9') {
            if(dot<0) {
                fi = fi*10+s[i] -'0';
            }else {
                ff = ff*10+s[i] -'0';
            }
        }else if(s[i] == '.') {
            if(dot<0) dot =i;
            else
                break;
        }else
            break;
    }

    printf("i=%d,dor=%d\n",i,dot);
    printf("fi=%f,ff=%f\n",fi,ff);

    for(j=0;j<i-dot-1;j++) 
        ff/=10;
    printf("fi=%f,ff=%f\n",fi,ff);

    f=fi+ff;

    if(NV)
        f=-f;

    printf("f=%f\n",f);

    return 0;
}
