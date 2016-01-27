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
#ifndef _PIECE_H_
#define _PIECE_H_
#include <iostream>
using namespace std;
#include <vector>
enum PieceColor{
    BLACK,
    WHITE
};

struct PiecePos{
    int x;
    int y;
    PiecePos(int a,int b):x(a),y(b){}
};

class Piece{
protected:
    PieceColor m_color;  //共享
    //PiecePos m_pos; 改成享元模式 不共享
public:
    Piece(PieceColor color);
    //Piece(PieceColor color,PiecePos pos);
    ~Piece();
    virtual void Draw();
};

#endif
