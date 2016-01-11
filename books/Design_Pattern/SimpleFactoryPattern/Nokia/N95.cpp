/*########################################################
##File Name: N95.cpp
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
#include "N95.h"
#include<iostream>
using namespace std;

CN95::CN95(void){
    std::cout<<"生产一部N95"<<std::endl;
}

CN95::~CN95(void){

}

bool CN95::MakeCall(const std::string& number) const{
    cout<<"我在用N95，拔打号码是:"<<number.c_str()<<endl;
    return false;
}
