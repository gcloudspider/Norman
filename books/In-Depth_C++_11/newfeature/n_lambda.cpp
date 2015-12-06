/*########################################################
##File Name: n_lambda.cpp
##Created Time:2015年12月06日 星期日 11时41分20秒
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


int main(){
    vector<int> v= {1,2,3,4,5,6};
    int even_cout = 0;
    for_each(v.begin(),v.end(),[&even_cout](int val){
        if(!(val & 1)){
            ++even_cout;
        }
    });

    cout<<"the number of even is "<<even_cout<<endl;

    return 0;
}
