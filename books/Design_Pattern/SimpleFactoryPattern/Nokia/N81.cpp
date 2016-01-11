/*########################################################
##File Name: N81.cpp
##Created Time:2016年01月11日 星期一 15时33分54秒
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
#include "N81.h"
#include<iostream>
using namespace std;

CN81::CN81(void){
    std::cout<<"生产一部N81"<<std::endl;
}

CN81::~CN81(void){

}

bool CN81::MakeCall(const std::string& number) const{
    cout<<"我在用N81，拔打号码是:"<<number.c_str()<<endl;
    return false;
}
