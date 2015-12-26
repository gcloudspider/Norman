/*########################################################
##File Name: head.h
##Created Time:2015年12月09日 星期三 12时18分25秒
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

#ifndef _CHATSERVER_H
#define _CHATSERVER_H
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

#define gettid() syscall(__NR_gettid)

/*const*/
#define CUSTOM_PROMPT_IP        "ip not found!"
#define CUSTOM_PROMPT_DB        "dbpath not found!"

#define CONF_SERVER_IP          "SERVER:SERVER"
#define CONF_SERVER_PORT        "SERVER:PORT"
#define CONF_SERVER_CONNUM      "SERVER:CONNECT"
#define CONF_SERVER_THREADNUM   "SERVER:THREADNUM"
#define CONF_DB_PATH            "db:db"

#define DEFAULT_SERVER          "127.0.0.1"
#define DEFAULT_PORT            8080
#define DEFAULT_CONNUM          100
#define DEFAULT_THREADNUM       100

#define DEFAULT_CFGPATH         "../conf/chatroom.cfg"


/*struct*/
typedef struct servercfg{
    const char* server_ip;
    int  server_port;
    int  server_connum;
    int  server_threadnum;
    const char* dbpath;
}SEVCF;

typedef struct userinfo{
    int fd;
    int online;
    char username[64];
    char passwd[128];
    struct userinfo *pre;
    struct userinfo *next;
}USERINFO;

typedef void*(*FUNC_POINT)(void* argv);
typedef struct tasklist{
    FUNC_POINT function;
    void* argv;
    struct tasklist *next;
}QTASKLIST;

typedef struct thread{
    pthread_mutex_t mutex;
    pthread_cond_t cond;
    int max_thread_num;
    pthread_t thread_id[DEFAULT_THREADNUM];
    QTASKLIST* qhead;
    QTASKLIST* qtail;
}TD;

TD td;
int eh;
struct epoll_event ev,evs[10];

typedef struct socket{
    int sfd;
    int cfd;
    struct sockaddr_in sin;
    struct sockaddr_in cin;
}SOCK;


/*function*/
int init_conf(SEVCF* cf,const char* cpath);

void parse_msg(int cfd);

int init_db(USERINFO* uinfo,USERINFO** uhead,const char* dbpath);

int init_thread_mutex(pthread_mutex_t *mutex);

int init_thread_cond(pthread_cond_t *cond);

int init_thread_pool(TD* td);

int init_epoll(int threadnum);
int add_epoll(int fd);
int del_epoll(int cfd);

int init_socket(SOCK* sock,const char* ip,int port,int connum);

void* thread_wakeup(void* argv);

#endif
