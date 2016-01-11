/*########################################################
##File Name: main.cpp
##Created Time:2016年01月11日 星期一 13时19分22秒
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
#include"N96Factory.h"
#include<iostream>
using namespace std;


/*客户端*/
int main(int argc,char* argv[]){
    /*客户端通过建立N96工厂生产Nokia手机*/
    CFactoryMethod* factoryMethod = new CN96Factory();
    CNokia *nokia = factoryMethod->CreateNokiaMobile();
    nokia->MakeCall("1234567");
    return 0;
}
