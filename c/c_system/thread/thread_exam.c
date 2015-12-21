/*########################################################
##File Name: thread_exam.c
##Created Time:2015年12月18日 星期五 10时00分19秒
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

pthread_mutex_t mutex;

int stunum = 0;

void* func_teacher(void* v){
    int n=0;
    int k=0;
    int count = 1;
    while(1){
        pthread_mutex_lock(&mutex);
        if(stunum == 10){
            printf("drink beer!beer!beer! num=%d k=%d\n",n,++k);
            stunum = 0;
        }
        if(k==3)break;
        pthread_mutex_unlock(&mutex);
    }
    printf("teacher finish!!!\n");
    return v;
}

void* func_student(void* v){
    int time;
    time = rand()%10+1;
    printf("thread=%d get running... time=%d\n",(int)v,time);
    sleep(time);
    pthread_mutex_lock(&mutex);
    stunum++;
    printf("thread %d finish!\n",(int)v);
    pthread_mutex_unlock(&mutex);
    return v;
}

int main(){
    int i;
    void* rret;
    pthread_t ptid[30],tea;
    
    pthread_mutex_init(&mutex,NULL);
    pthread_create(&tea,NULL,func_teacher,NULL);
    for(i=0;i<30;i++){
        pthread_create(&ptid[i],NULL,func_student,(void*)i);
        pthread_detach(ptid[i]);
    }

    pthread_join(tea,&rret);

    return 0;
}
