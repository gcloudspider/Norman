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
#include "MetaphaseState.h"
void ProphaseState::Prophase(War *war){
    if(war->GetDays() < 10){
        cout<<"第"<<war->GetDays()<<"天:战争初期,双方你来我往,互相试探对方"<<endl;
    }else{
        war->SetState(new MetaphaseState());
        war->GetState();
    }
}

void ProphaseState::CurrentState(War *war){
    Prophase(war);
}
