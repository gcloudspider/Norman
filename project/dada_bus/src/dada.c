/*########################################################
##File Name: dada.c
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
#include "../include/dada.h"

void usage(const char* progname){
    fprintf(stderr,"Usage: %s [-d deamon] [-h help] [-v version]\n",progname);
    exit(2);
}

void version(const char* progname){
    fprintf(stderr,"%s Version:\n",progname);
    exit(2);
}

void app_init(){
    CF cf;
    int ret;

    ret = dada_conf_init(&cf,DEFAULT_CFGPATH);
}

int main(int argc,char* argv[]){
    int ch;

    if(argc < 2){
        usage(argv[0]);
    }
    
    while((ch=getopt(argc,argv,"dhv"))!= EOF){
        switch(ch){
            case 'd':
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
