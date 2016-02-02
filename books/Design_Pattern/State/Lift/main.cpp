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
#include "ILift.h"
#include "Context.h"
#include "OpenningState.h"
#include "CloseingState.h"
#include "RunningState.h"
#include "StoppingState.h"
void DoIt(){
    ILift *pLift = new CLift();
    pLift->SetState(ILift::STOPPING_STATE);
    pLift->Open();
    pLift->Close();
    pLift->Run();
    pLift->Stop();
    delete pLift;
}

void DoNew(){
    CContext context;
    CCloseingState closeingState;
    context.SetLiftState(&closeingState);
    context.Close();
    context.Open();
    context.Run();
    context.Stop();
}

int main(){
    cout<<"-----使用模式之前-----"<<endl;
    DoIt();

    cout<<"------使用模式之后-----"<<endl;
    DoNew();
    return 0;
}
