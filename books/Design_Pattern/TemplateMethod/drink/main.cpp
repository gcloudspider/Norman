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
#include <stdio.h>
#include <stdlib.h>
#include "Beverage.h"
#include "Tea.h"
#include "Coffee.h"

int main(){
    Beverage *pTea = new Tea;
    cout<<"============准备茶=========="<<endl;
    pTea->PrepareBeverage();

    Beverage *pCoffee = new Coffee;
    cout<<"============准备咖啡========"<<endl;
    pCoffee->PrepareBeverage();

    free(pTea);
    free(pCoffee);
}

