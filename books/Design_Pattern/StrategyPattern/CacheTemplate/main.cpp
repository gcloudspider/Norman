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
#include "Random_ReplaceAlgorithm.h"

//详见:Norman/C++/Code/Template/TemplateDemo1/README.md
#include "Cache.cpp"

int main(){
    Cache<Random_ReplaceAlgorithm> cache; //模板实参
    cache.Replace();
    return 0;
}
