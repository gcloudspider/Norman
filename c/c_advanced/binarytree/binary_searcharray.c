/*########################################################
##File Name: binary_search.c
##Created Time:2015年11月26日 星期四 10时03分17秒
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


int binary_search(int m[],int left,int right,int key) {
    int mid;

    while(left<=right) {
        mid = (left+right)/2;
        if(m[mid] == key) {
            return mid;
        } else if(m[mid] < key) {
            left = mid+1;
        } else if(m[mid] > key) {
            right = mid-1;
        }
    }
    
    return -1;
}

int main() {
    int m[8] = {1,3,5,7,9,11,13,15};
    int key;
    int left,right;
    int ret;

    printf("please input key to search:\n");
    scanf("%d",&key);

    ret = binary_search(m,2,7,key);

    if(ret == -1) {
        printf("Not Found\n");
    } else {
        printf("Found Key:%d\n",ret);
    }
    return 0;
}
