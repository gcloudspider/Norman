/*########################################################
##File Name: nv_cond.c
##Created Time:2015年12月26日 星期六 19时31分47秒
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


int nv_init_thread_cond(pthread_cond_t* cond){
    return pthread_cond_init(cond,NULL);
}

void* nv_cond_login(void* argv){
    printf("%p\n",uhead);
}

void* nv_cond_logout(void* argv){
    
}

void* nv_cond_register(void* argv){
    
}

void* nv_cond_single_session(void* argv){
    
}

void* nv_cond_mutli_session(void* argv){
    
}

void* nv_cond_group_session(void* argv){
    
}

void* nv_cond_broad_session(void* argv){
    
}
