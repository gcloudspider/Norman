/*########################################################
##File Name: NokiaSimpleFactory.cpp
##Created Time:2016年01月11日 星期一 13时37分14秒
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

CNokiaSimpleFactory::CNokiaSimpleFactory(void){

}

CNokiaSimpleFactory::~CNokiaSimpleFactory(void){

}

CNokia * CNokiaSimpleFactory::CreateNokia(const std::string& model){
    if(model == "N96"){
        return new CN96();
    } else if(model == "N95"){
        return new CN95();
    } else if(model == "N85"){
        return new CN85();
    } else if(model == "N81"){
        return new CN81();
    } else {
        assert(false);
    }
    return NULL;
}

