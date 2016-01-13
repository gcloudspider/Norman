/*########################################################
##File Name: ChuanCookFactory.cpp
##Created Time:2016年01月12日 星期二 15时46分42秒
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
#include "ChuanCookFactory.h"
#include "ChuanBraisingFish.h"
#include "ChuanSteamedFish.h"
#include<iostream>
using namespace std;

CChuanCookFactory::CChuanCookFactory(){

}

CChuanCookFactory::~CChuanCookFactory(){

}

CBraisingFish* CChuanCookFactory::CookBraisingFish(){
    cout<<"The Chuan BraisingFish is Cooked!"<<endl;
    return new CChuanBraisingFish();
}

CSteamedFish* CChuanCookFactory::CookSteamedFish(){
    cout<<"The Chuan SteamedFish is Cooked!"<<endl;
    return new CChuanSteamedFish();
}
