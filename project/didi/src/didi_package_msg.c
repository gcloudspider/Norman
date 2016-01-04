/*########################################################
##File Name: didi_package_msg.c
##Created Time:2016年01月04日 星期一 17时47分05秒
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
#include "../include/didi.h"

int didi_create_regmsg(cJSON* root,didi_packmsg_t pg,zlog_category_t **c){
    const char* const head = "head";
    const char* const body = "body";
    cJSON *js_head;
    cJSON *js_body;
    
    root = cJSON_CreateObject();
    if(!root){
        zlog_error(*c,"get root failed!\n");
        return -1;
    }

    cJSON_AddItemToObject(root,head,js_head=cJSON_CreateObject());
    cJSON_AddNumberToObject(js_head,"packtype",pg.packtype);
    cJSON_AddNumberToObject(js_head,"event",pg.event);
    cJSON_AddStringToObject(js_head,"version",pg.version);
    cJSON_AddStringToObject(js_head,"reqId",pg.reqId);

    cJSON_AddItemToObject(root,body,js_body=cJSON_CreateObject());
    cJSON_AddStringToObject(js_body,"username",pg.packbody.signup.username);
    cJSON_AddStringToObject(js_body,"passwd",pg.packbody.signup.passwd);

    return 0;
}
//释放json对象
int didi_release_json(cJSON* root,zlog_category_t **c){
    if(!root){
        zlog_error(*c,"get root failed!\n");
        return -1;
    }
    cJSON_Delete(root);
    return 0;
}
//json对象转换成字符串
char* didi_convert_json(cJSON* root,zlog_category_t **c){
    char *result;
    if(!root){
        zlog_error(*c,"get root failed!\n");
        return NULL;
    }
    result = cJSON_Print(root);

    return result;
}

//将字符串转换成json对象
cJSON* didi_convert_string(char *string,zlog_category_t **c){
    cJSON* root;
    root = cJSON_Parse(string);

    if(!root){
        zlog_error(*c,"get root failed!\n");
        return NULL;
    }
    return root;
}

//获取json节点
cJSON* didi_getjson_node(cJSON* root,const char* node,zlog_category_t **c) {
    cJSON* js_node;
    js_node = cJSON_GetObjectItem(root,node);
    if(!js_node){
        zlog_error(*c,"not found %s node!\n",node);
        return NULL;
    }
    return js_node;
}

//获取节点item数据
cJSON* didi_getitem_node(cJSON* node,const char* item,zlog_category_t **c){
    cJSON* nitem;
    nitem = cJSON_GetObjectItem(node,item);
    if(!item){
        zlog_error(*c,"not found %s item\n",item);
        return NULL;
    }
    return nitem;
}
