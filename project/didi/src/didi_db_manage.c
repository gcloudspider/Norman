/*########################################################
##File Name: didi_database_manage.c
##Created Time:2015年12月29日 星期二 20时53分42秒
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

int didi_db_init(MYSQL *db,didi_mysql_t didimysql){
    char *sql;
    int res;
    mysql_init(db);
    if(mysql_real_connect(db,didimysql.hostname,didimysql.username,didimysql.passwd,didimysql.dbname,0,NULL,0)){
        zlog_info(c,"didi connection db success!");
        mysql_query(db,"SET NAMES UTF8");
    } else {
        zlog_error(c,"didi connect db failed!");
        if(mysql_error(db)){
            zlog_error(c,"connect error %d:%s",mysql_errno(db),mysql_error(db));
            zlog_error(c,"error: main process exit!");
            exit(2);
        }
    }
}

int didi_db_release(MYSQL *db){
    mysql_close(db);
    zlog_info(c,"didi release db success!");
}

int query_user_exist(MYSQL *db,const char* telphone,int usertype){
    char sql[1024];
    MYSQL_FIELD *field;
    MYSQL_RES *ptr;
    MYSQL_ROW result;
    int ret,row,column;
    int i,j;
    if(usertype == PERSONAL_USER){
        sprintf(sql,"select telphone from didiuser where telphone=%s",telphone);
    } else if(usertype == DRIVERS_USERS){
        sprintf(sql,"select drivertelphone from dididriver where drivertelphone=%s",telphone);
    }
    zlog_info(c,"%s",sql);
    ret = mysql_query(db,sql);
    if(ret != 0){
        zlog_error(c,"query failed!,sql:%s",sql);
        zlog_error(c,"%s",mysql_error(db));
    } else {
        zlog_info(c,"query successful.");
        ptr = mysql_store_result(db);
        if(ptr != NULL){
            row = mysql_num_rows(ptr);
            column = mysql_num_fields(ptr);
            zlog_info(c,"row=%d column=%d",row,column);
            if(row == 0){
                return -1;
            }
            mysql_free_result(ptr);
        }
    }
    return 0;
}

int didi_query_passwd(MYSQL *db,const char* telphone,const char* passwd,int usertype){
    char sql[1024];
    MYSQL_FIELD *field;
    MYSQL_RES *ptr;
    MYSQL_ROW result;
    int ret,row,column;
    int i,j;
    if(usertype == PERSONAL_USER){
        sprintf(sql,"select passwd from didiuser where telphone=%s",telphone);
    } else if(usertype == DRIVERS_USERS){
        sprintf(sql,"select driverpasswd from dididriver where drivertelphone=%s",telphone);
    }
    zlog_info(c,"%s",sql);
    ret = mysql_query(db,sql);
    if(ret != 0){
        zlog_error(c,"query failed!,sql:%s",sql);
        zlog_error(c,"%s",mysql_error(db));
    } else {
        zlog_info(c,"query successful.");
        ptr = mysql_store_result(db);
        if(ptr != NULL){
            row = mysql_num_rows(ptr);
            column = mysql_num_fields(ptr);
            zlog_info(c,"row=%d column=%d",row,column);

            for(i=0;field=mysql_fetch_field(ptr);i++){
                zlog_info(c,"%s",field->name);
            }

            for(i=0;i<row;i++){
                result = mysql_fetch_row(ptr);
                for(j=0;j<column;j++){
                    zlog_info(c,"%s",result[j]);
                    if(strcmp(result[j],passwd)==0){
                        return 0;
                    }
                }
            }
            mysql_free_result(ptr);
        }
    }
    return -1;

}

int didi_update_passwd(MYSQL *db,int usertype,const char* telphone,const char* passwd){
    char sql[1024];
    MYSQL_FIELD *field;
    MYSQL_RES *ptr;
    MYSQL_ROW result;
    int ret,row,column;
    int i,j;
    if(usertype == PERSONAL_USER){
        sprintf(sql,"update didiuser set passwd='%s' where telphone='%s'",passwd,telphone);
    } else if(usertype == DRIVERS_USERS){
        sprintf(sql,"update dididriver set driverpasswd='%s' where drivertelphone='%s'",passwd,telphone);
    }
    zlog_info(c,"%s",sql);
    ret = mysql_query(db,sql);
    if(ret != 0){
        zlog_error(c,"query failed!,sql:%s",sql);
        zlog_error(c,"%s",mysql_error(db));
        return -1;
    }
    return 0;
}

int didi_insert_user(MYSQL* db,didi_user_t user){
    char sql[1024];
    int res;

    mysql_query(db,"SET NAMES UTF8");
    sprintf(sql,"INSERT INTO didiuser(userid,username,nickname,passwd,telphone)values(%d,'%s','%s','%s','%s')",user.userid,user.username,user.nickname,user.passwd,user.telphone);
    zlog_info(c,"%s",sql);
    res = mysql_query(db,sql);
    if(!res){
        zlog_info(c,"insert %lu rows",(unsigned long)mysql_affected_rows(db));
    } else {
        zlog_info(c,"insert error %d:%s",mysql_errno(db),mysql_error(db));
        return -1;
    }
    return 0;
}

int didi_insert_driveruser(MYSQL* db,didi_driver_t driver){
    char sql[1024];
    int res;

    mysql_query(db,"SET NAMES UTF8");
    sprintf(sql,"INSERT INTO dididriver(driverid,drivername,driverpasswd,drivertelphone,drivercarnum)values(%d,'%s','%s','%s','%s')",driver.driverid,driver.drivername,driver.driverpasswd,driver.drivertelphone,driver.drivercarnum);
    zlog_info(c,"%s",sql);
    res = mysql_query(db,sql);
    if(!res){
        zlog_info(c,"insert %lu rows",(unsigned long)mysql_affected_rows(db));
    } else {
        zlog_info(c,"insert error %d:%s",mysql_errno(db),mysql_error(db));
        return -1;
    }
    return 0;
}

int didi_query_order(MYSQL *db,int usertype,const char* telphone){
    char *buf;
    char sql[1024];
    MYSQL_FIELD *field;
    MYSQL_RES *ptr;
    MYSQL_ROW result;
    int ret,row,column;
    int i,j;

    switch(usertype){
        case PERSONAL_USER:
            sprintf(sql,"select * from didiorders where userphone=%s",telphone);
            break;
        case DRIVERS_USERS:
        sprintf(sql,"select * from didiorders where driverphone=%s",telphone);
            break;
        default:
            break;
    }
    zlog_info(c,"%s",sql);
    ret = mysql_query(db,sql);
    if(ret != 0){
        zlog_error(c,"query failed!,sql:%s",sql);
        zlog_error(c,"%s",mysql_error(db));
    } else {
        zlog_info(c,"query successful.");
        ptr = mysql_store_result(db);
        if(ptr != NULL){
            row = mysql_num_rows(ptr);
            column = mysql_num_fields(ptr);
            zlog_info(c,"row=%d column=%d",row,column);
            if(row == 0){
                return -1;
            }
            mysql_free_result(ptr);
        }
    }
    return 0;
}

void* query_field_fetch(MYSQL* db,const char* fieldname,const char* tablename,const char* telphone,int usertype){
    void* rret;
    char sql[1024];
    MYSQL_FIELD *field;
    MYSQL_RES *ptr;
    MYSQL_ROW result;
    int ret,row,column;
    int i,j;
    
    if(usertype == PERSONAL_USER){
    sprintf(sql,"select `%s` from %s where telphone='%s'",fieldname,tablename,telphone);
    } else if(usertype == DRIVERS_USERS){
    sprintf(sql,"select `%s` from %s where drivertelphone='%s'",fieldname,tablename,telphone);
    }
    zlog_info(c,"%s",sql);
    ret = mysql_query(db,sql);
    if(ret != 0){
        zlog_error(c,"query failed!,sql:%s",sql);
        zlog_error(c,"%s",mysql_error(db));
    } else {
        zlog_info(c,"query successful.");
        ptr = mysql_store_result(db);
        if(ptr != NULL){
            row = mysql_num_rows(ptr);
            column = mysql_num_fields(ptr);
            for(i=0;i<row;i++){
                result = mysql_fetch_row(ptr);
                for(j=0;j<column;j++){ 
                    rret = result[j];
                    zlog_info(c,"%s",result[j]);
                }
            }
            zlog_info(c,"query user info row=%d column=%d",row,column);
            mysql_free_result(ptr);
        }
    }
    return rret;
}

int query_user_info(MYSQL* db,union online_user* user,int usertype,const char* telphone){
    int id;
    if(usertype == PERSONAL_USER){
        id = atoi((char*)query_field_fetch(db,"userid","didiuser",telphone,PERSONAL_USER));
        user->comuser.userid = id;
        strcpy(user->comuser.username,(char*)query_field_fetch(db,"username","didiuser",telphone,PERSONAL_USER));
        strcpy(user->comuser.nickname,(char*)query_field_fetch(db,"nickname","didiuser",telphone,PERSONAL_USER));
        strcpy(user->comuser.telphone,telphone);
    } else if(usertype == DRIVERS_USERS){
        id = atoi((char*)query_field_fetch(db,"driverid","dididriver",telphone,DRIVERS_USERS));
        user->driver.driverid = id;
        strcpy(user->driver.drivername,(char*)query_field_fetch(db,"drivername","dididriver",telphone,DRIVERS_USERS));
        strcpy(user->driver.drivertelphone,telphone);
        strcpy(user->driver.drivercarnum,(char*)query_field_fetch(db,"drivercarnum","dididriver",telphone,DRIVERS_USERS));
    }
    return 0;
}

int didi_insert_historyorder(MYSQL*db,didi_order_t* pn){
    char sql[1024];
    int res;

    mysql_query(db,"SET NAMES UTF8");
    sprintf(sql,"INSERT INTO didiorders(`orderid`,`starting`,`destination`,`userphone`,`driverphone`,`starttime`,`arrivaltime`,`payment`)values(%d,'%s','%s','%s','%s','%s','%s','%s')",pn->orderid,pn->starting,pn->destination,pn->userphone,pn->driverphone,pn->starttime,pn->arrivaltime,pn->payment);
    zlog_info(c,"%s",sql);
    res = mysql_query(db,sql);
    if(!res){
        zlog_info(c,"insert %lu rows",(unsigned long)mysql_affected_rows(db));
    } else {
        zlog_info(c,"insert error %d:%s",mysql_errno(db),mysql_error(db));
        return -1;
    }
    return 0; 
}

void* didi_fetch_ordhistory(MYSQL* db,const char* fieldname,const char* telphone,int usertype){
    void* rret;
    char sql[1024];
    MYSQL_FIELD *field;
    MYSQL_RES *ptr;
    MYSQL_ROW result;
    int ret,row,column;
    int i,j;
    if(usertype == PERSONAL_USER){ 
    sprintf(sql,"select `%s` from didiorders where userphone='%s'",fieldname,telphone);
    } else if(usertype == DRIVERS_USERS){
    sprintf(sql,"select `%s` from didiorders where driverphone='%s'",fieldname,telphone);
    }
    zlog_info(c,"%s",sql);
    ret = mysql_query(db,sql);
    if(ret != 0){
        zlog_error(c,"query failed!,sql:%s",sql);
        zlog_error(c,"%s",mysql_error(db));
    } else {
        zlog_info(c,"query successful.");
        ptr = mysql_store_result(db);
        if(ptr != NULL){
            row = mysql_num_rows(ptr);
            column = mysql_num_fields(ptr);
            for(i=0;i<row;i++){
                result = mysql_fetch_row(ptr);
                for(j=0;j<column;j++){ 
                    rret = result[j];
                    zlog_info(c,"%s",result[j]);
                }
            }
            zlog_info(c,"query user info row=%d column=%d",row,column);
            mysql_free_result(ptr);
        }
    }
    return rret;
}
void query_online_user(){

}

void query_online_driver(){

}
