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
#include "Lift.h"

CLift::CLift(){
    this->m_state = 0;
}

CLift::~CLift(){

}

void CLift::SetState(int state){
    this->m_state = state;
}

void CLift::Open(){
    switch(this->m_state){
        case OPENING_STATE:
            break;
        case CLOSING_STATE:
            this->OpenWithoutLogic();
            this->SetState(OPENING_STATE);
            break;
        case RUNNING_STATE:
            break;
        case STOPPING_STATE:
            this->OpenWithoutLogic();
            this->SetState(OPENING_STATE);
            break;
    }
}

void CLift::Close(){
    switch(this->m_state){
        case OPENING_STATE:
            this->CloseWithoutLogic();
            this->SetState(CLOSING_STATE);
            break;
        case CLOSING_STATE:
            break;
        case RUNNING_STATE:
            break;
        case STOPPING_STATE:
            break;
    }
}

void CLift::Run(){
    switch(this->m_state){
        case OPENING_STATE:
            break;
        case CLOSING_STATE:
            this->RunWithoutLogic();
            this->SetState(RUNNING_STATE);
            break;
        case RUNNING_STATE:
            break;
        case STOPPING_STATE:
            this->RunWithoutLogic();
            this->SetState(RUNNING_STATE);
            break;
    }
}

void CLift::Stop(){
    switch(this->m_state){
        case OPENING_STATE:
            break;
        case CLOSING_STATE:
            this->StopWithoutLogic();
            this->SetState(CLOSING_STATE);
            break;
        case RUNNING_STATE:
            this->StopWithoutLogic();
            this->SetState(CLOSING_STATE);
            break;
        case STOPPING_STATE:
            break;
    }
}

void CLift::OpenWithoutLogic(){
    cout<<"电梯门开启...."<<endl;
}

void CLift::CloseWithoutLogic(){
    cout<<"电梯门关闭...."<<endl;
}

void CLift::RunWithoutLogic(){
    cout<<"电梯上下跑起来...."<<endl;
}

void CLift::StopWithoutLogic(){
    cout<<"电梯停止了...."<<endl;
}


