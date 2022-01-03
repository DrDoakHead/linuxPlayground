/**
 * Implementation of the King class
 */

#include "King.h"

King::King(Color color)
{
    m_color = color;
    m_typeOfPiece = TypeOfPiece::PieceType::KING;
}

King::~King()
{
}

std::string King::toString() const
{
    return "K";
}

bool King::isValidMove(const Position& initPos, const Position& finalPos) const
{
    if (initPos == finalPos)
    {
        return false;
    }

    int8_t diffX = abs(initPos.getX() - finalPos.getX());
    int8_t diffY = abs(initPos.getY() - finalPos.getY());
    if (diffX + diffY == 1)
    {
        return true;
    }
    return false;
}

std::vector<Position> King::getPath(const Position& initPos, const Position& finalPos) const
{
    std::vector<Position> path;
    path.push_back(initPos);
    path.push_back(finalPos);
    return path;
}
