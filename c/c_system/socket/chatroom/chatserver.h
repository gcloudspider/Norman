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

/*const*/
#define DEFAULT_SERVER      "127.0.0.1"
#define DEFAULT_PORT        8080
#define DEFAULT_CONNUM      100
#define DEFAULT_THREADNUM   100

#define DEFAULT_CFGPATH     "./chatroom.cfg"
/*struct*/

typedef struct server_cfg{
    char server_ip[128];
    int  server_port;
    int  server_connum;
    int  server_threadnum;
    char dbpath[64];
}SEV_CF;


/*function*/
int parser_cfg(SEV_CF* cf,const char* cpath);

#endif
