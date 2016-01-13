/*########################################################
##File Name: FactoryB.cpp
##Created Time:2016年01月12日 星期二 13时18分07秒
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
#include "FactoryB.h"
#include<iostream>
using namespace std;

CFactoryB::CFactoryB(){

}

CFactoryB::~CFactoryB(){

}

CSingleCore* CFactoryB::CreateSingleCore(){
    return new CSingleCoreB();
}

CMultiCore* CFactoryB::CreateMultiCore(){
    return new CMultiCoreB();
}

