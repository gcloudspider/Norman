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

#ifndef _WAR_H_
#define _WAR_H_
#include "State.h"
class State;
class War{
private:
    State *m_state;
    int m_days;

public:
    War(State *state);
    ~War();
    int GetDays();
    void SetDays(int days);
    void SetState(State *state);
    void GetState();
};

#endif
