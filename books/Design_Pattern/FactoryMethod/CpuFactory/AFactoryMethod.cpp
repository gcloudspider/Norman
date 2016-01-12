/*########################################################
##File Name: AFactoryMethod.cpp
##Created Time:2016年01月12日 星期二 10时43分50秒
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
#include "AFactoryMethod.h"
#include<iostream>
using namespace std;

CAFactoryMethod::CAFactoryMethod(){

}

CAFactoryMethod::~CAFactoryMethod(){

}

CSingleCore* CAFactoryMethod::CreateSingleCore(){
    return new CSingleCoreA();
}

