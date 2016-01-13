/*########################################################
##File Name: LuCookFactory.cpp
##Created Time:2016年01月12日 星期二 14时47分54秒
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
#include "LuCookFactory.h"
#include "LuBraisingFish.h"
#include "LuSteamedFish.h"
#include<iostream>
using namespace std;

CLuCookFactory::CLuCookFactory(){

}

CLuCookFactory::~CLuCookFactory(){

}

CBraisingFish* CLuCookFactory::CookBraisingFish(){
    cout<<"The Lu BraisingFish is Cooked!"<<endl;
    return new CLuBraisingFish();
}

CSteamedFish* CLuCookFactory::CookSteamedFish(){
    cout<<"The Lu SteamedFish is Cooked!"<<endl;
    return new CLuSteamedFish();
}
