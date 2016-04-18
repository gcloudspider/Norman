/**
* Create Date:Fri 15 Apr 2016 06:25:17 PM CST
* -------------------------------
* Copyright (C) 2016-2016 by NiaoYun (@) 
* Report bugs and download new versions at https//niaoyun.com
* 
* This library is distributed under the MIT License. See notice at the end of this file.
* This work is based on POSIX，which is:
* Copyright (C) 2016,by NiaoYun
*/

#include<iostream>
using namespace std;
#include<boost/regex.hpp>

int main() {
    std::string str = "192.168.1.1";
    boost::regex expression("([0-9]+).([0-9]+).([0-9]+)");
    boost::smatch what;

    if(boost::regex_search(str,what,expression)) {
        std::cout << what.size() << std::endl;

        for(size_t i = 0; i< what.size();i++) {
            if(what[i].matched) {
                std::cout<< what[i] << std::endl;
            }
        }
    }
    return 0;
}
