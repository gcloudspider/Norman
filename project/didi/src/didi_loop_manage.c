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

int didi_init_socket(didi_socket_t *sock,const char* ip,int port,int connect){
    int ret;
    int len;
    sock->sfd = socket(AF_INET,SOCK_STREAM,0);
    if(-1 == sock->sfd){
        return -1;
    }

    sock->sin.sin_family = AF_INET;
    sock->sin.sin_port = htons(port);
    if(inet_pton(AF_INET,ip,&sock->sin.sin_addr.s_addr)<=0){
        return -1;
    }

    ret = bind(sock->sfd,(const struct sockaddr*)&sock->sin,(socklen_t)sizeof(sock->sin));
    if(-1 == ret){
        return -1;
    }

    ret = listen(sock->sfd,connect);
    if(-1 == ret){
        return -1;
    }
    return 0;
}

int didi_init_epoll(didi_thread_t* didi_td,int threadnum){
    didi_td->eh = epoll_create(threadnum);
    if(-1 == didi_td->eh){
        return -1;
    }
    return 0;
}

int didi_add_epoll(didi_thread_t *didi_td,int fd){
    didi_td->ev.data.fd = fd;
    didi_td->ev.events = EPOLLIN|EPOLLET;
    epoll_ctl(didi_td->eh,EPOLL_CTL_ADD,fd,&didi_td->ev);
}

int didi_found_epoll(int eh,struct epoll_event evs[10]){
    return epoll_wait(eh,evs,10,-1);
}

int didi_init_loop(didi_socket_t sock_t,didi_server_t server,zlog_category_t **c){
    int ret,len;
    //didi_socket_t sock_t;

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

    //初始化Socket对象
    ret = didi_init_socket(&sock_t,server.hostip,server.port,server.connect);
    if(-1 == ret){
        zlog_info(*c,"init socket failed!\n");
        exit(2);
    }
    zlog_info(*c,"init socket successfuly!\n");

    //初始化epoll
    ret = didi_init_epoll(&didi_td,server.threadnum);
    if(-1 == ret){
        zlog_info(*c,"init epoll failed!\n");
        exit(2);
    }
    zlog_info(*c,"init epoll successfuly!\n");

    didi_add_epoll(&didi_td,sock_t.sfd);
}

int didi_release_socket(didi_socket_t sock_t,zlog_category_t **c){
    close(sock_t.sfd);
    zlog_info(*c,"release socket successfuly!\n");
}
