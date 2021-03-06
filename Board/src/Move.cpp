/**
 * Implementation of the Move class
 *
 */

#include "Move.h"

Move::Move(const Position& initPosition, const Position& finalPosition, const std::shared_ptr<Piece>& piece) :
    initPosition(initPosition),
    finalPosition(finalPosition),
    piece(piece)
{
}

Move::Move(const Position& initPosition, const Position& finalPosition,
           const std::shared_ptr<Piece>& piece, const Square& captureSquare) :
    initPosition(initPosition),
    finalPosition(finalPosition),
    piece(piece),
    capturedPiece(captureSquare.getPiece()),
    capturedPosition(captureSquare.getPosition())
{
}

Move::~Move()
{
}

Position Move::getInitPosition() const
{
    return initPosition;
}

Position Move::getFinalPosition() const
{
    return finalPosition;
}

std::shared_ptr<Piece> Move::getPiece() const
{
    return piece;
}

bool Move::isCapture() const
{
    if (capturedPiece == nullptr) 
    { 
        return false;
    }
    return true;
}

std::shared_ptr<Piece> Move::getCapturedPiece() const
{
    return capturedPiece;
}

Position Move::getCapturePosition() const
{
    return capturedPosition;
}

