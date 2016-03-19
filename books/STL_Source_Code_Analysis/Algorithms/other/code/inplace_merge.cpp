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
#include <algorithm>
#include <vector>
/*
将两个已排序的序列[first,middle]和[middle，last]合并成单 一有序序列
//若原来是增序,现在也递增排序 若原来是递减排序,现在也是递 减排序
*/

int main() {
    int first[]  = {5,10,15,20,25};
    int second[]  = {50,40,30,20,10};
    vector<int> v(10);

    vector<int>::iterator it;

    sort(first,first+5);
    sort(second,second+5);

    it = copy(first,first+5,v.begin());
    	copy(second,second+5,it);

    inplace_merge(v.begin(),v.begin()+5,v.end());

    cout << "the resulting vector contains:";

    for(it = v.begin(); it!=v.end();++it)
    	cout << ' '<<*it;
    cout << endl;
    merge(first,first+5,second,second+5,v.begin());

    cout << "The resulting vector contains:";
    for(vector<int>::iterator it=v.begin(); it != v.end();++it)
    	cout << ' ' << *it;
    cout << endl;

    return 0;
}
