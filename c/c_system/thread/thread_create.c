/*########################################################
##File Name: thread_create.c
##Created Time:2015年12月16日 星期三 14时31分03秒
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
#include<pthread.h>
#include "head.h"

void* print_world(void* v){
    int j = 10;
    while(j--){
        sleep(1);
        printf("thread1!%d\n",*(int*)v);
    }
    return (void*)100;
}

void* print_world2(void* v){
    while(1){
        sleep(1);
        printf("thread2!%d\n",(int)v);
    }
    return ;
}

int main(){
    pthread_t threadid;
    pthread_t threadid2;
    int i = 100;
    void *value;

    pthread_create(&threadid,NULL,print_world,&i);
    pthread_create(&threadid2,NULL,print_world2,(void *)100);

    pthread_join(threadid,&value);      //等待子线程执行完
    printf("main wait thread1 finised! result=%d\n",(int)value);

    return 0;
}
