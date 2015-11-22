/*########################################################
##File Name: array_datablock.c
##Created Time:2015年11月22日 星期日 13时54分56秒
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
    int m[] = {1,1,1,2,3,4,4,4,4,5,7,8,8,8,8,9};

    int len = sizeof(m)/sizeof(m[0]);
    printf("%d\n",len);

    int i,j,n,max=0;
    int pos;
    for(i=0,j=1;i<len&&j<len;) {
        //printf("%d\n",m[i]);
        if(m[i] == m[j]) {
            j++;
        } else {
            n=j-i;
            if(n>max) {
                max=n;
                pos = i;
            }
            i=j;
            j++;
        }
    }
    
    for(i=0;i<max;i++) {
        printf("%d",m[pos+i]);
    }
    printf("\n");
    return 0;
}
