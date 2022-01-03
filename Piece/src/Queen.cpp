/**
 * Implementation of the Queen class
 */

#include "Queen.h"

Queen::Queen(Color color)
{
    m_color = color;
    m_typeOfPiece = TypeOfPiece::PieceType::QUEEN;
}

Queen::~Queen()
{
}

std::string Queen::toString() const
{
	return "Q";
}

bool Queen::isValidMove(const Position& initPos, const Position& finalPos) const
{
    // The queen's valid moves are a combination of Bishop, Rook, and King
    if (initPos == finalPos) 
    { 
        return false;
    }

    // This is the bishop move
    int8_t diffX = abs(initPos.getX() - finalPos.getX());
    int8_t diffY = abs(initPos.getY() - finalPos.getY());
    if (diffX == diffY)
    {
        return true;
    }

    // This is the rook move
    if (initPos.getX() == finalPos.getX() ||
        initPos.getY() == finalPos.getY())
    {
        return true;
    }

    // This is a king move
    if (diffX + diffY == 1)
    {
        // check if this move will not result in the king 
        // being attacked if so return true 
        return true;
    }

    return false;
}

std::vector<Position> Queen::getPath(const Position& initPos, const Position& finalPos) const
{
    std::vector<Position> path;
    // If it is a rook move
    if (initPos.getX() == finalPos.getX() ||
        initPos.getY() == finalPos.getY())
    {
        int8_t pathLength = abs(initPos.getX() - finalPos.getX())
            + abs(initPos.getY() - finalPos.getY()) + 1;

        for (int8_t cnt = 0; cnt < pathLength; cnt++)
        {
            if (initPos.getX() == finalPos.getX())
            {
                path.push_back(Position(initPos.getX(), std::min(initPos.getY(), finalPos.getY()) + cnt));
            }
            else
            {
                path.push_back(Position(std::min(initPos.getX(), finalPos.getX()) + cnt, initPos.getY()));;
            }
        }

    }
    // If it is a bishop move
    else if (abs(initPos.getX() - finalPos.getX()) == abs(initPos.getY() - finalPos.getY()))
    {
        int pathLength = (abs(initPos.getX() - finalPos.getX()) +
            abs(initPos.getY() - finalPos.getY())) / 2 + 1;

        //In this case i am considering initPos as the first point and finalPos as second
        int8_t i_X = Position::sgn(finalPos.getX() - initPos.getX());
        int8_t i_Y = Position::sgn(finalPos.getY() - initPos.getY());

        for (int8_t cnt = 0; cnt < pathLength; cnt++)
        {
            path.push_back(Position(initPos.getX() + i_X * cnt, initPos.getY() + i_Y * cnt));
        }
    }
    // If it is a king move
    else if ((abs(initPos.getX() - finalPos.getX()) + abs(initPos.getY() - finalPos.getY())) == 1)
    {
        path.push_back(initPos);
        path.push_back(finalPos);
    }
    return path;
}
