/*########################################################
##File Name: thread_epoll.c
##Created Time:2015年12月26日 星期六 17时43分14秒
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

int nv_init_epoll(int threadnum){
    eh = epoll_create(threadnum);
    if(-1 == eh){
        perror("epoll_create");
        return -1;
    }
    return 0;
}

int nv_add_epoll(int fd){
    ev.data.fd = fd;
    ev.events = EPOLLIN|EPOLLET;
    epoll_ctl(eh,EPOLL_CTL_ADD,fd,&ev);
}

int nv_found_epoll(){
    return epoll_wait(eh,evs,10,-1);
}

int nv_del_epoll(int fd){
    ev.data.fd = fd;
    epoll_ctl(eh,EPOLL_CTL_DEL,fd,&ev);
}
