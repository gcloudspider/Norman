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
#include"NokiaSimpleFactory.h"
#include<iostream>
using namespace std;


/*客户端*/
int main(int argc,char* argv[]){
    CNokia *nokia = NULL;

    string modeName = "N96";
    nokia = CNokiaSimpleFactory::CreateNokia(modeName);
    nokia->MakeCall("123456789");
    nokia = NULL;
    return 0;
}
