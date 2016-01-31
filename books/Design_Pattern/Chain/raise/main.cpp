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
#include "GeneralManager.h"
#include "Manager.h"
#include "Majordomo.h"
#include "CommonManager.h"

int main(){
    Manager *general = new GeneralManager(NULL,"A");
    Manager *majordomo = new Majordomo(general,"B");
    Manager *common = new CommonManager(majordomo,"C");
    common->DealWithRequest("D",300);
    common->DealWithRequest("E",600);
    common->DealWithRequest("F",1000);

    delete common;
    delete majordomo;
    delete general;
    return 0;
}
