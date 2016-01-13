/*########################################################
##File Name: LuBraisingFish.h
##Created Time:2016年01月12日 星期二 14时38分30秒
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

#ifndef _LUBRAISINGFISH_H
#define _LUBRAISINGFISH_H
#include "BraisingFish.h"

class CLuBraisingFish:public CBraisingFish{
public:
    CLuBraisingFish(void);
    ~CLuBraisingFish(void);
    virtual void Delicious();
};
#endif
