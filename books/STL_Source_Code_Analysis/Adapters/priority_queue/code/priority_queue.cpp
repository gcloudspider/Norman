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
#include <vector>
#include <queue>
#include <functional>

class mycomparison {
    bool reverse;
public:
    mycomparison(const bool& revparam=false) {
        reverse = revparam;
    }

    bool operator() (const int& lhs,const int&rhs) const {
        if(reverse) return (lhs>rhs);
        else return (lhs<rhs);
    }

};

int main() {
    int myints[] = {10,60,50,20};
    priority_queue<int> first;
    priority_queue<int> second (myints,myints+4);
    priority_queue<int,vector<int>,greater<int>> third(myints,myints+4);

    cout << "third=(";
    while ( !third.empty() ) {
        cout << third.top() << " ";
        third.pop();
    }

    cout << ")" << endl;

    typedef priority_queue<int,vector<int>,mycomparison> mypq_type;

    mypq_type fourth(myints,myints+4);
    mypq_type fifth(mycomparison(true));

    cout << "fourth = (";
    while ( !fourth.empty() ) {
        cout << fourth.top() << " ";
        fourth.pop();
    }
    cout << ")" << endl;
    cout << "fifth = (";
    while ( !fifth.empty() ) {
        cout << fifth.top() << " ";
        fifth.pop();
    }
    cout << ")" << endl;

    for(int i=0; i<5; i++) {
        fifth.push(i*10);
    }

    cout << "after push the elements,fifth size is: " << fifth.size() << endl;
    cout << "after push the elements,fifth = (";
    while ( !fifth.empty() ) {
        cout << fifth.top() << " ";
        fifth.pop();
    }
    cout << ")" << endl;

    return 0;
}
