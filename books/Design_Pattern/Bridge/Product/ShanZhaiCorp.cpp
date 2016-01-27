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
#include "ShanZhaiCorp.h"

CShanZhaiCorp::CShanZhaiCorp(IProduct *pproduct)
:CNewCorp(pproduct){
    
}

CShanZhaiCorp::~CShanZhaiCorp(void){
    
}

void CShanZhaiCorp::MakeMoney(){
    this->CNewCorp::MakeMoney();
    cout<<"我赚钱呀..."<<endl;
}
