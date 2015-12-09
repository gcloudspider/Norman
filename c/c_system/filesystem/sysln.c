/*########################################################
##File Name: sysln.c
##Created Time:2015年12月09日 星期三 09时08分24秒
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
#include "head.h"

void usage(){
    fprintf(stderr,"Usage: sysln <hardlink> <filename> [-s softlink] [-u unlink] \n");
    exit(2);
}

int myhardlink(const char* dst,const char* src){
    int ret;
    ret = link(dst,src);
    return ret;
}

int mysoftlink(const char* dst,const char* src){
    symlink(dst,src);
}

int unmylink(const char* dst,const char* src){
    unlink(dst);
}

int readmyslink(const char* dst){
    char buf[1024] = {0};
    readlink(dst,buf,1024);
    printf("%s->%s\n",dst,buf);
}

int main(int argc,char* argv[]){
    int ch;
    int ret;

    while((ch=getopt(argc,argv,"hvsr"))!=EOF){
        switch(ch){
            case 'h':
                usage();
                break;
            case 'v':
                break;
            case 's':
                mysoftlink(argv[1],argv[2]);
                break;
            case 'r':
                readmyslink(argv[1]);
            case 'u':
                unmylink(argv[1]);
                break;
            default:
                usage();
                break;
        }
    }

    if(argc <2){
        usage();
    }

    ret = mylink(argv[1],argv[2]);
    if(-1==ret){
        printf("link %s to %s failed!\n",argv[2],argv[1]);
    } else {
        printf("remove %s to %s success!\n",argv[2],argv[1]);
    }
}
