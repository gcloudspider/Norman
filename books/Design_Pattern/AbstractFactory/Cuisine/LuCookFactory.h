/*########################################################
##File Name: LuCookFactory.h
##Created Time:2016年01月12日 星期二 14时46分07秒
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

#ifndef _LUCOOKFACTORY_H
#define _LUCOOKFACTORY_H
#include "CookFactory.h"

class CLuCookFactory:public CCookFactory {
public:
    CLuCookFactory(void);
    ~CLuCookFactory(void);

    virtual CBraisingFish* CookBraisingFish();
    virtual CSteamedFish* CookSteamedFish();
};
#endif
