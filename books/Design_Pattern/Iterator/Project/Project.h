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
#ifndef _PROJECT_H_
#define _PROJECT_H_
#pragma once
#include "IProject.h"
#include "IProjectIterator.h"
class CProject:public IProject{
public:
    CProject();
    CProject(string name,int num,int cost);
    ~CProject();
    string GetProjectInfo();
    void Add(string name,int num,int cost);
    IProjectIterator* GetIterator();
    void Erase();
private:
    string m_name;
    int m_num;
    int m_cost;
    vector<IProject*> m_projectList;
};

#endif
