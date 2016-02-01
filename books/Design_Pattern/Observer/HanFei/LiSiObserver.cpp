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

#include "LiSiObserver.h"

CLiSiObserver::CLiSiObserver(void)
:IObserver("李斯"){

}

CLiSiObserver::~CLiSiObserver(void){

}

void CLiSiObserver::Update(string context){
    cout<<"李斯:观察到韩非子活动,开始向老板汇报了..."<<endl;
    this->ReportToQinShiHuang(context);
    cout<<"李斯:汇报完毕,秦老板高兴了,有赏..."<<endl;
}

string CLiSiObserver::GetName(){
    return m_name;
}

void CLiSiObserver::ReportToQinShiHuang(string report){
    cout<<"李斯:报告老板,韩非子那小子他准备谋反了--->"<<report.c_str()<<endl;
}
