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

#include "CarModel.h"
#include "BenzModel.h"
#include "BMWModel.h"
#include "BenzBuilder.h"
#include "BMWBuilder.h"
#include "Director.h"
#include <iostream>
#include <vector>

void DoBenzRun(){
    cout<<"------生产奔驰模型-----"<<endl;
    CBenzModel *pBenz = new CBenzModel();
    vector<string> seq;
    seq.push_back("engine boom");
    seq.push_back("start");
    seq.push_back("stop");

    pBenz->SetSequence(&seq);
    pBenz->Run();
    delete pBenz;
}

void DoBuilder(){
    cout<<"------用同一个顺序,生成模型-----"<<endl;
    vector<string> seq;
    seq.push_back("engine boom");
    seq.push_back("start");
    seq.push_back("stop");

    CBenzBuilder benzBuilder;
    benzBuilder.SetSequence(&seq);
    CBenzModel *pBenz = dynamic_cast<CBenzModel*>(benzBuilder.GetCarModel());
    pBenz->Run();

    CBMWBuilder bmwBuilder;
    bmwBuilder.SetSequence(&seq);
    CBMWModel *pBenzmw = dynamic_cast<CBMWModel*>(bmwBuilder.GetCarModel());
    pBenz->Run();
}

void DoDirector(){
    cout<<"-----批量生成模型-----"<<endl;
    CDirector director;
    for(int i=0;i<2;i++){
        director.GetABenzModel()->Run();
    }

    for(int i=0;i<2;i++){
        director.GetBBenzModel()->Run();
    }

    for(int i=0;i<2;i++){
        director.GetCBMWModel()->Run();
    }
}


int main(){
    DoBenzRun();

    DoBuilder();

    DoDirector();

    return 0;
}
