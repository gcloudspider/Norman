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

#include "PieceBoard.h"

int main(){
    PieceBoard pieceBoard("A","B");
    pieceBoard.SetPiece(BLACK,PiecePos(4,4));
    pieceBoard.SetPiece(WHITE,PiecePos(4,16));
    pieceBoard.SetPiece(BLACK,PiecePos(16,4));
    pieceBoard.SetPiece(WHITE,PiecePos(16,16));
}
