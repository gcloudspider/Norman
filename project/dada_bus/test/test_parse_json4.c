/*########################################################
##File Name: test_parse_json4.c
##Created Time:2015年12月31日 星期四 08时33分09秒
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

int main(int argc,char** argv){
    char *s = "{\"list\":[{\"name\":\"norman\",\"age\":10},{\"name\":\"huahua\",\"age\":11}]}";

    cJSON* root = cJSON_Parse(s);
    if(!root){
        printf("get root failed!\n");
        return -1;
    }

    cJSON *js_list = cJSON_GetObjectItem(root,"list");
    if(!js_list){
        printf("no list!\n");
        return -1;
    }
    //1.获取数组大小
    int array_size = cJSON_GetArraySize(js_list);
    printf("array size is %d\n",array_size);
    int i = 0;
    
    cJSON *item,*it,*js_name,*js_age;
    char *p = NULL;

    //2.循环取得数组项
    for(i=0;i<array_size;i++){
        item = cJSON_GetArrayItem(js_list,i);
        if(!item){
            printf("get array item failed!\n");
        }
        //3.将数组项转换成json字符串
        p= cJSON_PrintUnformatted(item);
        //4.将json字符串转为一个json对象
        it = cJSON_Parse(p);
        if(!it)
            continue;
        //5.按从对象中取数组中每一个子项
        js_name = cJSON_GetObjectItem(it,"name");
        printf("name is %s\n",js_name->valuestring);
        js_age = cJSON_GetObjectItem(it,"age");
        printf("age is %d\n",js_age->valueint);
    }

    if(root)
        cJSON_Delete(root);

    return 0;
}
