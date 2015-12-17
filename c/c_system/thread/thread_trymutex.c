/*########################################################
##File Name: thread_trymutex.c
##Created Time:2015年12月17日 星期四 20时32分57秒
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
#include "head.h"

pthread_mutex_t mutex1;
pthread_mutex_t mutex2;

char hello[1024];
char world[1024];

void* func_thread1(void *v){
    int i= 0,j=0,k;
    void *p = v;
    char *str[2] = {
        "hello","world"  
    };
    while(++j){
        //pthread_mutex_lock(&mutex1);     
        pthread_mutex_trylock(&mutex1);     
        //当前资源如果被锁，不阻塞继续其它任务
        //sleep(1);
        //pthread_mutex_lock(&mutex2);
        pthread_mutex_trylock(&mutex2);
            strcpy(hello,"hello");
            strcpy(world,"world");
        pthread_mutex_unlock(&mutex1);
        pthread_mutex_unlock(&mutex2);
    }
    return v;
}

void * func_thread2(void* v){
    int i =0;
    while(1){
        //pthread_mutex_lock(&mutex2);
        pthread_mutex_trylock(&mutex2);
        //pthread_mutex_lock(&mutex1); //阻塞
        pthread_mutex_trylock(&mutex1);
        for(i=0;hello[i];i++){
            putchar(hello[i]);
        }
        for(i=0;world[i];i++){
            putchar(world[i]);
        }
        pthread_mutex_unlock(&mutex1);
        pthread_mutex_unlock(&mutex2);
    }
    return v;
}

int main(){
    pthread_t ptid1;
    pthread_t ptid2;

    int ret;
    void *rret;

    pthread_mutex_init(&mutex1,NULL);  //初始化锁
    pthread_mutex_init(&mutex2,NULL);

    ret = pthread_create(&ptid1,NULL,func_thread1,NULL);
    ret = pthread_create(&ptid2,NULL,func_thread2,NULL);

    pthread_join(ptid1,&rret);
    pthread_join(ptid2,&rret);

    pthread_mutex_destroy(&mutex1);
    pthread_mutex_destroy(&mutex2);
    return 0;
}


