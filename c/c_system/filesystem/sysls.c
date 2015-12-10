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
    fprintf(stderr,"Usage: sysls\n");
    exit(2);
}

int filter(const struct dirent* d){
    if(strcmp(d->d_name,".")==0 || strcmp(d->d_name,"..")==0)
        return 0;
    return 1;
}


int main(int argc,char* argv[]){
    int ch;
    int ret;
    DIR *fd;
    struct dirent *d,**m;
    struct stat *finfo;
    int i,count;

    if(argc == 1){
        count = scandir("./",&m,filter,alphasort);
        for(i=0;i<count;i++){
            printf("%s\n",m[i]->d_name);
        }
    }

    while((ch=getopt(argc,argv,"hvl"))!=EOF){
        switch(ch){
            case 'h':
                usage();
                break;
            case 'v':
                break;
            case 'l':
                break;
            default:
                
                break;
        }
    }


}
