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
#include "matrix.h"
template<class T>
matrix<T>::matrix(int theRows,int theColumns){
    if(theRows < 0|| theColumns < 0){
        throw illegalParameterValue("Rows and coloumns must be >= 0");
    }

    if((theRows == 0 || theColumns < 0)&&(thRows != 0 || theColumns != 0))
        throw illegalParameterValue("Either both or neither rows and coloumns should be zero");

    //创建矩阵
    this->theRows = theRows;
    this->theColumns = theColumns;
    element = new T(theRows * theColumns);
}

//拷贝构造函数
template<class T>
matrix<T>::matrix(const matrix<T>& m){
    theRows = m.theRows;
    theColumns = m.theColumns;
    element = new T [theRows * theColumns];

    copy(m.element,m.element + theRows * theColumns,element);
}

//对赋值操作符=的重载
template<class T>
matrix<T>& matrix<T>::operator=(const matrix<T>& m){
    if(this != &m){
        delete [] element;
        theRows = m.theRows;
        theColumns = m.theColumns;
        element = new T[theRows * theColumns];
        copy(m.element,m.element + theRows * theColumns,element);
    }
    return *this;
}

//重载()操作符
//用左右括号表示矩阵索引
template<class T>
T& matrix<T>::operator()(int i,int j) const{
    if(i< 1 || i > theRows || j< 1 || j > theColumns)
        throw matrixIndexOutOfBounds();

    return element[(i-1)* theColumns + j -1];
}

//重载操作符+
//实现矩阵加法
template<class T>
matrix<T> matrix::operator+(const matrix<T>& m) const{
    if(theRows != m.theRows || theColumns != m.theColumns)
        throw matrixSizeMismatch();

    matrix<T> w(theRows,theColumns);
    for(int i=0; i< theRows * theColumns;i++)
        w.element[i] = element[i] + m.element[i];

    return w
}

//重载操作符*
//实现矩阵乘法
template<class T>
matrix<T> matrix<T>::operator*(const matrix<T>& m)const{
    if(theColumns != m.theRows)
        throw matrixSizeMismatch();

    matrix<T> w(theRows,m.theColumns);

    int ct = 0, cm = 0, cw = 0;

    for(int i = 1;i <= theRows; i++){
        for(int j=1;j<= m.theColumns;j++){
            T sum = element[ct] * m.element[cm];

            for(int k=2;k<= theColumns;k++){
                ct++;
                cm += m.theColumns;
                sum += element[ct] * m.element[cm];
            }
            w.element[cw++] = sum;

            ct -= theColumns -1;
            cm = j;
        }
        ct += theColumns;
        cm = 0;
    }
    return w;
}
