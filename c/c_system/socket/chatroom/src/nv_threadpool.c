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

int nv_init_thread_pool(TD* td){
    int i;
    td->max_thread_num = DEFAULT_THREADNUM;
    td->qhead = NULL;
    td->qtail = NULL;
    for(i=0;i<td->max_thread_num;i++){
        pthread_create(&td->thread_id[i],NULL,nv_thread_wakeup,NULL);
        pthread_detach(td->thread_id[i]);
    }
    return 0;
}


void* nv_thread_wakeup(void* argv){
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

void nv_pool_add_task(FUNC_POINT function,void* argv){
    QTASKLIST* ptask = malloc(sizeof(QTASKLIST));
    printf("malloc task address:%p\n",ptask);
    ptask->function = function;
    ptask->argv = argv;
    pthread_mutex_lock(&td.mutex);
    if(td.qhead){
        td.qtail->next = ptask;
        td.qtail = ptask;
    } else {
        td.qtail = ptask;
        td.qhead = td.qtail;
    }
    pthread_mutex_unlock(&td.mutex);
    pthread_cond_signal(&td.cond);
}
