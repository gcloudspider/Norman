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
    cJSON *root,*js_body;
    //创建一个数组对象
    root = cJSON_CreateArray();
    //在对象里添加一个字符串和一个数字
    cJSON_AddItemToArray(root,cJSON_CreateString("Hello world"));
    cJSON_AddItemToArray(root,cJSON_CreateNumber(10));

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
