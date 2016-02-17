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
#include "arrayList.h"
#include "linearList.h"

int main(){
    linearList *x = (linearList) new arrayList<int>(100);
    arrayList<double> y (100);

    arrayList<char> z;

    arrayList<double> w(y);
}


