/*########################################################
##File Name: CookFactory.h
##Created Time:2016年01月12日 星期二 14时43分16秒
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

#ifndef _COOKFACTORY_H
#define _COOKFACTORY_H
#include "BraisingFish.h"
#include "SteamedFish.h"
class CCookFactory{
public:
    CCookFactory(void);
    ~CCookFactory(void);

    virtual CBraisingFish *CookBraisingFish();
    virtual CSteamedFish* CookSteamedFish();
};
#endif
