/*########################################################
##File Name: array_strreverse.c
##Created Time:2015年11月22日 星期日 19时46分08秒
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
    char s[] = "  this is a pig ";
    int i,j,left,right;
    char tmp;
    int out = 1;

    i=j=0;
    printf("s=%s\n",s);

    while(s[j]) j++;
    j--;

    while(i<j) {
        tmp = s[i];
        s[i] = s[j];
        s[j] = tmp;
        i++;
        j--;
    }
    printf("s=%s\n",s);

    for(i=j=0;s[i]&&s[j];j++) {
        if(s[j] != ' ') {
            if(out) {
                left = j;
                out =0;
            }
        }else {
            if(out == 0) {
                out =1;
                right=j-1;
                while(left<right) {
                    tmp=s[left];
                    s[left] = s[right];
                    s[right] = tmp;
                    left++;
                    right--;
                }
            }
        }
    }

    if(out ==0) {
        out =1;
        right=j-1;
        while(left<right) {
            tmp=s[left];
            s[left] = s[right];
            s[right] = tmp;
            left++;
            right--;
        }
    }
    printf("s=%s\n",s);
    return 0;
}
