/*########################################################
##File Name: thread_pool.c
##Created Time:2015年12月26日 星期六 15时10分11秒
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
#include "../include/chatserver.h"

int init_thread_pool(TD* td){
    int i;
    td->max_thread_num = DEFAULT_THREADNUM;
    td->qhead = NULL;
    td->qtail = NULL;
    for(i=0;i<td->max_thread_num;i++){
        pthread_create(&td->thread_id[i],NULL,thread_wakeup,NULL);
        pthread_detach(td->thread_id[i]);
    }
    return 0;
}


void* thread_wakeup(void* argv){
    QTASKLIST* ptask = NULL;
    while(1){
        ptask = NULL;
        pthread_mutex_lock(&td.mutex);
        pthread_cond_wait(&td.cond,&td.mutex);
        while(1){
            printf("thread id:%ld actived!\n",gettid());
            if(td.qhead){
                ptask = td.qhead;
                if(td.qhead == td.qtail){
                    td.qhead = td.qtail = NULL;
                } else {
                    td.qhead = td.qhead->next;
                }
            } else {
                printf("queue no task! thread id:%ld waiting....!\n",gettid());
                break;
            }
            pthread_mutex_unlock(&td.mutex);
            if(ptask){
                ptask->function(ptask->argv);
                printf("thread id:%ld release work address:%p!\n",gettid(),ptask);
                free(ptask);
            }    
        }   
    }
    return argv;
}
