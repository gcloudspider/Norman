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
    struct package p;
    int ret;
    int cfd = (int) argv;
    printf("cond_login cfd=%d\n",cfd);

    ret = read(cfd,&p.body.signin,1024);
    if(-1 == ret){
        perror("read");
        return ;
    }
    printf("read data %s!\n",p.body.signin.username);
    //Issues1: thread debug ?
    //printf("%s%s\n",p.body.signin.username,p.body.signin.passwd);
    
    return argv;
}

void* nv_cond_logout(void* argv){
    
}

void* nv_cond_register(void* argv){
    
}

void* nv_cond_online_user(void* argv){

}

void* nv_cond_single_session(void* argv){
    
}

void* nv_cond_mutli_session(void* argv){
    
}

void* nv_cond_group_session(void* argv){
    
}

void* nv_cond_broad_session(void* argv){
    
}
