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
#include<iostream>
#include <vector>
/*
 *C++98中
 std::vector<int>& add_one(std::vector<int> &v){
    for(std::vector<int>::iterator it = v.begin();it != v.end();it++){
        *it += 1;
    }
    return v;
 }

 void multiply_by_two(std::vector<int> &v){
    for(std::vector<int>::iterator it=v.begin(); it!= v.end();it++){
    *it *= 2;
    }
 }
 * */

 /*
  *C++11
  std::vector<int>& add_one(std::vector<int> &v){
    for(auto& it:v){
        it += 1;
    }
    return v;
  }

  void multiply_by_two(std::vector<int> &v){
    for(auto& it: v){
        it *=2;
    }
  }
  * */

//C++14
auto& add_one(std::vector<int>& v){
    for(auto& it: v){
        it += 1;
    }
    return v;
}

void multiply_by_two(std::vector<int>& v){
    for(auto& it:v){
        it *= 2;
    }
}

void print_vec(const std::vector<int>& v){
    for(const auto& e: v){
        std::cout<<e<<std::endl;
    }
    std::cout<<std::endl;
}


int main(){
    std::vector<int> my_vector{-1,2,3,5};
    multiply_by_two(add_one(my_vector));
    print_vec(my_vector);
    return 0;
}
