/*########################################################
##File Name: array_align.c
##Created Time:2015年11月22日 星期日 20时50分26秒
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
    char s[1024] = "";
    int i,j;
    char tmp;
    scanf("%s",s);

    for(i=0,j=1;s[i]&&s[j];) {
        if(s[i]%2==0) {
            if(s[j]%2) {
                tmp = s[i];
                s[i] = s[j];
                s[j] =tmp;
                i++;
                j++;
            }else {
                j++;
            }
        }else {
            i++;
            j++;
        }
    }

    printf("s=%s\n",s);
    return 0;
}
