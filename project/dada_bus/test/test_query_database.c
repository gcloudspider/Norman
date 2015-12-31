/*########################################################
##File Name: test_query_database.c
##Created Time:2015年12月31日 星期四 09时53分55秒
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
#include<string.h>
#include<stdlib.h>
#include<mysql/mysql.h>

#define SERVERADDR "localhost"
#define USERNAME    "dadabus"
#define PASSWD      "dada123456"
#define DBNAME      "dadabus"

int main(){
    char sql[1000];
    MYSQL db;
    MYSQL_RES *ptr;
    MYSQL_ROW result;
    int ret;
    mysql_init(&db);
    mysql_real_connect(&db,SERVERADDR,USERNAME,PASSWD,DBNAME,0,NULL,0);

    strcpy(sql,"select * from dadauser;");
    ret = mysql_query(&db,sql);
    MYSQL_FIELD *field;
    int row,column;
    int i,j;
    ptr = mysql_store_result(&db);
    row = mysql_num_rows(ptr);
    column = mysql_num_fields(ptr);

    printf("row=%d column=%d\n",row,column);
    for(i=0;field=mysql_fetch_field(ptr);i++){
        printf("%s\t",field->name);
    }
    printf("\n");

    for(i=0;i<row;i++){
        result = mysql_fetch_row(ptr);
        for(j=0;j<column;j++){
            printf("%s\t",result[j]);
        }
        printf("\n");
    }
    mysql_free_result(ptr);
    mysql_close(&db);

    return 0;

}
