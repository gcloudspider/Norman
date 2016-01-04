/*########################################################
##File Name: didi_core_manage.c
##Created Time:2016年01月04日 星期一 10时43分11秒
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
#include "../include/didi.h"

void* didi_thread_wakeup(void* argv){
    didi_tasklist_t* ptask = NULL;
    while(1){
        ptask = NULL;
        pthread_mutex_lock(&didi_td.mutex);
        pthread_cond_wait(&didi_td.cond,&didi_td.mutex);
        while(1){
            if(didi_td.qhead){
                ptask = didi_td.qhead;
                if(didi_td.qhead == didi_td.qtail){
                didi_td.qhead = didi_td.qtail = NULL;
                } else {
                didi_td.qhead = didi_td.qhead->next;
                }
            } else {
                break;
            }
            pthread_mutex_unlock(&didi_td.mutex);
            if(ptask){
                ptask->didi_func(ptask->argv);
                free(ptask);
            }
        }
    }
    return argv;
}

