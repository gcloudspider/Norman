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

#include "MetaphaseState.h"
#include "AnaphaseState.h"
void MetaphaseState::Metaphase(War *war){
    if(war->GetDays() < 20)
        cout<<"第"<<war->GetDays()<<"天:战争中期,进入相持阶段,双发各有损耗"<<endl;
    else {
        war->SetState(new AnaphaseState());
        war->GetState();
    }
}

void MetaphaseState::CurrentState(War *war){
    Metaphase(war);
}
