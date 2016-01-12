/*########################################################
##File Name: main.cpp
##Created Time:2016年01月12日 星期二 09时02分23秒
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
#include"AFactoryMethod.h"
#include<iostream>
using namespace std;

int main(int argc,char* argv[]){
    CCoreAFactory* coreAfactory = new CAFactoryMethod();
    CSingleCore *singlecore = coreAfactory->CreateSingleCore();
    singlecore->Show();
    return 0;
}
