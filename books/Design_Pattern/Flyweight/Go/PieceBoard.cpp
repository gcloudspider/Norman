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

PieceBoard::PieceBoard(string black,string white)
:m_blackName(black)
,m_whiteName(white){
    m_blackPiece = NULL;
    m_whitePiece = NULL;
}

PieceBoard::~PieceBoard(){
    //Clear();
    delete m_blackPiece;
    delete m_whitePiece;
}

void PieceBoard::SetPiece(PieceColor color,PiecePos pos){
    Piece *piece = NULL;
    if(color == BLACK){
        //piece = new BlackPiece(color,pos);
        if(m_blackPiece == NULL)
            m_blackPiece = new BlackPiece(color);
        cout<<m_blackName<<"在位置("<<pos.x<<","<<pos.y<<")";
        //piece->Draw();
        m_blackPiece->Draw();
    } else{
        if(m_whitePiece == NULL)
            //piece = new WhitePiece(color,pos);
            m_whitePiece = new WhitePiece(color);
        cout<<m_whiteName<<"在位置("<<pos.x<<","<<pos.y<<")";
        m_whitePiece->Draw();
    }
    //m_vecPiece.push_back(piece);
    m_vecPos.push_back(pos);
}

/*
void PieceBoard::Clear(){
    int size = m_vecPiece.size();
    for(int i=0;i<size;i++)
        delete m_vecPiece[i];
}
*/
