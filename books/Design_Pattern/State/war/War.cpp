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

#include "War.h"

War::War(State *state)
    :m_state(state)
     ,m_days(0){
     
     
};

War::~War(){
    delete m_state;
}

int War::GetDays(){
    return m_days;
}

void War::SetDays(int days){
    m_days = days;
}

void War::SetState(State *state){
    delete m_state;
    m_state = state;
}

void War::GetState(){
    m_state->CurrentState(this);
}
