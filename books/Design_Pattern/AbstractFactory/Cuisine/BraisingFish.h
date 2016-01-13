/*########################################################
##File Name: BraisingFish.h
##Created Time:2016年01月12日 星期二 14时27分03秒
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

#ifndef _BRAISINGFISH_H
#define _BRAISINGFISH_H
#include "FoodProduct.h"
/*红烧鱼类*/
class CBraisingFish:public CFoodProduct{
public:
    CBraisingFish(void);
public:
    virtual ~CBraisingFish(void);
public:
    virtual void Delicious();
};
#endif
