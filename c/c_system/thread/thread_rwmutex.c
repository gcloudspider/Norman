/*########################################################
##File Name: thread_rwmutex.c
##Created Time:2015年12月17日 星期四 21时06分50秒
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
pthread_rwlock_t mutex1;
//pthread_mutex_t mutex1;
char hello[1024] = "hello";

void *func_thread1(void* v){
    int i=0,j=0,k;
    void*p = v;
    char *str[2]={
        "hello","world"
    };
    while(++j){
        //pthread_mutex_lock(&mutex1);    //若资源被占用阻塞
        pthread_rwlock_wrlock(&mutex1);
        sleep(3);
            strcpy(hello,"hello");
        pthread_rwlock_unlock(&mutex1);
        //pthread_mutex_unlock(&mutex1);
        usleep(1000*500);
    }
    return v;
}

void* func_thread2(void* v){
    int i =0;
    while(1){
        pthread_rwlock_wrlock(&mutex1);
        //pthread_mutex_lock(&mutex1);
        printf("2 %s\n",hello);
        pthread_rwlock_unlock(&mutex1);
        //pthread_mutex_unlock(&mutex1);
        usleep(1000*100);
    }
    return v;
}

void* func_thread3(void* v){
    int i = 0;
    while(1){
        pthread_rwlock_rdlock(&mutex1);
        //pthread_mutex_lock(&mutex1);
        printf("3 %s\n",hello);
        sleep(5);
        pthread_rwlock_unlock(&mutex1);
        //pthread_mutex_unlock(&mutex1);
        usleep(1000*200);
    }
    return v;
}


int main(){
    pthread_t ptid1;
    pthread_t ptid2;
    pthread_t ptid3;
    int ret;
    void *rret;
    pthread_rwlock_init(&mutex1,NULL);
    //pthread_mutex_init(&mutex1,NULL);

    ret = pthread_create(&ptid2,NULL,func_thread2,NULL);
    ret = pthread_create(&ptid3,NULL,func_thread3,NULL);

    pthread_join(ptid1,&rret);
    pthread_join(ptid2,&rret);

    pthread_rwlock_destroy(&mutex1);
    //pthread_mutex_destroy(&mutex1);

    return 0;
}
