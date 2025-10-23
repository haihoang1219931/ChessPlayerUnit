#include "ChessController.h"
#include <string.h>
ChessController::ChessController(ApplicationController* app)
{
    m_app = app;
    m_chessPieceDetected = false;
    m_isBlack = false;
}
void ChessController::setChessPiece(bool isBlack) {

}
void ChessController::setOpponentMove(ChessMove chessMove) {
    m_isOpponentMoved = true;
    m_opponentMove = chessMove;
}
void ChessController::setNextMove(ChessMove chessMove) {
    m_isNextMoveCalculated = true;
    m_nextMove = chessMove;
}
ChessMove ChessController::nextMove() {
    return m_nextMove;
}
void ChessController::checkPiece() {
    if(m_chessPieceDetected) {
        if(m_isBlack) {
            char chessBoard[CHESS_ROW][CHESS_COL] = {
                {'R','N','B','K','Q','B','N','R'},
                {'P','P','P','P','P','P','P','P'},
                {'.','.','.','.','.','.','.','.'},
                {'.','.','.','.','.','.','.','.'},
                {'.','.','.','.','.','.','.','.'},
                {'.','.','.','.','.','.','.','.'},
                {'p','p','p','p','p','p','p','p'},
                {'r','n','b','k','q','b','n','r'},
            };
            memcpy(m_chessBoard,chessBoard,CHESS_ROW*CHESS_COL);
        } else {
            char chessBoard[CHESS_ROW][CHESS_COL] = {
                {'r','n','b','q','k','b','n','r'},
                {'p','p','p','p','p','p','p','p'},
                {'.','.','.','.','.','.','.','.'},
                {'.','.','.','.','.','.','.','.'},
                {'.','.','.','.','.','.','.','.'},
                {'.','.','.','.','.','.','.','.'},
                {'P','P','P','P','P','P','P','P'},
                {'R','N','B','Q','K','B','N','R'},
            };
            memcpy(m_chessBoard,chessBoard,CHESS_ROW*CHESS_COL);
        }
        m_chessPieceDetected = false;
    } else {

    }
}
void ChessController::waitOpponentMove() {
    if(m_isOpponentMoved) {
        m_isOpponentMoved = false;
    } else {
    }
}
void ChessController::calculateNextMove() {
    if(m_isNextMoveCalculated) {
        m_isNextMoveCalculated = false;
//        ChessMove nextMove;
        // Todo: caculate next move
//        m_nextMove = nextMove;
    } else {

    }
}
