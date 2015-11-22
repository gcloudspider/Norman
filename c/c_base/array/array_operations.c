/*########################################################
##File Name: array_operations.c
##Created Time:2015年11月22日 星期日 21时19分25秒
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
    char s[]="123+456";
    int len = sizeof(s)/sizeof(s[0]);
    int i,j,k;
    int left=0,right=0;
    len--;
    char buf[];

    for(i=0;i<len;i++) {
        switch(s[i]) {
            case '+':{
                for(j=0;j<i;j++){
                    left=left*10+s[j]-'0';
                }
                printf("%d\n",left);

                for(k=i+1;k<len;k++) {
                    right=right*10+s[k]-'0';
                } 
                printf("%d\n",right);

                printf("left(%d)+right(%d)=%d\n",left,right,left+right);

                
                printf("Buf=%s\n",buf);
                break;
            }
            case '-': {
                break;
            }
            case '*': {
                break;
            }
            case '/': {
                break;
            }
            default:
                 break;
        }
    }

    return 0;
}
