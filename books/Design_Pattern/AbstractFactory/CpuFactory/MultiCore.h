/*########################################################
##File Name: MultiCore.h
##Created Time:2016年01月12日 星期二 13时00分28秒
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

#ifndef _MULTICORE_H
#define _MULTICORE_H
class CMultiCore{
public:
    CMultiCore();
public:
    virtual ~CMultiCore();
public:
    virtual void Show() = 0; //纯虚函数
};

#endif
