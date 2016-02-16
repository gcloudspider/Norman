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
#include<stdio.h>
#include<iostream>
#include<iterator>
#include<algorithm>
using namespace std;

/*普通方法实现排列
template<class T>
void permutations(T list[],int k,int m){
    if(k==m){
        copy(list,list+m+1,ostream_iterator<T>(cout,""));
        cout<<endl;
    } else {
        for(int i=k;i<=m;i++){
            swap(list[k],list[i]);
            permutations(list,k+1,m);
            swap(list[k],list[i]);
        }   
    }
}
*/

//STL copy和next_permutation算法实现排列
template<class T>
void Permutations(T list[],int k,int m){
    do{
        //按字典顺序,产生下一个更大的排列
        copy(list,list+m+1,ostream_iterator<T>(cout,""));
        cout<<endl;
        //next_permutation(start,end,compare)
        //compare判断一个排列是否比另一个排列要小
    }while(next_permutation(list,list+m+1));
}

int main(){
    int a[]={2,3,5,1,7};
    double b[]={2.4,3.2,5.5,1.9,7.2};
    Permutations(a,0,4);
    Permutations(b,0,4);
}
