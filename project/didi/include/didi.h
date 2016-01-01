/*########################################################
##File Name: didi.h
##Created Time:2015年12月29日 星期二 20时49分13秒
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

#ifndef _didi_H
#define _didi_H
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<sys/stat.h>
#include<getopt.h>
#include<sys/types.h>
#include<sys/syscall.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/mman.h>
#include<sys/ioctl.h>
#include<dirent.h>
#include<sys/time.h>
#include<signal.h>
#include<sys/ipc.h>
#include<sys/sem.h>
#include<sys/msg.h>
#include<sys/shm.h>
#include<pthread.h>
#include<semaphore.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<sys/epoll.h>

#include<zlog.h>

//prompt
#define CUSTOM_PROMPT_IP        "ip not found!"
#define CUSTOM_PROMPT_DB        "host not found!"
#define CUSTOM_PROMPT_DBNAME    "dbname not found!"
#define CUSTOM_PROMPT_DBUSER    "db username not found!"
#define CUSTOM_PROMPT_DBPASSWD  "db passwd not found!"
#define CUSTOM_PROMPT_LOG       "log path not found!"
//server
#define CONF_SERVER_IP          "server:hostname"
#define CONF_SERVER_PORT        "server:port"
#define CONF_SERVER_CONNUM      "server:connect"
#define CONF_SERVER_THREADNUM   "server:threadnum"
//db
#define CONF_DB_HOSTNAME        "mysql:hostname"
#define CONF_DB_NAME            "mysql:dbname"
#define CONF_DB_USERNAME        "mysql:username"
#define CONF_DB_PASSWD          "mysql:passwd"
//log
#define CONF_LOG_PATH           "log:logconf"

#define DEFAULT_SERVER          "0.0.0.0"
#define DEFAULT_PORT            8080
#define DEFAULT_CONNUM          100
#define DEFAULT_THREADNUM       100

#define DEFAULT_CFGPATH         "../conf/didi.conf"

typedef struct server{
    const char *hostip;
    int  port;
    int  connect;
    int  threadnum;
}SERVER;

typedef struct mysql{
    const char* hostname;
    const char* dbname;
    const char* username;
    const char* passwd;
}MYSQL;

typedef struct log{
    const char* logconf;
}LOG;

typedef struct conf{
    struct server server;
    struct mysql mysql;
    struct log log;
}CF;

//function
//
int didi_conf_init(CF *cf,const char* cpath);

int didi_log_init(zlog_category_t **c,const char* logpath);
int didi_log_release();

//db
int didi_db_init(MYSQL *db);

#endif
