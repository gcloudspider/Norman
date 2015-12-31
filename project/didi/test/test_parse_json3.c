/*########################################################
##File Name: test_parse_json3.c
##Created Time:2015年12月31日 星期四 08时24分39秒
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
    char *s = "{\"list\":[\"name1\",\"name2\"]}";
    cJSON *root = cJSON_Parse(s); //创建一个json对象
    if(!root){
        printf("get root failed!\n");
        return -1;
    }
    
    //获取对象中的一个item
    cJSON *js_list = cJSON_GetObjectItem(root,"list");
    if(!js_list){
        printf("no list!\n");
        return -1;
    }

    //获取数组大小
    int array_size = cJSON_GetArraySize(js_list);
    printf("array size is %d\n",array_size);
    int i = 0;
    cJSON *item;
    for(i=0;i<array_size;i++){
        //获取数组中元素
        item = cJSON_GetArrayItem(js_list,i);
        printf("item type is %d\n",item->type);
        printf("%s\n",item->valuestring);
    }

    if(root)
        cJSON_Delete(root);
    return 0;
}
