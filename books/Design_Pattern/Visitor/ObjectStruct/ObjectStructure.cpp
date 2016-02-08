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
#include "ObjectStructure.h"

void ObjectStructure::Attach(Element *pElement){
    elements.push_back(pElement);
}

void ObjectStructure::Detach(Element *pElement){
    vector<Element *>::iterator it = find(elements.begin(),elements.end(),pElement);
    if(it != elements.end()){
        elements.erase(it);
    }
}

void ObjectStructure::Accept(Visitor *pVisitor){
    for(vector<Element *>::const_iterator it = elements.begin();it != elements.end();++it){
        (*it)->Accept(pVisitor);
    }
}
