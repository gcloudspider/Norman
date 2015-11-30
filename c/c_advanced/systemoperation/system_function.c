/*########################################################
##File Name: sys_fopen.c
##Created Time:2015年11月27日 星期五 10时27分17秒
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


int main() {
    FILE *fp;
    int ret;
    char buf[1024] = {0};

    fp = fopen("./a.txt","r+");

    if(fp == NULL) {
        printf("line %d\n",__LINE__);
        perror("while fopen():");
        return -1;
    }

    printf("open file successfully!\n");

    ret = fread(buf,1,1,fp);
    if(ret == 0) {
        perror("fread()");
    }

    printf("buf=\"%s\"\n",buf);
    
    fclose(fp);
    return 0;
}
