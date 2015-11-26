/*########################################################
##File Name: algorithm_selectsort.c
##Created Time:2015年11月26日 星期四 15时57分32秒
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

void select_sort_algorithm(int m[]) {
    int i,j,min,tmp;
    for(i=0;i<8-1;i++) {
        min = i;                        //1.假设下标0为最小值，依次向次假设
        for(j=i+1;j<8;j++) {            //2.找到最小字符的位置，
            if(m[j] < m[min]) {
                min = j;
            }
        }
        if(min != i) {                  
            tmp = m[min];               //3.若最小位置 不是假设的位置,将内容跟最小位置内容互换
            m[min] = m[i];
            m[i] = tmp;
        }
    }
}

int main() {
    int m[8] = {9,2,6,10,8,3,5,7};

    int k;
    printf("before select sort:\n");

    for(k=0;k<8;k++) {
        printf("%d ",m[k]);
    }
    printf("\n");

    select_sort_algorithm(m);

    printf("after select sort\n");

    for(k=0;k<8;k++) {
        printf("%d ",m[k]);
    }
    printf("\n");


    return 0;
}
