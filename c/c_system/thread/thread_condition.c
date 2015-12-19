/*########################################################
##File Name: thread_condition.c
##Created Time:2015年12月18日 星期五 15时12分09秒
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
pthread_cond_t cond;

int num =0;

void* student(void *v){
    int time;
    time = rand()%10+1;
    printf("student %d get running...time=%d\n",(int)v,time);
    sleep(time);
    pthread_mutex_lock(&mutex);
    num++;
    printf("student %d finish! num=%d\n",(int)v,num);
    if(num%10 == 0){
        pthread_cond_signal(&cond);     //触发条件，
    }
    pthread_mutex_unlock(&mutex);
    return v;
}

void* teacher(void* v){
    int k = 0;
    int n=0;
    while(1){
        pthread_cond_wait(&cond,&mutex);  //醒来
        printf("drink beer!num=%d k=%d\n",num,++k);

        if(num==30)break;
    }
    printf("teacher finish!!!\n");
    return v;
}

int main(){
    pthread_t tid[30],t;
    int i;
    void *ret;

    srand((int)time(0));
    printf("hello,condition variable test\n");
    pthread_mutex_init(&mutex,NULL);
    pthread_cond_init(&cond,NULL);      //条件变量初始化

    pthread_create(&t,NULL,teacher,NULL);
    sleep(1);

    for(i=0;i<30;i++){
        pthread_create(&tid[i],NULL,student,(void*)i);
    }

    for(i=0;i<30;i++){
        pthread_detach(tid[i]);
    }
    pthread_join(t,&ret);

    pthread_exit(0);
}
