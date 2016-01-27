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
#ifndef _PIECEBOARD_H_
#define _PIECEBOARD_H_
#include "Piece.h"
#include "BlackPiece.h"
#include "WhitePiece.h"

class PieceBoard{
private:
    //vector<Piece*> m_vecPiece;
    vector<PiecePos> m_vecPos;      //存放棋子位置
    Piece* m_blackPiece;            //黑棋子
    Piece* m_whitePiece;            //白棋子
    string m_blackName;
    string m_whiteName;

public:
    PieceBoard(string black,string white);
    ~PieceBoard();
    void SetPiece(PieceColor color,PiecePos pos);

    //void Clear();
};
#endif
