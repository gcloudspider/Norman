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
#include <stdio.h>
#include "InstructionHandler.h"
#include "DirectionNode.h"
#include "ActionNode.h"
#include "DistanceNode.h"
#include "AndNode.h"
#include "DirectionNode.h"
#include "SentenceNode.h"

InstructionHandler::InstructionHandler(char *instruction)
    :m_pInstruction(instruction)
     ,m_pTree(NULL){
     
}

void InstructionHandler::Handle(){
    AbstractNode *pLeft = NULL;
    AbstractNode *pRight = NULL;
    AbstractNode *pDirection = NULL;
    AbstractNode *pAction = NULL;
    AbstractNode *pDistance = NULL;

    vector<AbstractNode *> node;

    char **InstructionArray = NULL;

    int size;
    SplitInstruction(InstructionArray,size);

    for(int i = 0;i<size;++i){
        if(strcmp(InstructionArray[i],"and")==0){
            char *pDirectionStr = InstructionArray[++i];
            pDirection = new DirectionNode(pDirectionStr);

            char *pActionStr = InstructionArray[++i];
            pAction = new ActionNode(pActionStr);

            char *pDistanceStr = InstructionArray[++i];
            pDistance  = new DistanceNode(pDistanceStr);

            pRight = new SentenceNode(pDirection,pAction,pDistance);
            node.push_back(new AndNode(pLeft,pRight));
        } else {
            char *pDirectionStr = InstructionArray[i];
            pDirection = new DirectionNode(pDirectionStr);

            char *pActionStr = InstructionArray[++i];
            pAction = new ActionNode(pActionStr);

            char *pDistanceStr = InstructionArray[++i];
            pDistance = new DistanceNode(pDistanceStr);

            pLeft = new SentenceNode(pDirection,pAction,pDistance);
            node.push_back(pLeft);
        }
    }
    m_pTree = node[node.size() - 1];
}

void InstructionHandler::Output(){
    const char *pResult = m_pTree->Interpret();

    setlocale(LC_ALL,"");
    sprintf("%s\n",pResult);

    SAFE_DELETE(pResult);
}

void InstructionHandler::SplitInstruction(char **&instruction,int &size){
    instruction = new char*[10];
    memset(instruction,0,10 * sizeof(char*));

    for(int i=0;i<10;++i){
        instruction[i] = new char[10];
        memset(instruction[i],0,10*sizeof(char));
    }

    size = 0;
    int n = 0;
    while(*m_pInstruction != '\0'){
        if(*m_pInstruction == ' '){
            size++;
            m_pInstruction++;
            n = 0;
            continue;
        }
        instruction[size][n++] = *m_pInstruction++;
    }
    size++;
}
