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
#include <cstdlib>
#include <string>
#include <regex>
using namespace std;

int main(){
    string email_address;
    string user_name, domain_name;

    regex pattern("([0-9A-Za-z\\-_\\.]+)@([0-9a-z]+\\.[a-z]{2,3}(\\.[a-z]{2})?)");

    while(cin >> email_address){
        if(regex_match(email_address,pattern)){
            cout << "您输入的电子邮件地址合法" << endl;
            user_name = regex_replace(email_address,pattern,string("$1"));
            domain_name = regex_replace(email_address,pattern,string("$2"));
            cout << "用户名：" << user_name << endl;
            cout << "域名：" << domain_name << endl;
            cout << endl;
        } else {
            cout << "您输入的电子邮件地址不合法" << endl << endl;
        }
    }
    return EXIT_SUCCESS;
}
