/*########################################################
##File Name: ReleaseAppModel.c
##Created Time:2015年11月30日 星期一 08时36分30秒
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
#include "../utils/global.h"
#include "../utils/DataStruct.h"
#include "ReleaseAppModel.h"
#include "../DataManage/FileManage.h"


void ReleaseAllModel() {
    size_t s_ret,t_ret,a_ret;

    STU* pstu = g_pstudent;
    TEA* ptea = g_pteacher;
    ADMIN* padmin = g_padmin;
    //printf("%p\n",pstu);
    //printf("%p\n",ptea);
    //printf("%p\n",padmin);

    //TODO:将链表内容回写文件
    s_ret = WriteDataToStudentFile(&pstu);
    if(s_ret == 0) {
        printf("write student file sucessful!\n");    
    } else {
        printf("write student file failed!\n");    
    }

    t_ret = WriteDataToTeacherFile(&ptea);
    if(t_ret == 0) {
        printf("write teacher file sucessful!\n");    
    } else {
        printf("write teacher file failed!\n");    
    }

    a_ret = WriteDataToAdminFile(&padmin);
    if(a_ret == 0) {
        printf("write admin file sucessful!\n");    
    } else {
        printf("write admin file failed!\n");    
    }


    //TODO:释放链表
    printf("release app finished !\n");
    return ;
}
