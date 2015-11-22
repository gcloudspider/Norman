/*########################################################
##File Name: array_trim.c
##Created Time:2015年11月22日 星期日 19时36分33秒
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
    char buf[] = "this   is  a  pig";
    int i,j;

    printf("buf=%s\n",buf);

    i=j=0;
    for(;buf[i]&&buf[j];) {
        if(buf[j] == ' ') {
            j++;
        } else {
            buf[i] = buf[j];
            i++;
            j++;
        }
    }
    
    buf[i] = '\0';

    printf("buf=%s\n",buf);

    return 0;
}
