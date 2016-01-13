/*########################################################
##File Name: ChuanCookFactory.h
##Created Time:2016年01月12日 星期二 15时43分28秒
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

#ifndef _CHUANCOOKFACTORY_H
#define _CHUANCOOKFACTORY_H
#include "CookFactory.h"
class CChuanCookFactory:public CCookFactory{
public:
    CChuanCookFactory(void);
    ~CChuanCookFactory(void);

    virtual CBraisingFish *CookBraisingFish();
    virtual CSteamedFish* CookSteamedFish();
};
#endif
