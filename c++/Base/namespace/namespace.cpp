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
using namespace std;
namespace Norman{
    auto num = 5;
}

namespace cell390{
    auto sum = 0;
    auto num = 1;
}

namespace evely211{
    auto sum = 0;
    auto num = 2;
}



int main(int argc,char* argv[]){
    auto num = 4;
    //cout << "local:"<<num<< endl;
    //cout << "Norman:"<<Norman::num<< endl;
    //cout << "global:"<<::num<< endl;

    using namespace evely211;
    //using evely211::sum;
    //using evely211::num;
    sum += num;
    cout << "Sum="<<sum<<endl;

    return 0;
}
