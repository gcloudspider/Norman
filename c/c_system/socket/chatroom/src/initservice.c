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

int init_conf(SEVCF *cf,const char* cpath){
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

int init_db(USERINFO* uinfo,USERINFO** uhead,const char* dbpath){
    FILE* fp;
    USERINFO *p=NULL;

    fp=fopen(dbpath,"r+");
    if(NULL == fp){
        perror("fopen");
        return -1;
    }

    while(feof(fp)==0){
        uinfo = malloc(sizeof(USERINFO));
        if(NULL == uinfo){
            perror("malloc");
            return -1;
        }

        fscanf(fp,"%s\t%s\t%d\n",
                uinfo->username,
                uinfo->passwd,
                &uinfo->online);

        if(*uhead){
            uinfo->next = NULL;
            uinfo->pre = p;
            p->next = uinfo;
        } else {
            uinfo->next = *uhead;
            uinfo->pre = *uhead;
            *uhead = uinfo;
        }
        p= uinfo;
    }
    
    fclose(fp);
    return 0;
}

int init_thread_mutex(TD* td){
    return pthread_mutex_init(&td->mutex,NULL);
}

int init_thread_cond(TD* td){
    return pthread_cond_init(&td->cond,NULL);
}

int init_thread_pool(TD* td){
    int i;
    td->max_thread_num = DEFAULT_THREADNUM;
    td->qhead = NULL;
    td->qtail = NULL;
    for(i=0;i<td->max_thread_num;i++){
        pthread_create(&td->thread_id[i],NULL,thread_wakeup,NULL);
        pthread_detach(td->thread_id[i]);
    }
    return 0;
}

int init_socket(SOCK* sock,const char* ip,int port,int connum){
    int ret;
    int len;
    
    sock->sfd = socket(AF_INET,SOCK_STREAM,0);
    if(-1 == sock->sfd){
        perror("socket");
        return -1;
    }

    sock->sin.sin_family = AF_INET;
    sock->sin.sin_port = htons(port);

    if(inet_pton(AF_INET,ip,&sock->sin.sin_addr.s_addr)<=0){
        perror("inet_pton");
        return -1;
    }

    ret = bind(sock->sfd,(const struct sockaddr*)&sock->sin,(socklen_t)sizeof(sock->sin));
    if(-1 == ret){
        perror("bind");
        return -1;
    }

    ret = listen(sock->sfd,connum);
    if(-1 == ret){
        perror("listen");
        return -1;
    }
    return 0;
}
