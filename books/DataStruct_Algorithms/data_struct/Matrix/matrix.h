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
#ifndef _MATRIX_H_
#define _MATRIX_H_
template<class T>
class matrix{
    friend ostream& operator<<(ostream&,const matrix<T>&);
public:
    matrix(int theRows = 0,int theColumns = 0);
    matrix(const matrix<T>&);
    ~matrix(){delete [] element;}
    int rows() const{return theColumns;}
    T& operator()(int i,int j)const;
    matrix<T>& operator=(const matrix<T>&);
    matrix<T> operator+() const;
    matrix<T> operator+(const matrix<T>&) const;
    matrix<T> operator-()const ;
    matrix<T> operator-(const matrix<T>&) const;
    matrix<T> operator*(const matrix<T>&) const;
    matrix<T>& operator+=(const T&);
private:
    int theRows,theColumns;
    T *element;
};

#endif
