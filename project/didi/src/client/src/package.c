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
#include "../include/user.h"

int didi_create_regmsg(cJSON** root,didi_packmsg_t pg){
    const char* const head = "head";
    const char* const body = "body";
    cJSON *js_head;
    cJSON *js_body;
    
    *root = cJSON_CreateObject();
    if(!*root){
        printf("get root failed!\n");
        return -1;
    }

    cJSON_AddItemToObject(*root,head,js_head=cJSON_CreateObject());
    cJSON_AddNumberToObject(js_head,"packtype",pg.packtype);
    cJSON_AddNumberToObject(js_head,"event",pg.event);
    cJSON_AddStringToObject(js_head,"version",pg.version);
    cJSON_AddStringToObject(js_head,"reqId",pg.reqId);

    cJSON_AddItemToObject(*root,body,js_body=cJSON_CreateObject());
    switch(pg.event){
        case EVENT_REGISTER:
            cJSON_AddNumberToObject(js_body,"usertype",pg.packbody.signup.usertype);
            cJSON_AddStringToObject(js_body,"telphone",pg.packbody.signup.telphone);
            cJSON_AddStringToObject(js_body,"nickname",pg.packbody.signup.nickname);
            cJSON_AddStringToObject(js_body,"username",pg.packbody.signup.username);
            cJSON_AddStringToObject(js_body,"passwd",pg.packbody.signup.passwd);
            break;
        case EVENT_LOGIN:
            cJSON_AddNumberToObject(js_body,"usertype",pg.packbody.signin.usertype);
            cJSON_AddStringToObject(js_body,"telphone",pg.packbody.signin.telphone);
            cJSON_AddStringToObject(js_body,"passwd",pg.packbody.signin.passwd);
            break;
        case EVENT_LOGOUT:
            cJSON_AddNumberToObject(js_body,"usertype",pg.packbody.signout.usertype);
            cJSON_AddStringToObject(js_body,"telphone",pg.packbody.signout.telphone);
            break;
        case EVENT_MPASSWD:
            cJSON_AddNumberToObject(js_body,"usertype",pg.packbody.mpasswd.usertype);
            cJSON_AddStringToObject(js_body,"telphone",pg.packbody.mpasswd.telphone);
            cJSON_AddStringToObject(js_body,"passwd",pg.packbody.mpasswd.newpasswd);
            break;
        default:
            break;
    }
    return 0;
}
//释放json对象
int didi_release_json(cJSON** root){
    if(!*root){
        printf("get root failed!\n");
        return -1;
    }
    cJSON_Delete(*root);
    return 0;
}
//json对象转换成字符串
char* didi_convert_json(cJSON** root){
    char *result;
    if(!*root){
        printf("get root failed!\n");
        return NULL;
    }
    result = cJSON_Print(*root);
    return result;
}
//无格式化转换
char* didi_ufconvert_json(cJSON** root){
    char *result;
    if(!*root){
        printf("get root failed!\n");
        return NULL;
    }
    result= cJSON_PrintUnformatted(*root); //没有格式
    //result = cJSON_Print(*root);
    return result;
}

//将字符串转换成json对象
cJSON* didi_convert_string(char *string){
    cJSON* root;
    root = cJSON_Parse(string);

    if(!root){
        printf("get root failed!\n");
        return NULL;
    }
    return root;
}

//获取json节点
cJSON* didi_getjson_node(cJSON** root,const char* node) {
    cJSON* js_node;
    js_node = cJSON_GetObjectItem(*root,node);
    if(!js_node){
        printf("not found %s node!\n",node);
        return NULL;
    }
    return js_node;
}

//获取节点item数据
cJSON* didi_getitem_node(cJSON** node,const char* item){
    cJSON* nitem;
    nitem = cJSON_GetObjectItem(*node,item);
    if(!item){
        printf("not found %s item\n",item);
        return NULL;
    }
    return nitem;
}
