/*########################################################
##File Name: nv_database.c
##Created Time:2015年12月26日 星期六 19时30分12秒
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

