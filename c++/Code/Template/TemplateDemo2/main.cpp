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
#include "TemplateDemo.cpp"
#include <cstdlib>
#include <string>

int main(){
    try{
        //定义整型20个元素 栈空间
        Stack<int,20> int20Stack;
        //定义整形 40个元素 栈空间
        Stack<int,40> int40Stack;
        //定义字符串形 40个元素栈空间
        Stack<std::string,40> stringStack;

        //压栈元素7
        int20Stack.push(7);
        //获取栈顶元素
        std::cout<<int20Stack.top()<<std::endl;
        //弹栈
        int20Stack.pop();

        //将hello 压栈
        stringStack.push("hello");
        std::cout<<stringStack.top()<<std::endl;
        stringStack.pop();
        stringStack.pop(); //第二次弹栈 由于栈之前已弹出,为空显示错误
        return 0;
    }catch(std::exception const& ex){
        std::cerr<<"Exception: "<<ex.what() <<std::endl;
        return EXIT_FAILURE;
    }

}
