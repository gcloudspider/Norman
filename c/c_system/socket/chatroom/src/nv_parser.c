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
    int ret;
    struct package p;

    ret = read(cfd,&p.head,sizeof(p.head));
    if(ret <=0){
        close(cfd);
        nv_del_epoll(cfd);
        return ;
    }

    switch(p.head.type){
        case 1:
            nv_pool_add_task(nv_cond_login,(void*)cfd);
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            break;
        case 8:
            break;
        default:
            break;
    }
}







