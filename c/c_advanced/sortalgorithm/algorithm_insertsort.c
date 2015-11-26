/*########################################################
##File Name: algorithm_insertsort.c
##Created Time:2015年11月26日 星期四 15时26分25秒
##Author: Norman 
##Description:  插入排序
##
##Issue: 
##
##Analyze: 
##      1.将第二个值记录
##      2.循环判断前面的值是否大于记录的临时值
##      3.若大于将前一个值替换当前值
##Induction:
##
##Summary:
##
##########################################################*/

#include<stdio.h>

void insert_sort(int m[],int len) {
    int i,tmp,j,k;
    for(i=1;i<len;i++) {
        tmp = m[i];
        for(j=i;j>0;j--) {
            if(m[j-1]>tmp) {
                m[j] = m[j-1];
            } else {
                break;
            }
        }
        m[j] = tmp;
    }
}


int main() {
    int m[8] = {9,2,6,10,8,3,7,5};

    printf("before insert sort:\n");

    int i;
    for(i=0;i<8;i++) {
        printf("%d ",m[i]);
    }
    printf("\n");

    insert_sort(m,8);

    printf("after insert sort:\n");
    for(i=0;i<8;i++) {
        printf("%d ",m[i]);
    }
    printf("\n");

    return 0;
}
