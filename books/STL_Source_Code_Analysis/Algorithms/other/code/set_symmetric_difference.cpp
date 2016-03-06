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
两个集合区间的对称差集,
求存在于[first1,last1)但不存在于[first2,last2]内所有元素以及出现在[first2,last2]但不出现在[first1,last1)
注意:输入区间必须是已排序
*/

int main() {
    int first[]  = {5,10,15,20,25};
    int second[]  = {50,40,30,20,10};
    vector<int> v(10);

    vector<int>::iterator it;

    sort(first,first+5);
    sort(second,second+5);

    it = set_symmetric_difference(first,first+5,second,second+5,v.begin());

    v.resize(it-v.begin());

    cout <<" the difference has " << (v.size()) << "elements:" << endl;


    for(it = v.begin(); it!=v.end();++it)
    	cout << ' '<<*it;
    cout << endl;

    return 0;
}
