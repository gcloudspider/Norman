/*########################################################
##File Name: n_template.cpp
##Created Time:2015年12月05日 星期六 10时04分16秒
##Author: Norman 
##Description: 模板改进
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
#include<map>
using namespace std;
/*别名*/
typedef std::map<std::string,int> map_int_t;    //相同效果
using map_int_t = std::map<std::string,int>;

//
template <typename T>
struct Food{
    typedef T type;
};

template <typename T>
class A{
    int c;
};


/////////////////////////////
template<int N>
struct Foo{
    int x;
};

int main(){
    //Foo<100>> 2> xx;        //与老标准不兼容
    Foo<(100>>2)> xx;
    /**/
    Food<A<int>>::type cc;      //C++98/03不被支持
    return 0;
}
