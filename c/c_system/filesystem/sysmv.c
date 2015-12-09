/*########################################################
##File Name: sysmv.c
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
    fprintf(stderr,"Usage: sysmv <oldfilename> <newfilename>\n");
    exit(2);
}

int mymv(const char* str,const char* dst){
    int ret;
    ret = rename(str,dst);
    return ret;
}

int main(int argc,char* argv[]){
    int ch;
    int ret;

    while((ch=getopt(argc,argv,"hv"))!=EOF){
        switch(ch){
            case 'h':
                usage();
                break;
            case 'v':
                break;
            default:
                usage();
                break;
        }
    }

    if(argc <3){
        usage();
    }

    ret = mymv(argv[1],argv[2]);
    if(-1==ret){
        printf("rename %s to %s failed!\n",argv[1],argv[2]);
    } else {
        printf("rename %s to %s success!\n",argv[1],argv[2]);
    }
}
