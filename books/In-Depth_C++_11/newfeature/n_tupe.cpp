/*########################################################
##File Name: n_tupe.cpp
##Created Time:2015年12月06日 星期日 11时49分35秒
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

#include<iostream>
#include<tuple>
using namespace std;

int main(){
    tuple<int,string,float> t1(10,"Test",3.14);
    //作用相当于struct

    int n = 7;
    //tuple_cat 连接多个tuple
    auto t2 = tuple_cat(t1,make_pair("Foo","bar"),t1,tie(n)); //tie解包tuple
    n = 10;
    printf(t2);
}
