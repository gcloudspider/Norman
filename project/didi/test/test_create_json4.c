/*########################################################
##File Name: test_json3.c
##Created Time:2015年12月30日 星期三 21时15分32秒
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
#include "../include/cjson.h"

int create_js(){
    cJSON *root,*js_body,*js_list;
    //对象里包括一个数组,数组包括对象
    root = cJSON_CreateObject();
    cJSON_AddItemToObject(root,"body",js_body=cJSON_CreateArray());
    cJSON_AddItemToArray(js_body,js_list=cJSON_CreateObject());
    //在对象里添加一个字符串和一个数字
    cJSON_AddStringToObject(js_list,"name","norman");
    cJSON_AddNumberToObject(js_list,"status",100);

    //char* s = cJSON_Print(root);
    char *s = cJSON_PrintUnformatted(root);

    if(s){
        printf("%s\n",s);
        free(s);
    }

    if(root){
        cJSON_Delete(root);
    }

EXIT:
    return -1;
}


int main(int argc, char** argv){

    create_js();

    return 0;
}
