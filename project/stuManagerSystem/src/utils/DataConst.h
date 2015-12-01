/*########################################################
##File Name: DataConst.h
##Created Time:2015年11月27日 星期五 19时51分57秒
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

#ifndef _DATACONST_H
#define _DATACONST_H
/*Data Storage FileName*/
#define STU_FILE_STORAGE_NAME           "../db/student.txt"
#define TEA_FILE_STORAGE_NAME           "../db/teacher.txt"
#define ADMIN_FILE_STORAGE_NAME         "../db/admin.txt"

/*public*/
#define LOGINED_MODIFY_PASSWD           "修改密码"

#define MAIN_MENU_WELCOME_TITLE         "欢迎使用学生管理系统"

/*login info*/
#define LOGIN_SELECT_USER               "用户登录界面"
#define LOGIN_SELECT_STUDENT            "学生登录"
#define LOGIN_SELECT_TEACHER            "教师登录"
#define LOGIN_SELECT_ADMIN              "管理员登录"
#define SELECT_LOGIN_USER               "请选择登录的用户:"
#define LOGOUT                          "退出"

/*logging*/
#define PLEASE_INPUT_STUDENT_ID         "请输入学生学号:"
#define PLEASE_INPUT_TEACHER_ID         "请输入教师工号:"
#define PLEASE_INPUT_ADMIN_ID           "请输入管理员工号:"

#define PLEASE_INPUT_STUDENT_PASSWD     "请输入学生密码:"
#define PLEASE_INPUT_TEACHER_PASSWD     "请输入教师密码:"
#define PLEASE_INPUT_ADMIN_PASSWD       "请输入管理员密码:"
/*login error*/
#define AUTH_USERID_FAILED_INFO         "输入用户ID不存在,3秒后重新输入!"
#define AUTH_PASSWD_FAILED_INFO         "输入用户或密码错误,3秒后重新输入!"
#define LOGIN_SUCCESS_INFO              "登录成功!"

#define SELECT_MENU_ELEMENT             "功能选择:"
/*stu logined*/
#define SHOW_STUDENT_INFOMATION         "显示个人信息"
#define MODIFY_STUDENT_INFOMATION       "修改个人密码"
#define QUERY_STUDENT_SCORE             "查询各科成绩"
#define RETURN_PARENT_FOLDER            "返回上级目录"

/*teacher logined*/
#define SHOW_TEACHER_INFOMATION         "显示教师信息"
#define MODIFY_STUDENT_SCORE            "修改学生学分"

#define SEARCH_STUDENT_NUM              "按学号查找"
#define SEARCH_STUDENT_NAME             "按姓名查找"
#define SEARCH_STUDENT_CLASSID          "按班级查找"
#define SEARCH_STUDENT_SCORE            "按成绩查找"

/*admin logined*/
#define ADD_USER_INFOMATION             "新增用户信息"
#define ADD_STUDENT_INFOMATION          "添加学生信息"
#define ADD_TEACHER_INFOMATION          "添加教师信息"

#define MODIFY_USER_INFOMATION          "修改用户信息"
#define MODIFY_STUEDENT_INFOMATION      "修改学生信息"
#define MODIFY_TEACHER_INFOMATION       "修改教师信息"

#define DEL_USER_INFOMATION             "删除用户信息"
#define DEL_STUDENT_INFOMATION          "删除学生信息"
#define DEL_TEACHER_INFOMATION          "删除教师信息"

#define SEARCH_USER_INFOMATION          "搜索用户信息"
#define SEARCH_STUDENT_INFOMATION       "搜索学生信息"
#define SEARCH_TEACHER_INFOMATION       "搜索教师信息"

#define SEARCH_TEACHER_ID               "按工号搜索"
#define SEARCH_TEACHER_NAME             "按教师姓名搜索"
#define SEARCH_TEACHER_CLASSID          "按教师教授班级ID搜索"
#define SEARCH_TEACHER_LESSION          "按教师教授课目搜索"

#endif
