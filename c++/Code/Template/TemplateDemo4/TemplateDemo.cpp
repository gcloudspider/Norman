/**
*  - version 1.0
* -------------------------------
* Copyright (C) 2016-2016 by Norman (none_lih@163.com) 
* Report bugs and download new versions at https//github.com/evely211
* 
* This library is distributed under the MIT License. See notice at the end of this file.
* This work is based on POSIX，which is:
* Copyright (C) 2016,by Norman
*/
#include <iostream>
//using namespace std;   //使用using namespace std 报错.原因std中含有max函数

template<typename T>
const T& max(const T& a,const T& b){
    return a>b?a:b;
}

int main(){
    std::cout<<max(2.1,2.2)<<std::endl;   //模板实参被隐式推演成double
    std::cout<<max<double>(2.1,2.2)<<std::endl;   //显式指定模板参数
    std::cout<<max<int>(2.1,2.2)<<std::endl;      //显式指定模板参数,强制转换为int
    return 0;
}
