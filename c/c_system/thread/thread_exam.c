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

pthread_rwlock_t mutex;

int stunum = 0;

void* func_teacher(void* v){
    int n=0;
    int count = 1;
    while(stunum<=30){
        if(n== stunum) n=stunum;
        if((n!=0)&&(n%10 ==0)){
            printf("happy happy!\n");
            count++;
        }
        if(count == 3)break;
    }
}

void* func_student(void* v){
    int time;
    time = rand()%10+1;
    printf("thread=%d time=%d\n",(int)v,time);
    sleep(time);
    stunum++;
    if(stunum == 10){
        pthread_rwlock_wrlock(&mutex);
        if(stunum == 0){
            pthread_rwlock_unlock(&mutex);
        }
    }

}

int main(){
    int i;
    void* rret;
    pthread_t ptid[30],tea;
    
    pthread_rwlock_init(&mutex,NULL);
    pthread_create(&tea,NULL,func_teacher,NULL);
    for(i=0;i<30;i++){
        pthread_create(&ptid[i],NULL,func_student,(void*)i);
        pthread_detach(ptid[i]);
    }

    pthread_join(tea,&rret);

    return 0;
}
