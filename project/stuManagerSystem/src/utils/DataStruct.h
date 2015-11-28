/*########################################################
##File Name: DataStruct.h
##Created Time:2015年11月27日 星期五 19时37分30秒
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

#ifndef _DATASTRUCT_H
#define _DATASTRUCT_H

struct score {
    int math;
    int english;
    int c_lang;
    int java;
    int c_adv;
};

typedef struct student {
    int id;
    char name[64];
    int age;
    int sex;
    char telnum[11];
    char QQ[20];
    char passwd[32];
    int classid;
    struct score *lscore;
    struct student *pre;
    struct student *next;
}STU;

typedef struct teacher {
    int id;
    char name[64];
    int age;
    int sex;
    int class_no;
    int lession;
    char passwd[32];
    struct teacher *pre;
    struct teacher *next;
}TEA;

#endif
