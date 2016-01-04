/*########################################################
##File Name: didi.c
##Created Time:2015年12月29日 星期二 20时49分25秒
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

void usage(const char* progname){
    fprintf(stderr,"Usage: %s [-d deamon] [-h help] [-v version]\n",progname);
    exit(2);
}

void version(const char* progname){
    fprintf(stderr,"%s Version:\n",progname);
    exit(2);
}

void app_daemon(int ischdir,int isclose){
    pid_t pid;
    pid = fork();
    if(pid != 0){
        exit(-1);
    }

    setsid();

    pid = fork();
    if(pid != 0){
        exit(-1);
    }

    if(ischdir == 0){
        chdir("/");
    }

    if(isclose == 0){
        close(0);
        close(1);
        close(2);
    }

    umask((mode_t)0);
}

void app_init(){
    didi_conf_t cf;
    zlog_category_t *c;
    MYSQL db;
    int ret;
    //初始化配置文件
    ret = didi_conf_init(&cf,DEFAULT_CFGPATH);
    if(-1 == ret){
        printf("didi conf init failed!\n");
        return ;
    }
    //初始化zlog日志系统
    ret = didi_log_init(&c,cf.log.logconf);
    if(-1 == ret){
        zlog_info(c,"didi init log model failed!\n");
        return ;
    }
    zlog_info(c,"didi init log model success!\n");
    
    //初始化数据库
    didi_db_init(&db,cf.didimysql,&c);

    //主服务
    didi_init_loop(cf.server,&c);

    didi_db_release(&db,&c);
    didi_log_release();

}

int main(int argc,char* argv[]){
    int ch;

    if(argc < 2){
        usage(argv[0]);
    }
    
    while((ch=getopt(argc,argv,"dhv"))!= EOF){
        switch(ch){
            case 'd':
		        //app_daemon(1,1);
                app_init();
                break;
            case 'h':
                usage(argv[0]);
                break;
            case 'v':
                version(argv[0]);
                break;
            default:
                break;
        }
    }
}
