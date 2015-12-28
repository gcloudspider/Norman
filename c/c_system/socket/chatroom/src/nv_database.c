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


int nv_init_db(USERINFO* uinfo,const char* dbpath){
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

        if(uhead){
            uinfo->next = NULL;
            uinfo->pre = p;
            p->next = uinfo;
        } else {
            uinfo->next = uhead;
            uinfo->pre = uhead;
            uhead = uinfo;
        }
        p= uinfo;
    }
    
    fclose(fp);
    return 0;
}

int nv_print_online_user(USERINFO* uhead){
    USERINFO* pn;
    
    pn = uhead;
    if(uhead){
        printf("Online user:\n");
        while(pn){
            if(pn->online){
                printf("%s\n",pn->username);
            }
            pn= pn->next;
        }
    }
}

int nv_print_all_user(){
    USERINFO *pn;
    pn = uhead;
    if(uhead){
        while(pn){
            printf("%s\n",pn->username);
            pn = pn->next;
        }
    }
}

int nv_auth_user(const char* username,const char* passwd){
    USERINFO* pn;
    int ret;

    pn = uhead;
    if(uhead){
        while(pn){
            if(strcmp(pn->username,username)==0){
                if(strcmp(pn->passwd,passwd)==0){
                    pn->online = 1;
                    ret = 0;
                    break;
                } else {
                    ret = 2;
                    break;
                }   
            } else{
                ret = 1;
            }
            pn = pn->next;
        }
    }
    
    return ret;
}
