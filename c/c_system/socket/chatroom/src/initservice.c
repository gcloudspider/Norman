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
    
    cf->server_ip = iniparser_getstring(ini,"SERVER:SERVER","ip not found!");
    cf->server_port = iniparser_getint(ini,"SERVER:PORT",-1);

    cf->server_connum = iniparser_getint(ini,"SERVER:CONNECT",-1);
    
    cf->server_threadnum = iniparser_getint(ini,"SERVER:THREADNUM",-1);

    cf->dbpath = iniparser_getstring(ini,"db:db","dbpath not found");
    
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
