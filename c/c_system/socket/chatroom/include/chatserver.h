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
    char clientIp[255];
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

//全局变量
TD td;
int eh;
struct epoll_event ev,evs[10];
USERINFO *uhead;

typedef struct socket{
    int sfd;
 //   int cfd;
    struct sockaddr_in sin;
    struct sockaddr_in cin;
}SOCK;
//////////////////////////////////////////
//消息
typedef unsigned char u8;
typedef unsigned char u16;
typedef unsigned char u32;

enum MsgType{
    SIGNIN = 1,
    SIGNUP = 2,
    ONLINE = 3,
    LOGOUT = 4,
    SINGLE_SESSION = 5,
    GROUP_SESSION = 6,
    MULTI_SESSION = 7,
    BROAD_SESSION = 8
};

struct MsgHead{
    u8 type;
    u8 version;
    u16 length;
};

//严重Bug: 程序会Crash
//SOCKET编程中不能使用char *username 来发送或接收数据
//Issues: 何时需要序列化
struct signin {
    int  result;
    char resMsg[256];
    char username[64];  //error: char* username;
    char passwd[128];   //error: char* passwd
};

struct signup {
    int registed;
    char username[64];
    char passwd[128];
};

struct online {
    char username[64];
    char ipaddr[255];
};

struct logout {
    char username[64];
    int online;
};

struct Single_session {
    
};

struct Group_session {

};

struct Multi_session {

};

struct Broad_session {
    
};

union body{
    struct signin signin;   //登录
    struct signup signup;   //注册
    struct online online;   //在线用户
    struct logout logout;   //退出
    struct Single_session Single_session;   //单人会话
    struct Group_session Group_session;     //群组会话
    struct Multi_session Multi_session;     //多人会话
    struct Broad_session Broad_session;     //广播会话
};

struct package{
    struct MsgHead head;
    union body body;
};

/*function*/
int nv_init_conf(SEVCF* cf,const char* cpath);
void nv_parse_msg(int cfd);

int nv_init_db(USERINFO* uinfo,const char* dbpath);
int nv_auth_user();
int nv_print_all_user();
int nv_print_online_user();

int nv_init_thread_mutex(pthread_mutex_t *mutex);

int nv_init_thread_cond(pthread_cond_t *cond);

int nv_init_thread_pool(TD* td);
void nv_pool_add_task(FUNC_POINT function,void* argv);

int nv_init_epoll(int threadnum);
int nv_add_epoll(int fd);
int nv_del_epoll(int fd);
int nv_found_epoll();

int nv_init_socket(SOCK* sock,const char* ip,int port,int connum);

void* nv_thread_wakeup(void* argv);
void* nv_cond_login(void* argv);
void* nv_cond_logout(void* argv);
void* nv_cond_register(void* argv);
void* nv_cond_online_user(void* argv);
void* nv_cond_single_session(void* argv);
void* nv_cond_mutli_session(void* argv);
void* nv_cond_group_session(void* argv);
void* nv_cond_broad_session(void* argv);

#endif
