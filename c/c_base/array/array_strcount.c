/*########################################################
##File Name: array_strcount.c
##Created Time:2015年11月22日 星期日 16时35分22秒
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
    char s[] = "this   is    a pig";
    int i,words = 0;
    int out=1;

    for(i=0;s[i];i++) {
        if(s[i] != ' ') {
            if(out){
                words++;
                out =0;
            }
        } else {
            if(!out)
            out =1;
        }
    }

    printf("%s\n",s);
    printf("%d\n",words);

    return 0;
}
