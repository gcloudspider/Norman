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
#include<mysql/mysql.h>
#include"cjson.h"
#define gettid() syscall(__NR_gettid)

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

struct didi_server_s{
    const char *hostip;
    int  port;
    int  connect;
    int  threadnum;
};

struct didi_mysql_s{
    const char* hostname;
    const char* dbname;
    const char* username;
    const char* passwd;
};

struct didi_log_s{
    const char* logconf;
};

struct didi_conf_s{
    struct didi_server_s server;
    struct didi_mysql_s didimysql;
    struct didi_log_s log;
};

struct didi_user_s{
    int userid;
    char username[64];
    char nickname[64];
    char passwd[128];
    char telphone[12];
};

struct didi_driver_s{
    int driverid;
    char drivername[64];
    char driverpasswd[128];
    char drivertelphone[12];
    char drivercarnum[20];
};

typedef void*(*DIDI_FUNC_POINT)(void* argv,void* argv2);
struct didi_tasklist_s{
    DIDI_FUNC_POINT didi_func;
    void* argv;
    void* argv2;
    struct didi_tasklist_s *next;
};

struct didi_thread_s{
    int eh;
    struct epoll_event ev,evs[10];
    pthread_mutex_t mutex;
    pthread_cond_t cond;
    int max_thread_num;
    pthread_t pthread_id[DEFAULT_THREADNUM];
    struct didi_tasklist_s *qhead;
    struct didi_tasklist_s *qtail;
};

struct didi_socket_s{
    int sfd;
    struct sockaddr_in sin;
    struct sockaddr_in cin;
};

enum usertype{
    PERSONAL_USER = 1,
    DRIVERS_USERS = 2
};

enum packtype{
    PACKTYPE_REQUEST = 1,           //请求包
    PACKTYPE_RESPONE = 2            //响应包
};

enum event{
    EVENT_REGISTER = 1,             //注册事件
    EVENT_LOGIN = 2,                //登录事件
    EVENT_LOGOUT = 3,               //退出事件
    EVENT_QUERY = 4,                 //查询订单事件
    EVENT_MPASSWD = 5,
    EVENT_ORDER = 6,
    EVENT_TAKETOKEN = 7
};

struct signup{
    char username[64];
    char passwd[128];
};

struct signin{
    char username[64];
    char passwd[128];
};

struct signout{
    char username[64];
};

union packbody{
    struct signup signup;           //注册
    struct signin signin;           //登录
    struct signout  signout;        //登出 (退出)
};

struct didi_packmsg_s{
    int packtype;
    int event;
    char version[8];
    char reqId[37];
    union packbody packbody;
};
/////////////////////////////
enum responcode{
    REQUER_SUCCESS = 200,       //服务器已处理请求
    PASSWD_SUCCESS = 201,       //密码验证正确
    ORDER_SUCCESS = 202,
    TAKETOKEN_SUCCESS = 203,

    SERVER_REFUSE = 403,        //
    USER_NOTEXIST = 404,        //用户不存在
    USER_EXIST = 405,           //用户已存在
    PASSWD_ERROR = 406,         //用户密码错误
    ORDER_ERROR = 407,
    TAKETOKEN_ERROR = 408,
};
//响应数据结构
struct reg_spond{
    int recode;
    char remsg[256];
    char telphone[12];
};

struct ord_spond{
    int recode;
    int orderid;
    char remsg[256];
    char telphone[12];
    char starting[1024];
    char destination[1024];
};

struct dri_spond{
    char drivername[64];
    char driverphone[12];
    char drivercarnum[20];
};

union repackbody{
    struct reg_spond reg_spond;
    struct ord_spond ord_spond;
    struct dri_spond dri_spond;
};

struct didi_repack_s{
    int packtype;
    int event;
    char version[8];
    char reqId[37];
    union repackbody repackbody;
};

union online_user{
    struct didi_user_s user;
    struct didi_driver_s driver;
};

//链表
struct didi_online_s{
    int fd;
    union online_user online_user;
    char telphone[12];
    struct didi_online_s *pre;
    struct didi_online_s *next;
};

struct didi_order_s{
    int orderid;
    char starting[1024];
    char destination[1024];
    char userphone[12];
    char driverphone[12];
    char starttime[32];
    char arrivaltime[32];
    char payment[128];
    struct didi_order_s *pre;
    struct didi_order_s *next;
};

/* types */
typedef struct didi_server_s didi_server_t;
typedef struct didi_mysql_s didi_mysql_t;
typedef struct didi_log_s didi_log_t;
typedef struct didi_conf_s didi_conf_t;

typedef struct didi_user_s didi_user_t;
typedef struct didi_driver_s didi_driver_t;
typedef struct didi_tasklist_s didi_tasklist_t;
typedef struct didi_thread_s didi_thread_t;

typedef struct didi_socket_s didi_socket_t;
typedef struct didi_packmsg_s didi_packmsg_t;
typedef struct didi_repack_s didi_repack_t;

typedef struct didi_online_s didi_online_t;
typedef struct didi_order_s didi_order_t;
//Global Var 全局变量 
didi_thread_t didi_td;
zlog_category_t *c;
MYSQL db;
didi_online_t *didi_user_head,*didi_user_tail;
didi_online_t *didi_driver_head,*didi_driver_tail;
didi_order_t *didi_order_head,*didi_order_tail;
didi_order_t *didi_overorder_head,*didi_overorder_tail;


//////////////////////////////////////////////////////////////////////
//初始化
int didi_conf_init(didi_conf_t *cf,const char* cpath);
int didi_log_init(zlog_category_t **c,const char* logpath);
int didi_log_release();
int didi_db_init(MYSQL *db,didi_mysql_t didimysql);
int didi_db_release(MYSQL *db);
int didi_found_epoll(int eh,struct epoll_event evs[10]);
int didi_add_epoll(didi_thread_t* didi_td,int fd);
int didi_del_epoll(int fd);
int didi_init_epoll(didi_thread_t* didi_td,int threadnum);
int didi_init_socket(didi_socket_t *sock,const char* ip,int port,int connect);
int didi_release_socket(didi_socket_t *sock_t);
int didi_init_pool(didi_thread_t* didi_td);
int didi_init_cond(pthread_cond_t* cond);
int didi_init_mutex(pthread_mutex_t* mutex);
int didi_init_loop(didi_socket_t *sock_t,didi_server_t server);
int didi_run(didi_socket_t sock_t);

int didi_cache_init(MYSQL *db);
int didi_cache_release();
void didi_adduser_cache(int cfd,int usertype,const char* telphone);
int didi_del_cache(int usertype,const char* telphone);
didi_online_t* didi_find_linklist(didi_online_t *head,const char* telphone);
int didi_del_linklist(didi_online_t *pn,didi_online_t *head);
int didi_create_order(int orderid,int usertype,const char* userphone,const char* starting,const char* destination,const char* starttime);
int didi_add_queue(int orderid,const char* userphone,const char* starting,const char* destination,const char* starttime);
int didi_getorder_cache(int orderid);
int didi_separate_cache(const char* telphone,int orderid);
didi_order_t* find_ordernode_linklist(int orderid);
int didi_delnode_linklist(didi_order_t* pn);
int didi_addnode_overorder(didi_order_t* pn);
int didi_getcfd_cache(int orderid);
char* didi_userphone_linklist(int orderid);
didi_online_t* didi_getdrivephone_cache(const char* driverphone);
/////////////////////////////////////////////////////////////////////////
//json数据格式处理
void didi_parse_msg(int cfd);
int didi_create_remsg(cJSON* root,didi_packmsg_t pg);
int didi_create_respone(cJSON** root,didi_repack_t* pg);
int didi_create_ordspond(cJSON** root,didi_repack_t *pg);
int didi_create_takespond(cJSON** root,didi_repack_t *pg);
int didi_release_json(cJSON* root);
char* didi_convert_json(cJSON* root);
char* didi_ufconvert_json(cJSON* root);
void didi_conver_string(cJSON** root,char* string);
cJSON* didi_getjson_node(cJSON* root,const char* node);
cJSON* didi_getitem_node(cJSON* node,const char* item);
/////////////////////////////////////////////////////////////////////////
//添加任务
void* didi_thread_wakeup(void* argv);
void didi_add_task(DIDI_FUNC_POINT didi_func,void* argv,void* argv2);
////////////////////////////////////////////////////////////////////////
//事件
//
void* didi_event_register(void* argv,void* argv2);
void* didi_event_login(void* argv,void* argv2);
void* didi_event_logout(void* argv,void* argv2);
void* didi_event_query(void* argv,void* argv2);
void* didi_event_mpasswd(void* argv,void* argv2);
void* didi_event_order(void* argv,void* argv2);
void* didi_event_taketoken(void* argv,void* argv2);

///////////////////////////////////////////////////////////////////////
//数据库
int query_user_exist(MYSQL *db,const char* telphone,int usertype);
int didi_insert_user(MYSQL *db,didi_user_t user);
int didi_insert_driver(MYSQL *db,didi_driver_t driver);
int didi_query_passwd(MYSQL *db,const char* telphone,const char* passwd,int usertype);
int didi_update_passwd(MYSQL *db,int usertype,const char* telphone,const char* passwd);
char* didi_query_order(MYSQL *db,int usertype,const char* telphone);
void query_online_user();
void query_online_driver();
//////////////////////////////////////////////////////////////////////
//缓存区
int init_user_linklist();
int init_driver_linklist();

/////////////////////////////////////////////////////////////////////
//杂项方法
int didi_generate_userid();
char* create_respon_package(int status,didi_repack_t* res_pack,const char* telphone);
char* create_ordspond_package(int status,didi_repack_t* res_pack,const char* telphone,int orderid,const char* starting,const char* destination);
char* create_takespond_package(int status,didi_repack_t* res_pack,const char* telphone,int orderid);
void didi_order_broadcast(const char* res_package);
char* create_drispond_package(int status,didi_repack_t *res_pack,didi_online_t* pn);
#endif
