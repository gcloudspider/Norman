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
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;

struct Person{
    char username[10];
    int age;
};


namespace shenzhen{
    Person person;
}

namespace guangzhou{
    Person person;
}

namespace beijin{
    Person person;
}

void usage(){
    cout<<"name: <username> <age> <city>"<<endl;
    exit(1);
}

auto print_result(int num){
    switch(num){
        case 1:
            break;
        case 2:
            break;
    }
}

int main(int argc,char* argv[]){

    auto num =0;

    return 0;
}
