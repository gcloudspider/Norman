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

#define MAX 2147483647
#include<stdio.h>
long re(long int a){
    long int t;
    for(t=0;a>0;a/=10)
        t=t*10+a%10;
    return t;
}

int nonre(long int s){
    if(re(s)==s)
        return 1;
    else return 0;
}

int main(){
    long int n,m,re();
    int count = 0;
    printf("please enter a number optionaly:");
    scanf("%ld",&n);
    printf("the generation process of palindrome:\n");
    while(!nonre((m=re(n))+n)){
        if(m+n>=MAX){
            printf("input error,break.\n");
            break;
        }else {
            printf("[%d]:%ld+%ld=%ld\n",++count,n,m,m+n);
            n+=m;
        }
    }
    printf("[%d]:%ld+%ld=%ld\n",++count,n,m,m+n);
    printf("here we reached the aim at last!\n");
}



