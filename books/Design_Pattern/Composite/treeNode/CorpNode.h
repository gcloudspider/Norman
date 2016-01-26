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
#ifndef _CORPNODE_H_
#define _CORPNODE_H_
#pragma once
#include <iostream>
using namespace std;
#include <vector>

class CCorpNode{
public:
    CCorpNode();
    CCorpNode(string _name,string _pos,int _salary);
    virtual ~CCorpNode(void);
    virtual string Getinfo();
    void SetParent(CCorpNode *_pParent);
    CCorpNode *GetParent();
    virtual bool isLeaf() = 0;
private:
    string m_name;
    string m_position;
    int m_salary;
protected:
    bool m_isLeaf;
    CCorpNode *m_pParent;
};
#endif
