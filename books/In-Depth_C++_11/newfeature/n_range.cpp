/*########################################################
##File Name: n_range.cpp
##Created Time:2015年12月05日 星期六 16时31分52秒
##Author: Norman 
##Description: 
##
##Issue: 
##
##Analyze: 
##
##Induction:
##
##Summary:
##
##########################################################*/

#include<iostream>
#include<vector>
using namespace std;

vector<int > arr = {1,2,3,4,5};

vector<int> & get_range() {
    cout<<"get_range ->: " <<endl;
    return arr;
}

int main() {
    vector<int> acc = {1,2,3,4,5};

    for(auto val: get_range()) {
        cout<< val << endl;
    }

    for(auto val:acc) {
        cout << val << endl;
        arr.push_back(0);
    }
    return 0;
}


