/*########################################################
##File Name: LuSteamedFish.h
##Created Time:2016年01月12日 星期二 16时53分07秒
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

#ifndef _LUSTEAMEDFISH_H
#define _LUSTEAMEDFISH_H
#include "SteamedFish.h"
class CLuSteamedFish:public CSteamedFish{
public:
    CLuSteamedFish(void);
    ~CLuSteamedFish(void);

    virtual void Delicious();
};
#endif
