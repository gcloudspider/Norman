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
#ifndef _PROTOTYPE_H_
#define _PROTOTYPE_H_

class Prototype{
public:
    Prototype();
    virtual ~Prototype();

    virtual Prototype* clone() = 0;
};

class ConcretePrototype:public Prototype{
public:
    ConcretePrototype();
    ~ConcretePrototype();

    Prototype *clone();
private:
    ConcretePrototype(const ConcretePrototype&);
};

#endif

