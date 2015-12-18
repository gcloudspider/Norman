/*########################################################
##File Name: thread_sem.c
##Created Time:2015年12月18日 星期五 14时10分43秒
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

#define THREADNUM 3
#define REPEAT_TIMES 2
#define DELAY 4
sem_t sem;

void* func_sem(void* v){
    int thread_num = (int)v;
    int delay_time,count;

    sem_wait(&sem);
    printf("Thread %d is starting.\n",thread_num);
    for(count =0;count<REPEAT_TIMES;count++){
        delay_time=(int)(DELAY*(rand()/(double)RAND_MAX))+1;
        sleep(delay_time);
        printf("\tThread %d:job %d delay=%d.\n",thread_num,count,delay_time);
    }
    printf("Thread %d is exiting.\n",thread_num);

    sem_post(&sem);
    pthread_exit(NULL);
}

int main(){
    pthread_t ptid[THREADNUM];
    void *rret;
    int i;

    srand((int)time(0));
    sem_init(&sem,0,3);
    
    for(i=0;i<THREADNUM;i++){
        pthread_create(&ptid[i],NULL,func_sem,(void*)i);
    }

    for(i=0;i<THREADNUM;i++){
        pthread_join(ptid[i],&rret);
    }

    for(i=0;i<THREADNUM;i++){
        sem_destroy(&sem);
    }

    return 0;
}
