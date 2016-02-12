/**
*  - version 1.0
* -------------------------------
* Copyright (C) 2016-2016 by Norman (none_lih@163.com) 
* Report bugs and download new versions at https//github.com/evely211
* 
* This library is distributed under the MIT License. See notice at the end of this file.
* This work is based on POSIX，which is:
* Copyright (C) 2016,by Norman
*/
#include<stdlib.h>
#include<stdio.h>
#include<time.h>

int main(){
    time_t m_time;
    int a,b;
    int sum;
    a = rand()%100;
    srand(time(&m_time));

    b = rand()%100;
    printf("%d+%d=",a,b);
    scanf("%d",&sum);
    if(sum==a+b)
        printf("Answer is true\n");
    else
        printf("Answer is false\n");
}
