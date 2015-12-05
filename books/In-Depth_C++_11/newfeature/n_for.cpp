/*########################################################
##File Name: n_for.cpp
##Created Time:2015年12月05日 星期六 14时36分27秒
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
#include<algorithm>
using namespace std;

void do_cout(int n) {
    cout<<n<<endl;
}

int main() {
    vector<int >arr;
    arr.push_back(1);   
    arr.push_back(2);   
    arr.push_back(3);   
    arr.push_back(4);
    
/*遍历vector*/
    for(auto it = arr.begin();it!= arr.end();++it){
        printf("%p\t%d\n",&(*it),*it);
    }
/*使用算法中for_each遍历*/
    for_each(arr.begin(),arr.end(),do_cout);
    printf("\n");

/*c++11新性for循环*/
    for(auto n:arr){
        cout<<n<<endl;
    }


    return 0;
}
