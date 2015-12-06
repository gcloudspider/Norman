/*########################################################
##File Name: n_bind.cpp
##Created Time:2015年12月06日 星期日 10时35分32秒
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
#include<functional>
using namespace std;

void call_when_even(int x,const function<void(int)>& f) {
    if(!(x & 1)) {
        f(x);
    }
}

void output(int x){
    cout<<x<<" ";
}

void output_add_2(int x) {
    cout<<x+2<<" ";
}

int main(){
    {
        auto fr = bind(output,placeholders::_1);        //placeholders 是一个占位符.代表这个位置将在函数调用时被传入第一个参数代替
        for(int i=0;i<10;++i){
            call_when_even(i,fr);
        }
        cout<< endl;
    }
    {
        auto fr = bind(output_add_2,placeholders::_1);
        for(int i=0;i<10;++i){
            call_when_even(i,fr);
        }
        cout<<endl;
    }
    return 0;
}

