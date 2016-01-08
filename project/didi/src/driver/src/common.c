/*########################################################
##File Name: common.c
##Created Time:2016年01月05日 星期二 08时41分15秒
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
#include<uuid/uuid.h>
#include"../include/user.h"

char *random_uuid(char* buf) {
    uuid_t uuid;
    
    uuid_generate(uuid);
    uuid_unparse(uuid, buf);
              
    return buf;
}

void handle_message(){
    pthread_t ttid01,ttid02;
    void* rret;

    pthread_create(&ttid01,NULL,thread_read,(void*)sfd);
    //pthread_create(&ttid02,NULL,thread_write,(void*)sfd);
    pthread_join(ttid01,&rret);
    //pthread_join(ttid02,&rret);
}

void handle_taketoken(){
    pthread_t ttid01,ttid02;
    void* rret;
    pthread_create(&ttid01,NULL,take_token,(void*)sfd);
    pthread_detach(ttid01);

}

void generate_curtime(char* buf){
    srand((int)time(0));   
  
    struct tm *p;
    time_t second;
    time(&second);
           
    p = localtime(&second);
             
    //char buf[100] = {0};
 
    sprintf(buf, "%d-%d-%d %d:%d:%d", 1900+p->tm_year, 1+p->tm_mon, p->tm_mday,p->tm_hour, p->tm_min, p->tm_sec);
  
}
