/*########################################################
##File Name: iniparse.c
##Created Time:2015年12月26日 星期六 09时27分26秒
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
#include "../include/iniparser.h"

int nv_init_conf(SEVCF *cf,const char* cpath){
    dictionary* ini;

    ini = iniparser_load(cpath);
    if(NULL == ini){
        fprintf(stderr,"cannot parse file:%s\n",cpath);
        return -1;
    }
    //iniparser_dump(ini,stderr);
    
    cf->server_ip = iniparser_getstring(ini,CONF_SERVER_IP,CUSTOM_PROMPT_IP);
    cf->server_port = iniparser_getint(ini,CONF_SERVER_PORT,-1);

    cf->server_connum = iniparser_getint(ini,CONF_SERVER_CONNUM,-1);
    
    cf->server_threadnum = iniparser_getint(ini,CONF_SERVER_THREADNUM,-1);

    cf->dbpath = iniparser_getstring(ini,CONF_DB_PATH,CUSTOM_PROMPT_DB);
    
    return 0;
}

void nv_parse_msg(int cfd){
    struct package p;
    struct sockaddr_in tcin;
    char buf[1024]={0};
    int ret;
    int len = sizeof(tcin);

    ret = read(cfd,&p.head,sizeof(p.head));
    if(ret <=0){
        getpeername(cfd,(struct sockaddr*)&tcin,(socklen_t*)&len);
        printf("client ip=%s,port=%d disconnect!\n",inet_ntop(AF_INET,&tcin.sin_addr.s_addr,buf,15),ntohs(tcin.sin_port));
        close(cfd);
        nv_del_epoll(cfd);
        return ;
    }
    printf("parser head type=%d\n",p.head.type);

    switch(p.head.type){
        case SIGNIN:
            printf("login signal!\n");
            nv_pool_add_task(nv_cond_login,(void*)cfd);
            break;
        case SIGNUP:
            printf("register signal!\n");
            nv_pool_add_task(nv_cond_register,(void*)cfd);
            break;
        case ONLINE:
            nv_pool_add_task(nv_cond_online_user,(void*)cfd);
            break;
        case LOGOUT:
            nv_pool_add_task(nv_cond_logout,(void*)cfd);
            break;
        case SINGLE_SESSION:
            nv_pool_add_task(nv_cond_single_session,(void*)cfd);
            break;
        case GROUP_SESSION:
            nv_pool_add_task(nv_cond_group_session,(void*)cfd);
            break;
        case MULTI_SESSION:
            nv_pool_add_task(nv_cond_mutli_session,(void*)cfd);
            break;
        case BROAD_SESSION:
            nv_pool_add_task(nv_cond_broad_session,(void*)cfd);
            break;
        default:
            break;
    }
}







