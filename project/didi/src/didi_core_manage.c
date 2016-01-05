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


int didi_run(didi_socket_t sock_t){
    int nfound,len;
    int i;
    int cfd;
    char buf[1024] = {0};

    len = sizeof(sock_t.sin);

    while(1){
        nfound = didi_found_epoll(didi_td.eh,didi_td.evs);
        zlog_info(c,"epoll wait found %d evs",nfound);
        if(nfound < 0){
            zlog_warn(c,"epoll_wait error!");
            continue;
        } else if(nfound == 0){
            zlog_warn(c,"time out!");
            continue;
        } else {
            for(i=0;i<nfound;i++){
                if(didi_td.evs[i].data.fd == sock_t.sfd){
                    zlog_info(c,"evs fd=%d sock_t.sfd=%d ",didi_td.evs[i].data.fd,sock_t.sfd);
                    cfd = accept(sock_t.sfd,(struct sockaddr*)&sock_t.cin,(socklen_t*)&len);
                    zlog_info(c,"client connect ip=%s port=%d",inet_ntop(AF_INET,&sock_t.cin.sin_addr.s_addr,buf,15),ntohs(sock_t.cin.sin_port));
                    if(-1 == cfd){
                        zlog_error(c,"accept error!");
                        continue;
                    } else {
                        didi_td.ev.data.fd = cfd;
                        didi_add_epoll(&didi_td,cfd);
                        continue;
                    }
                }else if (didi_td.evs[i].events == EPOLLIN|EPOLLET){
                    zlog_warn(c,"trigger event!!!!!");
                    didi_parse_msg(didi_td.evs[i].data.fd);
                }
            }
        }
    }
    return 0;
}

void didi_parse_msg(int cfd){
    struct sockaddr_in tcin;
    char buf[1024] = {0};
    int ret;
    cJSON* root,*headnode;
    cJSON *item,*item2;
    int len = sizeof(tcin);

    ret = read(cfd,buf,1024);
    zlog_info(c,"read cfd buf=%s",buf);
    if(ret <=0){
        getpeername(cfd,(struct sockaddr*)&tcin,(socklen_t*)&len);
        zlog_warn(c,"client ip=%s,port=%d disconnect!",inet_ntop(AF_INET,&tcin.sin_addr.s_addr,buf,15),ntohs(tcin.sin_port));
        close(cfd);
        didi_del_epoll(cfd);
        return ;
    } 
    didi_convert_string(&root,buf);
    zlog_info(c,"root=%p",root);
    headnode = didi_getjson_node(root,"head");
    zlog_info(c,"head node=%p",headnode);
    item = didi_getitem_node(headnode,"packtype");
    zlog_info(c,"headnode packtype=%d",item->valueint);
    if(item->valueint == PACKTYPE_REQUEST){
        item2 = didi_getitem_node(headnode,"event");
        zlog_info(c,"headnode event=%d",item2->valueint);
        switch(item2->valueint){
            case EVENT_REGISTER:
                zlog_warn(c,"event register user");
                didi_add_task(didi_event_register,(void*)cfd);
                break;
            case EVENT_LOGIN:
                zlog_warn(c,"event user login!");
                didi_add_task(didi_event_login,(void*)cfd);
                break;
            case EVENT_LOGOUT:
                zlog_warn(c,"event user logout!");
                didi_add_task(didi_event_logout,(void*)cfd);
                break;
            case EVENT_QUERY:
                zlog_warn(c,"event query user order!");
                didi_add_task(didi_event_query,(void*)cfd);
                break;
            default:
                break;
        }
    }
}

void didi_add_task(DIDI_FUNC_POINT didi_func,void* argv){
    didi_tasklist_t* ptask = malloc(sizeof(didi_tasklist_t));
    ptask->didi_func = didi_func;
    ptask->argv = argv;
    zlog_info(c,"add cfd=%d to task list",(int)argv);
    pthread_mutex_lock(&didi_td.mutex);
    if(didi_td.qhead){
        didi_td.qtail->next = ptask;
        didi_td.qtail = ptask;
    } else {
        didi_td.qtail = ptask;
        didi_td.qhead = didi_td.qtail;
    }
    pthread_mutex_unlock(&didi_td.mutex);
    pthread_cond_signal(&didi_td.cond);
}
