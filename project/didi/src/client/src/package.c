/*########################################################
##File Name: package.c
##Created Time:2016年01月04日 星期一 16时44分34秒
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
#include "../include/user.h"
#include "../include/cjson.h"
int create_js(cJSON* root){

    root = cJSON_CreateObject();
    if(!root){
        printf("get root failed!\n");
        goto EXIT;
    }
    printf("get root successfuly!\n");
    
    cJSON *js_head;
    cJSON *js_body;
    const char* const head = "head";
    const char* const body = "body";
    
    cJSON_AddItemToObject(root,head,js_head=cJSON_CreateObject());
    cJSON_AddStringToObject(js_head,"packtype","request");
    cJSON_AddStringToObject(js_head,"event","register");

    cJSON_AddItemToObject(root,body,js_body=cJSON_CreateObject());
    cJSON_AddStringToObject(js_body,"username","norman");
    cJSON_AddStringToObject(js_body,"passwd","123456");

    char* s = cJSON_Print(root);

    if(s){
        printf("create js string is%s\n",s);
        free(s);
    }

    cJSON_Delete(root);

    return 0;
EXIT:
    return -1;

}
