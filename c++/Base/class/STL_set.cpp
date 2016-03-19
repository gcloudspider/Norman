/**
* Create Date:2016年03月15日星期二 09:34:59
* -------------------------------
* Copyright (C) 2016-2016 by Norman (none_lih@163.com) 
* Report bugs and download new versions at https//github.com/evely211
* 
* This library is distributed under the MIT License. See notice at the end of this file.
* This work is based on POSIX，which is:
* Copyright (C) 2016,by Norman
*/

//1.自动排序
//2.相同元素忽略
//
//交集: set_intersection
//并集: set_union
//
#include<set>
#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    set<int> num;
    num.insert(4);
    num.insert(5);
    num.insert(6);
    num.insert(3);
    num.insert(7);

    num.erase(3);
    
    set<int>::iterator it = num.find(6);
    if(it != num.end()) {
        cout << "find=" <<*it << endl;
    }

    for(auto& m : num) {
        cout << m << " ";
    }
    cout << endl;

    set<int> sum{8,2,6,4};
    set<int> ret;
    set_intersection(num.begin(),num.end(),
                        sum.begin(),sum.end(),
                        inserter(ret,ret.end()));
    for(auto& r : ret){
        cout << r << " ";
    }
    cout << endl;


}
