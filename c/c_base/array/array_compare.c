/*************************************************************************
	> File Name: array_compare.c
	> Author: 
	> Mail: 
	> Created Time: 2015年11月21日 星期六 16时27分49秒
 ************************************************************************/

#include<stdio.h>

int main() {
    int i,j;
    int m[6] = {1,2,3,4,6,5};
    int n[6] = {1,2,3,4,6,5};
    
    for(i=0,j=0;i<6&& j<6;) {
        if(m[i] !=n[j]) {
            printf("array m and n not eq\n");
            return 0;
        }
        i++;
        j++;
    }

    printf("array m and n eq\n");
    return 0;
}
