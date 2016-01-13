/*########################################################
##File Name: CoreFactory.h
##Created Time:2016年01月12日 星期二 13时08分55秒
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

#ifndef _COREFACTORY_H
#define _COREFACTORY_H
class CCoreFactory{
public:
    CCoreFactory();
public:
    virtual CCoreFactory();
public:
    virtual CSingleCore* CreateSingleCore() = 0;
    virtual CMultiCore* CreateMultiCore() = 0;
};
#endif
