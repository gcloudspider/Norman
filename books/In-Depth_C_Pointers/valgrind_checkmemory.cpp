/*########################################################
##File Name: valgrind_checkmemory.c
##Created Time:2015年12月22日 星期二 15时44分34秒
##Author: Norman 
##Description: 
##          避免内存泄漏总结
##              1.养成良好习惯,保证malloc/new 和free/delete匹配 
##              2.
##          
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
#define _CRTDBG_MAP_ALLOC

#include<stdio.h>
#include<stdlib.h>
//#include<crtdbg.h> //windows平台
#include<iostream>
using namespace std;

void GetMemory(char* p,int num){
    p = (char*) malloc(sizeof(char)*num);
}

int main(int argc,char **argv){
    char* str = NULL;
    GetMemory(str,100);
    cout<<"Memory leak test!"<<endl;
    
 //   _CrtDumpMemoryLeaks();
    return 0;
}
