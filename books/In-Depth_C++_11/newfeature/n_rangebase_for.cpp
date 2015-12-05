/*########################################################
##File Name: n_rangebase_for.cpp
##Created Time:2015年12月05日 星期六 15时33分29秒
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
#include<map> 
#include<set>
using namespace std;

int main() { 
    map<string,int> mm={{"1",1},{"2",2},{"3",3}};
    set<int> ss = {1,2,3};  //set 特性:set内部元素是只读的

/*map关联性容器,需要使用val.first或val.second来提取键值*/
    for(auto& val :mm) {
        cout << val.first << "->"<< val.second << endl;
    }

    /*基于范围的for循环*/
    for(auto &val :mm) {
        cout<< val.first <<"->"<< val.second <<endl;
    }

    /*for循环中auto &会被推导为const int &*/
    
    for(auto &val :ss) {
        //cout<< val++ <<endl;    //error: val++ 只读
        cout<< val <<endl;
    }


    return 0;

}
