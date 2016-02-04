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
#ifndef _JTLIST_H_
#define _JTLIST_H_
#include <iostream>
using namespace std;

typedef struct tagNode{
    int value;
    tagNode *pNext;
}Node;

class JTList{
public:
    JTList();
    JTList(const JTList &);
    ~JTList();
    JTList &operator=(const JTList &);

    long GetCount() const;
    Node *Get(const long index) const;
    Node *First() const;
    Node *Last() const;
    bool Includes(const int &) const;

    void Append(const int &);
    void Remove(Node *pNode);
    void RemoveAll();

private:
    Node *m_pHead;
    Node *m_pTail;
    long m_lCount;
};

#endif
