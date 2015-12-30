/*########################################################
##File Name: test_json2.c
##Created Time:2015年12月30日 星期三 20时59分05秒
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
#include"../include/cjson.h"

int create_js(){
    cJSON *root;
    
    //创建根对象
    root = cJSON_CreateObject();
    if(!root){
        printf("get root failed!\n");
        goto EXIT;
    }
    printf("get root successfuly!\n");
    cJSON *js_body;
    const char* const body = "body";
    //创建body对象
    cJSON_AddItemToObject(root,body,js_body=cJSON_CreateObject());
    cJSON_AddStringToObject(js_body,"name","norman");
    cJSON_AddNumberToObject(js_body,"value",600);
    //将json对象转换成普通字符串 cJSON_Print(root)
    //char *s = cJSON_PrintUnformatted(root); //没有格式
    char *s = cJSON_Print(root); //有格式 有\n \t等

    if(s){
        printf("create js string is %s\n",s);
        free(s);
    }

    cJSON_Delete(root); //用完记得内存回收


    return 0;
EXIT:
    return -1;
}


int main(int argc,char** argv){
    create_js();
    return 0;
}
