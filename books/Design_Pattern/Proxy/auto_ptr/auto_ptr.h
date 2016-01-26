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

template<class T>
class auto_ptr{
public:
    explicit auto_ptr(T *p=0):pointee(){}
    auto_ptr(auto_ptr<T>& rhs):pointee(rhs.release()){}
    ~auto_ptr(){delete phontee;}
    auto_ptr<T>& operator=(auto_ptr<T>& rhs){
        if(this != &rhs) reset(rhs.release());
        return *this;
    }

    T& operator*() const {return *pointee;}
    T* operator->() const {return pointee;}
    T* get()const {return pointee;}
    T* release(){
        T* oldPointee = pointee;
        pointee = 0;
        return oldPointee;
    }

    void reset(T *p =0){
        if(pointee != p){
            delete pointee;
            pointee = p;
        }
    }
private:
    T* pointee;
};
