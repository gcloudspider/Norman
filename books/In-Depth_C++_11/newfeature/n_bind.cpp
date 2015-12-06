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

class A{
public:
    int i_ = 0;

    void output(int x,int y){
        cout<<x <<" "<<y<<endl;
    }
};

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

void output_1(int x,int y){
    cout<<x<<" "<<y<<endl;
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
///////////////////////////
    bind(output_1,1,2)();
    bind(output_1,placeholders::_1,2)(1);
    bind(output_1,2,placeholders::_1)(1);

    //bind(output_1,2,placeholders::_2)(1);   //调用时没有第二个参数
    bind(output_1,2,placeholders::_2)(1,2);

    bind(output_1,placeholders::_1,placeholders::_2)(1,2);
    bind(output_1,placeholders::_2,placeholders::_2)(1,2);
    bind(output_1,placeholders::_2,placeholders::_1)(1,2);
//////////////////////////
    A a;
    function<void(int,int)> fr = bind(&A::output,&a,placeholders::_1,placeholders::_2);
    fr(1,2);

    function<int&(void)> fr_i = bind(&A::i_,&a);
    fr_i() = 123;

    cout<<a.i_ <<endl;

    return 0;
}

