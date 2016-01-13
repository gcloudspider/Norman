/*########################################################
##File Name: FactoryA.cpp
##Created Time:2016年01月12日 星期二 13时13分27秒
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
#include "FactoryA.h"
#include<iostream>
using namespace std;

CFactoryA::CFactoryA(){

}

CFactoryA::~CFactoryA(){

}

CSingleCore* CFactoryA::CreateSingleCore(){
    return new CSingleCoreA();
}

CMultiCore* CFactoryA::CreateMultiCore(){
    return new CMultiCoreA();
}

