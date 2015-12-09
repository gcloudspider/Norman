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
#include<stdlib.h>
#include<getopt.h>
#include<sys/types.h>
#include<sys/stat.h>

void usage(){
    fprintf(stderr,"Usage: syschmod <mode>[0-7] <filename>\n");
    exit(2);
}

int setchmod(mode_t mode,const char* str){
    int ret;
    ret = chmod(str,mode);
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

    if(argc == 1){
        usage();
    }

    if(argc >1 && argc <3){
        usage();
    }
    
    ret = setchmod(atoi(argv[1]),argv[2]);

    if(-1==ret){
        printf("error: chmod %s failed!\n",argv[2]);
    } else {
        printf("success: chmod %s success!\n",argv[2]);
    }

}
