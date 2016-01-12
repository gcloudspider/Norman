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
#include "CpuSimpleFactory.h"
#include<iostream>
using namespace std;

int main(int argc,char* argv[]){
   CSingleCore* core = NULL;
   
   core = CCpuSimpleFactory::CreateSingleCore(COREA);
   core->Show();
   core = NULL;
   return 0;
}
