/*########################################################
##File Name: systemaccess.c
##Created Time:2015年12月08日 星期二 16时20分00秒
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
#include"head.h"
#include<unistd.h>
#define VERSION "1.0"

void usage(const char* name){
    fprintf(stderr,"Usage: %s <filename> [-f exist] [-r read] [-w write] [x execute]\n",name);
    exit(2);
}

int myaccess(const char* str,int mode){
    int ret;
    ret = access(str,mode);
    return ret;
}

int main(int argc,char *argv[]){
    int ch;
    int ret;

    while((ch=getopt(argc,argv,"fhrvwx"))!= EOF){
        switch(ch){
            case 'f':
                ret = myaccess(argv[1],F_OK);
                if(0==ret) {
                    printf("file exist\n");
                } else {
                    printf("file not exist\n");
                }
                break;
            case 'r':
                ret = myaccess(argv[1],R_OK);
                if(0==ret) {
                    printf("file readed\n");
                } else {
                    printf("file not readed\n");
                }
                break;
            case 'w':
                ret = myaccess(argv[1],W_OK);
                if(0==ret) {
                    printf("file write\n");
                } else {
                    printf("file not write\n");
                }
                break;
            case 'x':
                ret = myaccess(argv[1],X_OK);
                if(0==ret) {
                    printf("file execute\n");
                } else {
                    printf("file not execute\n");
                }
                break;
            case 'h':
                usage(argv[0]);
                break;
            case 'v':
                printf("%s VERSION:%s",argv[0],VERSION);
                exit(0);
                break;
            default:
                usage(argv[0]);
                break;
        }
    }

    if(argc <= 2){
        usage(argv[0]);
    }

    return 0;
}
