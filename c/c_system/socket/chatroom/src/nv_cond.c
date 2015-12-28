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
    USERINFO* pn = NULL;
    int ret;
    int cfd = (int) argv;
    printf("cond_login cfd=%d\n",cfd);
    char buf[1024];

    //ret = recv(cfd,buf,sizeof(buf),0);
    ret = read(cfd,&p.body,sizeof(p.body));
    if(-1 == ret){
        perror("recv");
        return ;
    }
    
    //Issues1: thread debug ?
    printf("read data username=%spasswd=%s\n",p.body.signin.username,p.body.signin.passwd);
    ret = nv_auth_user(p.body.signin.username,p.body.signin.passwd);
    
    printf("login result = %d\n",ret);

    switch(ret){
        case 0:
            p.body.signin.result = 0;
            memcpy(p.body.signin.resMsg,"Auth passwd success!",strlen("Auth passwd success!"));
            break;
        case 1:
            p.body.signin.result = 1;
            memcpy(p.body.signin.resMsg,"User not exist!",strlen("User not exist!"));
            break;
        case 2:
            p.body.signin.result = 2;
            memcpy(p.body.signin.resMsg,"Auth passwd failed!",strlen("Auth passwd failed!"));
            break;
        default:
            break;
    }
    
    p.head.type = 1;
    p.head.version = 1;

    write(cfd,&p.head,sizeof(p.head));
    write(cfd,&p.body,sizeof(p.body));

    return argv;
}

void* nv_cond_logout(void* argv){
    
}

void* nv_cond_register(void* argv){
    int ret;
    struct package p;
    char buf[1024];
    int cfd = (int)argv;

    ret = read(cfd,&p.body,sizeof(p.body));
    if(-1 == ret){
        perror("read");
    }

    return argv;
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
