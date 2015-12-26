/*########################################################
##File Name: nv_mutex.c
##Created Time:2015年12月26日 星期六 19时28分08秒
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

int nv_init_thread_mutex(pthread_mutex_t* mutex){
    return pthread_mutex_init(mutex,NULL);
}
