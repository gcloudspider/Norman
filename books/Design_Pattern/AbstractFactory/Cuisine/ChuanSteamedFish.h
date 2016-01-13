/*########################################################
##File Name: ChuanSteamedFish.h
##Created Time:2016年01月12日 星期二 16时44分47秒
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

#ifndef _CHUANSTEAMEDFISH_H
#define _CHUANSTEAMEDFISH_H
#include "SteamedFish.h"
class CChuanSteamedFish:public CSteamedFish{
public:
    CChuanSteamedFish(void);
    ~CChuanSteamedFish(void);

    virtual void Delicious();
};
#endif
