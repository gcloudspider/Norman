/*########################################################
##File Name: LoginController.c
##Created Time:2015年11月30日 星期一 14时06分15秒
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
#include "../utils/DataEnum.h"
#include "../Model/LoginModel.h"

size_t onLoginAuthUserId(int usertype,int userid) {
    size_t ret;

    switch(usertype) {
        case STUDENT:
            ret = onAuthenticationStudentUserId(userid);
            break;
        case TEACHER:
            ret = onAuthenticationTeacherUserId(userid);
            break;
        case ADMINISTRATOR:
            ret = onAuthenticationAdminUserId(userid);
            break;
        default:
            break;
    }
    return ret;
}

size_t onLoginAuthPasswd(int usertype,int userid,char *passwd) {
    size_t ret;

    switch(usertype) {
        case STUDENT:
            ret = onAuthenticationStudentPasswd(userid,passwd);
            break;
        case TEACHER:
            ret = onAuthenticationTeacherPasswd(userid,passwd);
            break;
        case ADMINISTRATOR:
            ret = onAuthenticationAdminPasswd(userid,passwd);
            break;
        default:
            break;
    }
    return ret;
}
