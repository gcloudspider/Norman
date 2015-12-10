/*########################################################
##File Name: sysfork.c
##Created Time:2015年12月10日 星期四 16时56分48秒
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
#include<unistd.h>
#include<stdlib.h>
int a = 0;

void faterprocess(){
    while(1){
        a++;
        if(a>5){
            exit(0);
        }
        printf("f %d\n",a);
    }
}

void childprocess(){
    a++;
    while(1){
        a++;
        if(a>10)
            exit(0);
        printf("c %d\n",a);
    }
}

int main(){
    int pi;
/*
    pi = fork();
    if (pi>0){
        faterprocess();
    } else if(pi ==0){
        childprocess();
    } else {
      perror("fork");  
    }*/

    pid_t pid1;
    pid_t pid2;
    pid1 = fork();
    pid2 = fork();
    printf("pid1:%d,pid2:%d\n",pid1,pid2);
    return 0;
}
