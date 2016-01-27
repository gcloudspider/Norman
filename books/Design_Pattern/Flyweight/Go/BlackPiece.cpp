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
#include "BlackPiece.h"

//BlackPiece::BlackPiece(PieceColor color,PiecePos pos)
BlackPiece::BlackPiece(PieceColor color)
:Piece(color){
//:Piece(color,pos){
    
}

BlackPiece::~BlackPiece(){
    
}

void BlackPiece::Draw(){
    cout <<"绘制一颗黑棋"<<endl;
}
