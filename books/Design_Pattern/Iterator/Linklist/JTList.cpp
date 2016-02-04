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
#include "JTList.h"

JTList::JTList()
    :m_pHead(NULL)
     ,m_pTail(NULL){
     
}

JTList::JTList(const JTList &){

}

JTList::~JTList(){
    Node* pCurrent = m_pHead;
    Node *pNextNode = NULL;
    while(pCurrent){
        pNextNode = pCurrent->pNext;
        delete pCurrent;
        pCurrent = pNextNode;
    }
}   

long JTList::GetCount() const{
    return m_lCount;
}

Node* JTList::Get(const long index)const{
    if(index > m_lCount -1 || index <0){
        return NULL;
    }

    int iPosTemp = 0;
    Node *pNodeTemp = m_pHead;
    while(pNodeTemp){
        if(index == iPosTemp++){
            return pNodeTemp;
        }
        pNodeTemp = pNodeTemp->pNext;
    }
    return NULL;
}

Node* JTList::First() const{
    return m_pHead;
}

Node* JTList::Last() const{
    return m_pTail;
}

bool JTList::Includes(const int &value) const{
    Node *pNodeTemp = m_pHead;
    while(pNodeTemp){
        if(value == pNodeTemp->value){
            return true;
        }
        pNodeTemp = pNodeTemp->pNext;
    }
    return false;
}

void JTList::Append(const int &value){
    Node *pInsertNode = new Node;
    pInsertNode->value = value;
    pInsertNode->pNext = NULL;

    if(m_pHead == NULL){
        m_pHead = m_pTail = pInsertNode;
    } else {
        m_pTail->pNext = pInsertNode;
        m_pTail = pInsertNode;
    }

    ++m_lCount;
}

void JTList::Remove(Node *pNode){
    if(pNode == NULL || m_pHead == NULL || m_pTail == NULL){
        return ;
    }

    if(pNode == m_pHead){
        Node *pNewHead = m_pHead->pNext;
        m_pHead = pNewHead;
    }else {
        Node *pPreviousNode = NULL;
        Node *pCurrentNode = m_pHead;
        while(pCurrentNode){
            pPreviousNode = pCurrentNode;
            pCurrentNode = pCurrentNode->pNext;
            if(pCurrentNode == pNode){
                break;
            }
        }

        Node *pNextNode = pNode->pNext;

        if(pNextNode == NULL){
            m_pTail = pPreviousNode;
        }

        pPreviousNode->pNext = pNextNode;
    }

    delete pNode;
    pNode = NULL;
    --m_lCount;
}

void JTList::RemoveAll(){
    delete this;
}


