/*########################################################
##File Name: test_genreqId.c
##Created Time:2016年01月05日 星期二 09时51分51秒
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
#include<stdlib.h>
#include<stdio.h>
#include<time.h>
int main(){
    srand((int)time(0));   
    int num = rand()%100000;   
    printf("rand num:%6d\n", num);
  
    struct tm *p;
    time_t second;
    time(&second);
           
    p = localtime(&second);
             
    char buf[100] = {0};
 
    sprintf(buf, "%d%d%d%d%d%d-%06d", 1900+p->tm_year, 1+p->tm_mon, p->tm_mday,p->tm_hour, p->tm_min, p->tm_sec, num);
  
  printf("guid:%s\n", buf);
}
