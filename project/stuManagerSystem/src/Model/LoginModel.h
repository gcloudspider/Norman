/*########################################################
##File Name: LoginModel.h
##Created Time:2015年11月28日 星期六 09时55分05秒
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

#ifndef _LOGINMODEL_H
#define _LOGINMODEL_H

int onAuthenticationStudentUserId(int userid);
int onAuthenticationTeacherUserId(int userid);
int onAuthenticationAdminUserId(int userid);

int onAuthenticationStudentPasswd(int userid,char *passwd);
int onAuthenticationTeacherPasswd(int userid,char *passwd);
int onAuthenticationAdminPasswd(int userid,char *passwd);



#endif
