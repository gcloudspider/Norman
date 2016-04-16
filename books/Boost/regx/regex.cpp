/**
* Create Date:Sat 16 Apr 2016 09:38:29 AM CST
* -------------------------------
* Copyright (C) 2016-2016 by Norman (none_lih@163.com) 
* Report bugs and download new versions at https//github.com/evely211
* 
* This library is distributed under the MIT License. See notice at the end of this file.
* This work is based on POSIX，which is:
* Copyright (C) 2016,by Norman
*/

#include<iostream>
using namespace std;
#include<boost/regex.hpp>
#include<string>

int main() {
    string line;
    boost::regex pat( "^Subject: (Re: |Aw: )*(.*)" );

    while (cin) {
        getline(cin,line);
        boost::smatch matches;

        if(boost::regex_match(line,matches,pat))
            cout << matches[2] << endl;
    }
}
