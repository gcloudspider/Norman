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
#include "../src/pugixml/pugixml.hpp"
#include <iostream>
using namespace std;

int main(){
    pugi::xml_document doc;
    if(!doc.load_file("../conf/OpenHms_Server.xml")) return -1;
    pugi::xml_node tools = doc.child("root");

    for(pugi::xml_node tool = tools.first_child(); tool;tool=tool.next_sibling()){
        cout<<"root:";
        for(pugi::xml_attribute attr= tool.first_attribute();attr;attr=attr.next_attribute()){
            cout<<" "<<attr.name() <<"="<<attr.value();
        }
        cout<<endl;
    }
}


