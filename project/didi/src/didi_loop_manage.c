/*########################################################
##File Name: didi_loop_manage.c
##Created Time:2016年01月04日 星期一 09时56分20秒
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
int didi_init_mutex(pthread_mutex_t* mutex){
    return pthread_mutex_init(mutex,NULL);
}

int didi_init_cond(pthread_cond_t* cond){
    return pthread_cond_init(cond,NULL);
}

int didi_init_pool(didi_thread_t* didi_td){
    int i;
    didi_td->max_thread_num = DEFAULT_THREADNUM;
    didi_td->qhead = NULL;
    didi_td->qtail = NULL;
    for(i=0;i<didi_td->max_thread_num;i++){
        pthread_create(&didi_td->pthread_id[i],NULL,didi_thread_wakeup,NULL);
        pthread_detach(didi_td->pthread_id[i]);
    }
    return 0;
}

int didi_init_loop(zlog_category_t **c){
    int ret;
    //初始化互斥锁
    ret = didi_init_mutex(&didi_td.mutex);
    if(-1 == ret){
        zlog_info(*c,"init thread mutex failed!\n");
        exit(2);
    }
    zlog_info(*c,"init thread mutex successfuly!\n");

    //初始化条件变量

    ret = didi_init_cond(&didi_td.cond);
    if(-1 == ret){
        zlog_info(*c,"init thread cond failed!\n");
        exit(2);
    }
    zlog_info(*c,"init thread mutex successfuly!\n");

    //初始化线程池
    
    ret = didi_init_pool(&didi_td);
    if(-1 == ret){
        zlog_info(*c,"init thread pool failed!\n");
        exit(2);
    }
    zlog_info(*c,"init thread mutex successfuly!\n");
}

