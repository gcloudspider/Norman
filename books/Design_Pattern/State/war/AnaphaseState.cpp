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
#include "AnaphaseState.h"
#include "EndState.h"
void AnaphaseState::Anaphase(War *war){
    if(war->GetDays()< 30)
        cout<<"第"<<war->GetDays()<<"天:战争后期,双方拼死一搏"<<endl;
    else{
        war->SetState(new EndState());
        war->GetState();
    }
}

void AnaphaseState::CurrentState(War *war){
    Anaphase(war);
}
