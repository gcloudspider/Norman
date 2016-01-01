/*########################################################
##File Name: didi_parse_conf.c
##Created Time:2015年12月29日 星期二 20时52分36秒
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
#include "../include/iniparser.h"

int didi_conf_init(CF *cf,const char* cpath){
    dictionary* ini;

    ini = iniparser_load(cpath);
    if(NULL == ini){
        fprintf(stderr,"cannot parse file:%s\n",cpath);
        return -1;    
    }
    
    //iniparser_dump(ini,stderr);
    
    cf->server.hostip = iniparser_getstring(ini,CONF_SERVER_IP,CUSTOM_PROMPT_IP);
    cf->server.port = iniparser_getint(ini,CONF_SERVER_PORT,-1);
    cf->server.connect = iniparser_getint(ini,CONF_SERVER_CONNUM,-1);
    cf->server.threadnum = iniparser_getint(ini,CONF_SERVER_THREADNUM,-1);
    
    cf->mysql.hostname = iniparser_getstring(ini,CONF_DB_HOSTNAME,CUSTOM_PROMPT_DB);
    cf->mysql.dbname = iniparser_getstring(ini,CONF_DB_NAME,CUSTOM_PROMPT_DBNAME);
    cf->mysql.username = iniparser_getstring(ini,CONF_DB_USERNAME,CUSTOM_PROMPT_DBUSER);
    cf->mysql.passwd = iniparser_getstring(ini,CONF_DB_PASSWD,CUSTOM_PROMPT_DBPASSWD);
    
    cf->log.logconf = iniparser_getstring(ini,CONF_LOG_PATH,CUSTOM_PROMPT_LOG);
    return 0;
}
