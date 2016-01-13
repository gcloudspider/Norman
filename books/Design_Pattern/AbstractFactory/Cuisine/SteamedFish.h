/*########################################################
##File Name: SteamedFish.h
##Created Time:2016年01月12日 星期二 14时30分16秒
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

#ifndef _STEAMEDFISH_H
#define _STEAMEDFISH_H
#include "FoodProduct.h"
//清蒸鱼类
class CSteamedFish:public CFoodProduct{
public:
    CSteamedFish(void);
    ~CSteamedFish(void);
    virtual void Delicious();
};
#endif
