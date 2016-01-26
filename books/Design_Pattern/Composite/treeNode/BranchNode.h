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
#ifndef _BRANCHNODE_H_
#define _BRANCHNODE_H_
#include "CorpNode.h"

class CBranchNode:public CCorpNode{
public:
    CBranchNode(void);
    CBranchNode(string name,string pos,int salary);
    ~CBranchNode(void);

    void Add(CCorpNode *pcorpNode);
    vector<CCorpNode*> GetSubordinateInfo();
    bool IsLeaf();
private:
    vector<CCorpNode*> m_subordinateList;
};

#endif
