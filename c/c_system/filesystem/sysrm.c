/*########################################################
##File Name: syschmod.c
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
    fprintf(stderr,"Usage: sysrm <filename>\n");
    exit(2);
}

int myremove(const char* str){
    int ret;
    ret = remove(str);
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

    if(argc <2){
        usage();
    }

    ret = myremove(argv[1]);
    if(-1==ret){
        printf("remove %s failed!\n",argv[1]);
    } else {
        printf("remove %s success!\n",argv[1]);
    }
}
