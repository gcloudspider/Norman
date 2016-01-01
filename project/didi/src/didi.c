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
    CF cf;
    int ret;

    ret = didi_conf_init(&cf,DEFAULT_CFGPATH);
    if(-1 == ret){
        printf("conf init failed!\n");
        return ;
    }

    printf("%s\n",cf.log.logconf);
    
    ret = didi_log_init(cf.log.logconf);

    while(1){
    
    }
    //ret = didi_database_init(cf.database);
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
