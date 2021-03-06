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

int didi_create_regmsg(cJSON* root,didi_packmsg_t pg){
    const char* const head = "head";
    const char* const body = "body";
    cJSON *js_head;
    cJSON *js_body;
    
    root = cJSON_CreateObject();
    if(!root){
        zlog_error(c,"get root failed!");
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

int didi_create_respone(cJSON** root,didi_repack_t *pg){
    const char* const head = "head";
    const char* const body = "body";
    cJSON* js_head;
    cJSON* js_body;

    *root = cJSON_CreateObject();
    if(!*root){
        zlog_error(c,"get root failed!");
        return -1;
    }

    cJSON_AddItemToObject(*root,head,js_head=cJSON_CreateObject());
    cJSON_AddNumberToObject(js_head,"packtype",pg->packtype);
    cJSON_AddNumberToObject(js_head,"event",pg->event);
    cJSON_AddStringToObject(js_head,"version",pg->version);
    cJSON_AddStringToObject(js_head,"reqId",pg->reqId);
    
    cJSON_AddItemToObject(*root,body,js_body=cJSON_CreateObject());
    cJSON_AddNumberToObject(js_body,"recode",pg->repackbody.reg_spond.recode);
    cJSON_AddStringToObject(js_body,"remsg",pg->repackbody.reg_spond.remsg);
    cJSON_AddStringToObject(js_body,"telphone",pg->repackbody.reg_spond.telphone);
}


int didi_create_ordspond(cJSON** root,didi_repack_t *pg){
    const char* const head = "head";
    const char* const body = "body";
    cJSON* js_head;
    cJSON* js_body;

    *root = cJSON_CreateObject();
    if(!*root){
        zlog_error(c,"get root failed!");
        return -1;
    }

    cJSON_AddItemToObject(*root,head,js_head=cJSON_CreateObject());
    cJSON_AddNumberToObject(js_head,"packtype",pg->packtype);
    cJSON_AddNumberToObject(js_head,"event",pg->event);
    cJSON_AddStringToObject(js_head,"version",pg->version);
    cJSON_AddStringToObject(js_head,"reqId",pg->reqId);
    
    cJSON_AddItemToObject(*root,body,js_body=cJSON_CreateObject());
    cJSON_AddNumberToObject(js_body,"recode",pg->repackbody.ord_spond.recode);
    cJSON_AddNumberToObject(js_body,"orderid",pg->repackbody.ord_spond.orderid);
    cJSON_AddStringToObject(js_body,"remsg",pg->repackbody.ord_spond.remsg);
    cJSON_AddStringToObject(js_body,"telphone",pg->repackbody.ord_spond.telphone);
    cJSON_AddStringToObject(js_body,"starting",pg->repackbody.ord_spond.starting);
    cJSON_AddStringToObject(js_body,"destination",pg->repackbody.ord_spond.destination);
}

int didi_create_takespond(cJSON** root,didi_repack_t *pg){
    const char* const head = "head";
    const char* const body = "body";
    cJSON* js_head;
    cJSON* js_body;

    *root = cJSON_CreateObject();
    if(!*root){
        zlog_error(c,"get root failed!");
        return -1;
    }

    cJSON_AddItemToObject(*root,head,js_head=cJSON_CreateObject());
    cJSON_AddNumberToObject(js_head,"packtype",pg->packtype);
    cJSON_AddNumberToObject(js_head,"event",pg->event);
    cJSON_AddStringToObject(js_head,"version",pg->version);
    cJSON_AddStringToObject(js_head,"reqId",pg->reqId);
    
    cJSON_AddItemToObject(*root,body,js_body=cJSON_CreateObject());
    cJSON_AddNumberToObject(js_body,"recode",pg->repackbody.ord_spond.recode);
    cJSON_AddNumberToObject(js_body,"orderid",pg->repackbody.ord_spond.orderid);
    cJSON_AddStringToObject(js_body,"remsg",pg->repackbody.ord_spond.remsg);
    cJSON_AddStringToObject(js_body,"telphone",pg->repackbody.ord_spond.telphone);
}

int didi_create_drispond(cJSON** root,didi_repack_t *pg){
    const char* const head = "head";
    const char* const body = "body";
    cJSON* js_head;
    cJSON* js_body;

    *root = cJSON_CreateObject();
    if(!*root){
        zlog_error(c,"get root failed!");
        return -1;
    }

    cJSON_AddItemToObject(*root,head,js_head=cJSON_CreateObject());
    cJSON_AddNumberToObject(js_head,"packtype",pg->packtype);
    cJSON_AddNumberToObject(js_head,"event",pg->event);
    cJSON_AddStringToObject(js_head,"version",pg->version);
    cJSON_AddStringToObject(js_head,"reqId",pg->reqId);
    
    cJSON_AddItemToObject(*root,body,js_body=cJSON_CreateObject());
    cJSON_AddNumberToObject(js_body,"recode",pg->repackbody.dri_spond.recode);
    cJSON_AddNumberToObject(js_body,"driverid",pg->repackbody.dri_spond.driverid);
    cJSON_AddStringToObject(js_body,"remsg",pg->repackbody.dri_spond.remsg);
    cJSON_AddStringToObject(js_body,"driverphone",pg->repackbody.dri_spond.driverphone);
    cJSON_AddStringToObject(js_body,"drivername",pg->repackbody.dri_spond.drivername);
    cJSON_AddStringToObject(js_body,"drivercarnum",pg->repackbody.dri_spond.drivercarnum);

}

int didi_create_noordhistory(cJSON** root,didi_repack_t *pg){
    const char* const head = "head";
    const char* const body = "body";
    cJSON* js_head;
    cJSON* js_body;

    *root = cJSON_CreateObject();
    if(!*root){
        zlog_error(c,"get root failed!");
        return -1;
    }

    cJSON_AddItemToObject(*root,head,js_head=cJSON_CreateObject());
    cJSON_AddNumberToObject(js_head,"packtype",pg->packtype);
    cJSON_AddNumberToObject(js_head,"event",pg->event);
    cJSON_AddStringToObject(js_head,"version",pg->version);
    cJSON_AddStringToObject(js_head,"reqId",pg->reqId);
    
    cJSON_AddItemToObject(*root,body,js_body=cJSON_CreateObject());
    cJSON_AddNumberToObject(js_body,"recode",pg->repackbody.ordhistory.recode);
    cJSON_AddStringToObject(js_body,"remsg",pg->repackbody.ordhistory.remsg);

}

int didi_create_uordhistory(cJSON** root,didi_repack_t *pg){
    const char* const head = "head";
    const char* const body = "body";
    cJSON* js_head;
    cJSON* js_body;

    *root = cJSON_CreateObject();
    if(!*root){
        zlog_error(c,"get root failed!");
        return -1;
    }

    cJSON_AddItemToObject(*root,head,js_head=cJSON_CreateObject());
    cJSON_AddNumberToObject(js_head,"packtype",pg->packtype);
    cJSON_AddNumberToObject(js_head,"event",pg->event);
    cJSON_AddStringToObject(js_head,"version",pg->version);
    cJSON_AddStringToObject(js_head,"reqId",pg->reqId);
    
    cJSON_AddItemToObject(*root,body,js_body=cJSON_CreateObject());
    cJSON_AddNumberToObject(js_body,"recode",pg->repackbody.ordhistory.recode);
    cJSON_AddStringToObject(js_body,"remsg",pg->repackbody.ordhistory.remsg);
    cJSON_AddNumberToObject(js_body,"orderid",pg->repackbody.ordhistory.orderid);
    cJSON_AddStringToObject(js_body,"starting",pg->repackbody.ordhistory.starting);
    cJSON_AddStringToObject(js_body,"destination",pg->repackbody.ordhistory.destination);
    cJSON_AddStringToObject(js_body,"driverphone",pg->repackbody.ordhistory.driverphone);
    cJSON_AddStringToObject(js_body,"payment",pg->repackbody.ordhistory.payment);
    cJSON_AddStringToObject(js_body,"starttime",pg->repackbody.ordhistory.starttime);
    cJSON_AddStringToObject(js_body,"arrivaltime",pg->repackbody.ordhistory.arrivaltime);

}

int didi_create_dordhistory(cJSON** root,didi_repack_t *pg){
    const char* const head = "head";
    const char* const body = "body";
    cJSON* js_head;
    cJSON* js_body;

    *root = cJSON_CreateObject();
    if(!*root){
        zlog_error(c,"get root failed!");
        return -1;
    }

    cJSON_AddItemToObject(*root,head,js_head=cJSON_CreateObject());
    cJSON_AddNumberToObject(js_head,"packtype",pg->packtype);
    cJSON_AddNumberToObject(js_head,"event",pg->event);
    cJSON_AddStringToObject(js_head,"version",pg->version);
    cJSON_AddStringToObject(js_head,"reqId",pg->reqId);
    
    cJSON_AddItemToObject(*root,body,js_body=cJSON_CreateObject());
    cJSON_AddNumberToObject(js_body,"recode",pg->repackbody.ordhistory.recode);
    cJSON_AddStringToObject(js_body,"remsg",pg->repackbody.ordhistory.remsg);
    cJSON_AddNumberToObject(js_body,"orderid",pg->repackbody.ordhistory.orderid);
    cJSON_AddStringToObject(js_body,"starting",pg->repackbody.ordhistory.starting);
    cJSON_AddStringToObject(js_body,"destination",pg->repackbody.ordhistory.destination);
    cJSON_AddStringToObject(js_body,"userphone",pg->repackbody.ordhistory.userphone);
    cJSON_AddStringToObject(js_body,"payment",pg->repackbody.ordhistory.payment);
    cJSON_AddStringToObject(js_body,"starttime",pg->repackbody.ordhistory.starttime);
    cJSON_AddStringToObject(js_body,"arrivaltime",pg->repackbody.ordhistory.arrivaltime);

}

//释放json对象
int didi_release_json(cJSON* root){
    if(!root){
        zlog_error(c,"get root failed!");
        return -1;
    }
    cJSON_Delete(root);
    return 0;
}
//json对象转换成字符串
char* didi_convert_json(cJSON* root){
    char *result;
    if(!root){
        zlog_error(c,"get root failed!");
        return NULL;
    }
    result = cJSON_Print(root);

    return result;
}

char* didi_ufconvert_json(cJSON* root){
    char *result;
    if(!root){
        printf("get root failed!\n");
        return NULL;
    }
    result= cJSON_PrintUnformatted(root); //没有格式
    //result = cJSON_Print(*root);
    return result;
}

//将字符串转换成json对象
void didi_convert_string(cJSON** root,char *string){
    //cJSON* root;
    *root = cJSON_Parse(string);

    if(!*root){
        zlog_error(c,"get root failed!");
       // return NULL;
    }
    //return root;
}

//获取json节点
cJSON* didi_getjson_node(cJSON* root,const char* node) {
    cJSON* js_node;
    js_node = cJSON_GetObjectItem(root,node);
    if(!js_node){
        zlog_error(c,"not found %s node!",node);
        return NULL;
    }
    return js_node;
}

//获取节点item数据
cJSON* didi_getitem_node(cJSON* node,const char* item){
    cJSON* nitem;
    nitem = cJSON_GetObjectItem(node,item);
    if(!nitem){
        zlog_error(c,"not found %s item",item);
        return NULL;
    }
    return nitem;
}
