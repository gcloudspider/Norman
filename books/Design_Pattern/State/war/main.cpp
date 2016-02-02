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
#include "ProphaseState.h"
#include "War.h"


int main(){
    War *war = new War(new ProphaseState());
    for(int i=1;i<40;i+=5){
        war->SetDays(i);
        war->GetState();
    }
    delete war;
    return 0;
}
