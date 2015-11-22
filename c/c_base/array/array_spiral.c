/*########################################################
##File Name: array_spiral.c
##Created Time:2015年11月21日 星期六 21时39分54秒
##Author: Norman 
##Description: 
##
##Issue: 螺旋数组
##
##Analyze: 
    1.将数字转为数组布局
    -------------------------------
    | a[0][1] | a[0][2] | a[0][3] |
    -------------------------------
    | a[1][0] | a[1][1] | a[1][2] |
    -------------------------------
    | a[2][0] | a[2][1] | a[2][2] |
    -------------------------------
    2. 1/2阶矩阵,大循环1次
       3/4阶矩阵,大循环2次
       n/n+1阶矩阵,大循环(n+1)/2次
##
##Induction:
##
##Summary:
##
##########################################################*/

#include<stdio.h>
#define N 500
int main() {
    
    int dst[N][N];
    int i,j,num,m,k=1;
    printf("please input int: ");
    scanf("%d",&num);

    if(num%2==0)
        m = num/2;
    else
        m = num/2+1;

    printf("Init array:\n");
    for(i=0;i<num;i++) {
        for(j=0;j<num;j++) {
            printf("%d    ",dst[i][j]);
        }
        printf("\n");
    }


    for(i=0;i<m;i++) {
        for(j=i;j<num-i;j++) {              //遍历上边一列的0-num
            dst[i][j] = k;
            k++;
        }
        //dst[0][num-i]
        for(j=i+1;j<mum-i;j++) {            // 此时[1][num-0-1]
            dst[j][num-i-1] = k;
            k++;
        }

        for(j=num-i-2;j>=i;j--) {
            dst[num-i-1][j] =k;
            k++;
        }

        for(j=num-2-i;j>i;j--) {
            dst[j][i] = k;
            k++;
        }
    }
    printf("Finish Fill Data:\n");
    for(i=0;i<num;i++) {
        for(j=0;j<num;j++) {
            printf("%d    ",dst[i][j]);
        }
        printf("\n");
    }

    return 0;
}

