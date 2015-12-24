/*########################################################
##File Name: IMServer.h
##Created Time:2015年12月24日 星期四 19时08分21秒
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

#ifndef _IMSERVER_H
#define _IMSERVER_H
/*
* include 
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/stat.h>
#include <getopt.h>
#include <sys/types.h>
#include <sys/syscall.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/ioctl.h>
#include <dirent.h>
#include <sys/time.h>
#include <sys/ipc.h>
#include <signal.h>
#include <sys/sem.h>
#include <sys/msg.h>
#include <sys/shm.h>
#include <pthread.h>
#include <semaphore.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/epoll.h>
/*
 *define
 */
#define DEFAULT_SERVER_PORT        8081
#define DEFAULT_SERVER_LISTEN      1024
#define DEFAULT_SERVER_IPADDR      "0.0.0.0"
#define DEFAULT_THREAD_POOLNUM     20
#define DEFAULT_EPOLL_POOLNUM      100
#define DEFAULT_EPOLL_WAITNUM      20
#define DEFAULT_EPOLL_WTIMEOUT     "-1"

/*
 * enum
 */

//消息类型
 
enum reqType{
    LOGINTYPE = 1,             //登录请求
    LOUGOUTTYPE = 2,           //退出请求
    REGISTERTYPE = 3           //注册请求
};

enum msgType{
    TEXTMSG = 1,               //纯文本消息
    IMAGEMSG = 2,              //图片消息
    FILEMSG = 3               //文件消息
};
/*
 *struct 
 */
typedef unsigned char u8;
typedef unsigned char u16;
typedef unsigned char u32;

//消息头信息
struct msgHead{
    
};

//消息主体信息
struct msgbody{
    
};

struct package{
    struct msgHead head;
    struct msgbody body;
};

//用户结构体
typedef struct imUser{
    int userid;
    char username[64];
    char passwd[128];
    int sex;
    int age;
}IMUSER;


//任务队列
typedef void*(*FUNC_POINT)(void* argv);
typedef struct tasklist{
    FUNC_POINT function;
    void* argv;
    struct tasklist *next;
}QTASKLIST;

/*
 *function
 * 
 */

//parse ini


//logger


//database




#endif
