
/**
* Implementation of the Pawn class
*/

#include "Pawn.h"

Pawn::Pawn(Color color)
{
    m_color = color;
    m_typeOfPiece = TypeOfPiece::PieceType::PAWN;
}

Pawn::~Pawn()
{
}

std::string Pawn::toString() const
{
	return "P";
}

bool Pawn::isValidMove(const Position& initPos, const Position& finalPos) const
{
    if (initPos == finalPos)
    {
        return false;
    }

    int8_t diffX = abs(initPos.getX() - finalPos.getX());
    int8_t diffY = abs(initPos.getY() - finalPos.getY());

    // This is for normal pawn moves.
    if (diffX == 0 && diffY == 1)
    {
        // White can only move forward
        if (m_color == WHITE)
        {
            if (initPos.getY() < finalPos.getY())
            {
                return true;
            }
        }
        // Black can only move "backwards" with aspect to the board
        else if (m_color == BLACK)
        {
            if (initPos.getY() > finalPos.getY())
            {
                return true;
            }
        }
    }

    // This is for first pawn move
    if (diffX == 0 && diffY == 2 &&
       (initPos.getY() == 1 || initPos.getY() == 6))
    {
        // White can only move forward
        if (m_color == WHITE)
        {
            if (initPos.getY() < finalPos.getY())
            {
                return true;
            }
        }
        // Black can only move backward in a sense.
        else if (m_color == BLACK)
        {
            if (initPos.getY() > finalPos.getY())
            {
                return true;
            }
        }
    }

    // Todo
    // Need to check the board as an attack must be made to do the following moves
    // This is for normal pawn captures

    // En-passant rules
    // 1) pawn must be row 4 if white, row 3 if black
    // 2) capture must have done a 2 banger
    // 3) pawn must capture right after the 2 banger

    return false;
}

std::vector<Position> Pawn::getPath(const Position& initPos, const Position& finalPos) const
{
    // This is for pawn captures
    if (initPos.getX() != finalPos.getX())
    { 
        return std::vector<Position>{initPos, finalPos}; 
    }
    // This is for normal pawn moves and first pawn moves
    int8_t pathLength = abs(initPos.getY() - finalPos.getY()) + 1;
    std::vector<Position> path;
    for (int8_t cnt = 0; cnt < pathLength; cnt++)
    {
        path.push_back(Position(initPos.getX(), std::min(initPos.getY(), finalPos.getY()) + cnt));
    }
    return path;
}
