/*########################################################
##File Name: main.cpp
##Created Time:2016年01月12日 星期二 15时51分25秒
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

#include <stdlib.h>
#include <iostream>
#include "LuCookFactory.h"
#include "ChuanCookFactory.h"

using namespace std;

int main(int argc,char* argv[]){
    CCookFactory* cookFac = new CLuCookFactory();
    CBraisingFish* braFish = cookFac->CookBraisingFish();
    //braFish->Delicious();
    cout<<"***********************/n";
    delete braFish;

    CSteamedFish* steFish = cookFac->CookSteamedFish();
    //steFish->Delicious();
    cout<<"***********************/n";
    delete steFish;
    delete cookFac;

    cookFac = new CChuanCookFactory();

    braFish = cookFac->CookBraisingFish();
    //braFish->Delicious();
    cout<<"***********************/n";
    delete braFish;

    steFish = cookFac->CookSteamedFish();
    //steFish->Delicious();
    delete steFish;

    system("pause");

    return 0;
}
