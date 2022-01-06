/**
 * Implementation of the Bishop class
 */

#include "Bishop.h"

Bishop::Bishop(Color color)
{
    m_color = color;
    m_typeOfPiece = TypeOfPiece::PieceType::BISHOP;
}

Bishop::~Bishop()
{
}

std::string Bishop::toString() const
{
    return "B";
}

bool Bishop::isValidMove(const Position& initPos, const Position& finalPos) const
{
    if (initPos == finalPos)
    { 
        return false;
    }

    int8_t diffX = abs(initPos.getX() - finalPos.getX());
    int8_t diffY = abs(initPos.getY() - finalPos.getY());
    if (diffX == diffY)
    {
        return true;
    }
    return false;
}

std::vector<Position> Bishop::getPath(const Position& initPos, const Position& finalPos) const
{
    std::vector<Position> path;
    int8_t pathLength = (abs(initPos.getX() - finalPos.getX()) +
        abs(initPos.getY() - finalPos.getY())) / 2 + 1;

    //Integer.signum(a) provides the sign of a number 1 if positive and -1 if negative.
    //In this case i am considering initPos as the first point and finalPos as second
    int8_t signOfX = Position::sgn(finalPos.getX() - initPos.getX());
    int8_t signOfY = Position::sgn(finalPos.getY() - initPos.getY());

    for (int8_t cnt = 0; cnt < pathLength; cnt++)
    {
        path.push_back(Position(initPos.getX() + (signOfX * cnt), initPos.getY() + (signOfY * cnt)));
    }
    return path;
}
