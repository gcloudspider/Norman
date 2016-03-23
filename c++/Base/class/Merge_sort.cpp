#include<iostream>
using namespace std;

void Merge_sort(int* arr,int* srr,int low,int high) {
    int mid;
    int m;
    if(low == high) srr[low] = arr[low];
    else {
        mid = (low+high)/2;
        Merge_sort(arr,srr,low,mid);
        Merge_sort(arr,srr,mid+1,high);
        Merge(arr,srr,low,mid,high);
    }

    for(m=low,m<=high;m++)
        arr[m] = srr[m];
}

void Merge(int* arr,int* srr,int i,int m,int n) {
    int k,j;
    k=i;
    j=m+1;
    while(i <= m&& j<=n) {
        if(arr[i] <= arr[j])
            srr[k++] = arr[i++];
        else 
            srr[k++] = arr[j++];
    }
    while(i <=m)
        srr[k++] = arr[i++];
    while(j <=n)
        srr[k++] = arr[j++];
}

//归并排序:
//归并排序把两个或两个以上有序表合成一个新的有序表,
//1.把待排序记录分成若干个有序子序列
//2.再把有序子序列合并为整体有序序列
//  一般采用2路归并排序,把含有n个元素的序列看作n个有序的子序列,每个子序列长度为1
//  再把子序列两两合并,得到n/2个长度为1或者2的子序列
//  再进行两两合并,直到最后序列长度为n的有序序列
//  2路归并排序操作是把相邻的两个数合并为有序的序列

int main() {
	
}
