/*########################################################
##File Name: test_parse_json.c
##Created Time:2015年12月30日 星期三 21时28分30秒
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

int main(){

    char *s = "{\"name\":\"norman\",\"age\":10}";

    cJSON *root;
    root = cJSON_Parse(s);  //将字符串转换成json格式

    if(!root){
        printf("get root failed!\n");
        return -1;
    }
    cJSON* name = cJSON_GetObjectItem(root,"name");  //获取节点
    if(!name){
        printf("No name!\n");
        return -1;
    }

    printf("name type is %d\n",name->type);
    printf("name is %s\n",name->valuestring);

    cJSON* age = cJSON_GetObjectItem(root,"age"); 
    if(!age){
        printf("no age!\n");
        return -1;
    }
    printf("age type is %d\n",age->type);
    printf("age is %d\n",age->valueint);

    return 0;
}
