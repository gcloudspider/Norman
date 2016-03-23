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

//归并排序:
//归并排序把两个或两个以上有序表合成一个新的有序表,
//1.把待排序记录分成若干个有序子序列
//2.再把有序子序列合并为整体有序序列
//
//

int main() {
	
}
