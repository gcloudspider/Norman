/*########################################################
##File Name: algorithm_quicksort.c
##Created Time:2015年11月26日 星期四 15时57分18秒
##Author: Norman 
##Description:  快速排序
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

void quick_sort_algorithm(int m[],int left,int right) {
    int key = left++;       //先赋值后++ so:key=m[0]
    int i=left,j=right;     //i=m[1] j=m[7]
    printf("key=%d\ti=%d\tj=%d\tleft=%d\tright=%d\n",key,i,j,left,right);

    if(left>right) return;  //只有一个元素,无需排序

    while(i<=j) {
        while(m[i]<=m[key] && i<right) {    
            //从左向右遍历查找比第一个小定下i最大的位置
            i++;
        }
        while(m[j]>m[key] && j>left) {
            //从右向左遍历查找比最后一个小定下j的位置
            j--;
        }

        if(i<j) {
            
        }
    }


}

int main() {
    int m[8] = {6,1,5,10,3,9,7,2};
    int i;
    printf("before quick sort\n");
    
    for(i=0;i<8;i++) {
        printf("%d ",m[i]);
    }
    printf("\n");

    quick_sort_algorithm(m,0,7);

    printf("after quick sort\n");
    for(i=0;i<8;i++) {
        printf("%d ",m[i]);
    }
    printf("\n");


    return 0;
}
