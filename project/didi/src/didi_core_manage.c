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


int didi_run(didi_socket_t sock_t,zlog_category_t **c){
    int nfound,len;
    int i;
    int cfd;
    char buf[1024] = {0};

    len = sizeof(sock_t.sin);

    while(1){
        nfound = didi_found_epoll(didi_td.eh,didi_td.evs);
        if(nfound < 0){
            zlog_info(*c,"epoll_wait error!\n");
            continue;
        } else if(nfound == 0){
            zlog_info(*c,"time out!\n");
            continue;
        } else {
            for(i=0;i<nfound;i++){
                if(didi_td.evs[i].data.fd == sock_t.sfd){
                    cfd = accept(sock_t.sfd,(struct sockaddr*)&sock_t.cin,(socklen_t*)&len);
                    zlog_info(*c,"client connect ip=%s port=%d\n",inet_ntop(AF_INET,&sock_t.cin.sin_addr.s_addr,buf,15),ntohs(sock_t.cin.sin_port));
                    if(-1 == cfd){
                        zlog_info(*c,"accept error!\n");
                        continue;
                    } else {
                        didi_td.ev.data.fd = cfd;
                        didi_add_epoll(&didi_td,cfd);
                        continue;
                    }
                }else if (didi_td.evs[i].events == EPOLLIN|EPOLLET){
                    didi_parse_msg(didi_td.evs[i].data.fd);
                }
            }
        }
    }
    return 0;
}

void didi_parse_msg(int cfd){

}
