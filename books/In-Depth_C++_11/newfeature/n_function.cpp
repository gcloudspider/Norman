/*########################################################
##File Name: n_function.cpp
##Created Time:2015年12月06日 星期日 09时27分25秒
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

void func(){
    cout<< __FUNCTION__ << endl;
}

class Foo{
    public:
    static int foo_func(int a){
        cout<<__FUNCTION__<<"("<<a<<") ->: ";
        return a;
    }
};

class Bar{
    public:
    int operator()(int a){
        cout<<__FUNCTION__<<"(" <<a<<")->: ";
        return a;
    }
};

int main(){
    function<void(void)> fr1 = func;        //绑定普通函数
    fr1();

    function<int(int)> fr2 = Foo::foo_func;     //绑定一个类的静态成员函数
    cout<<fr2(123)<<endl;

    Bar bar;
    fr2 = bar;                              //绑定一个仿函数
    cout<<fr2(123) <<endl;
    
    return 0;
}
