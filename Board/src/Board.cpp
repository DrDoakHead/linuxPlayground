/*
* Implementation of the Board class
*/

#include "Board.h"
#include "Rook.h"
#include "Bishop.h"
#include "Knight.h"
#include "Pawn.h"
#include "Queen.h"
#include "King.h"

#include <iostream>

Board::Board()
{
    setSquares();
    setWhitePieces();
    setBlackPieces();
}

Board::~Board()
{
}

void Board::resetBoard() 
{
    setSquares();
    setWhitePieces();
    setBlackPieces();
}

void Board::setSquares() 
{
    for (int8_t x = 0; x < 8; x++)
    {
    	board.push_back(std::vector<Square>());
        for (int8_t y = 0; y < 8; y++)
        {
            board.at(x).push_back(Square(Position(x, y)));
        }
    }
}

void Board::setWhitePieces() 
{
    board[2][0].setPiece(std::shared_ptr<Bishop>(new Bishop(WHITE)));
    board[5][0].setPiece(std::shared_ptr<Bishop>(new Bishop(WHITE)));
    board[1][0].setPiece(std::shared_ptr<Knight>(new Knight(WHITE)));
    board[6][0].setPiece(std::shared_ptr<Knight>(new Knight(WHITE)));
    board[0][0].setPiece(std::shared_ptr<Rook>(new Rook(WHITE)));
    board[7][0].setPiece(std::shared_ptr<Rook>(new Rook(WHITE)));
    board[3][0].setPiece(std::shared_ptr<Queen>(new Queen(WHITE)));
    board[4][0].setPiece(std::shared_ptr<King>(new King(WHITE)));
    board[0][1].setPiece(std::shared_ptr<Pawn>(new Pawn(WHITE)));
    board[1][1].setPiece(std::shared_ptr<Pawn>(new Pawn(WHITE)));
    board[2][1].setPiece(std::shared_ptr<Pawn>(new Pawn(WHITE)));
    board[3][1].setPiece(std::shared_ptr<Pawn>(new Pawn(WHITE)));
    board[4][1].setPiece(std::shared_ptr<Pawn>(new Pawn(WHITE)));
    board[5][1].setPiece(std::shared_ptr<Pawn>(new Pawn(WHITE)));
    board[6][1].setPiece(std::shared_ptr<Pawn>(new Pawn(WHITE)));
    board[7][1].setPiece(std::shared_ptr<Pawn>(new Pawn(WHITE)));
}

void Board::setBlackPieces()
{
    board[2][7].setPiece(std::shared_ptr<Bishop>(new Bishop(BLACK)));
    board[5][7].setPiece(std::shared_ptr<Bishop>(new Bishop(BLACK)));
    board[1][7].setPiece(std::shared_ptr<Knight>(new Knight(BLACK)));
    board[6][7].setPiece(std::shared_ptr<Knight>(new Knight(BLACK)));
    board[0][7].setPiece(std::shared_ptr<Rook>(new Rook(BLACK)));
    board[7][7].setPiece(std::shared_ptr<Rook>(new Rook(BLACK)));
    board[3][7].setPiece(std::shared_ptr<Queen>(new Queen(BLACK)));
    board[4][7].setPiece(std::shared_ptr<King>(new King(BLACK)));
    board[0][6].setPiece(std::shared_ptr<Pawn>(new Pawn(BLACK)));
    board[1][6].setPiece(std::shared_ptr<Pawn>(new Pawn(BLACK)));
    board[2][6].setPiece(std::shared_ptr<Pawn>(new Pawn(BLACK)));
    board[3][6].setPiece(std::shared_ptr<Pawn>(new Pawn(BLACK)));
    board[4][6].setPiece(std::shared_ptr<Pawn>(new Pawn(BLACK)));
    board[5][6].setPiece(std::shared_ptr<Pawn>(new Pawn(BLACK)));
    board[6][6].setPiece(std::shared_ptr<Pawn>(new Pawn(BLACK)));
    board[7][6].setPiece(std::shared_ptr<Pawn>(new Pawn(BLACK)));
}

std::vector<std::vector<Square> > Board::getBoard() const
{
    return board;
}

Square Board::getSquare(const Position& position) const
{
    Square result;
    for (int8_t x = 0; x < 8; x++)
    {
        for (int8_t y = 0; y < 8; y++) {
            if (board.at(x).at(y).getPosition() == position)
            {
                result = board.at(x).at(y);
            }
        }
    }
    return result;
}

void Board::makeMove(const Position& startPosition, const Position& finalPosition)
{
    Square initSquare = getSquare(startPosition);
    Square finalSquare = getSquare(finalPosition);
    makeMove(initSquare, finalSquare);
}

void Board::makeMove(Square& initSquare, Square& finalSquare)
{
    //Has a piece been captured;
    if (finalSquare.isOccupied())
    {
        capturePiece(finalSquare);
    }
    //Make the move
    finalSquare.setPiece(initSquare.getPiece());
    initSquare.releasePiece();
}

void Board::setPiece(const Position& position, const std::shared_ptr<Piece>& piece)
{
    getSquare(position).setPiece(piece);
}

void Board::capturePiece(Square& square) const
{
    if (square.isOccupied())
    {
        square.releasePiece();
    }
}

void Board::printBoard() const
{
    for (int y = 7; y >= 0; y--) 
    {
    	std::cout << " ================================ " << std::endl;
        for (int x = 0; x < 8; x++)
        {
            std::cout << "| " + (board[x][y].getPieceString() + " ");
        }
        std::cout << "|" << std::endl;
    }
    std::cout << " ================================ " << std::endl;
}
