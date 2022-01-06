/*
*	Definition of the Position class.
*/

#include "Position.h"
#include <sstream>

Position::Position() :
    m_x(-1),
    m_y(-1)
{
}

Position::Position(int8_t x, int8_t y) :
    m_x(-1),
    m_y(-1)
{
    if (isNumberValid(x) && isNumberValid(y))
    {
        m_x = x;
        m_y = y;
    }
}

Position::~Position()
{
}

int8_t Position::getX() const
{
    return m_x;
}

void Position::setX(int8_t x)
{
    if (isNumberValid(x))
    {
        m_x = x;
    }
}

int8_t Position::getY() const
{
    return m_y;
}

void Position::setY(int8_t y)
{
    if (isNumberValid(y))
    {
        m_y = y;
    }
}

std::string Position::toString() const
{
    std::stringstream ss;
    ss << "x = " << static_cast<int>(m_x);
    ss << ", y = " << static_cast<int>(m_y);
    return ss.str();
}

Position Position::operator=(const Position& rhs)
{
    if (this != &rhs)
    {
        m_x = rhs.m_x;
        m_y = rhs.m_y;
    }
    return *this;
}

bool Position::operator==(const Position& rhs) const
{
    if (m_x != rhs.m_x || m_y != rhs.m_y)
    {
        return false;
    }
    return true;
}

bool Position::operator!=(const Position& rhs) const
{
    if (this == &rhs)
    {
        return false;
    }
    return true;
}

Position Position::operator+(const Position& rhs)
{
    if (isNumberValid(m_x + rhs.m_x) && (isNumberValid(m_y + rhs.m_y)))
    {
        m_x += rhs.m_x;
        m_y += rhs.m_y;
        return *this;
    }
    else
    {
        return Position();
    }
}

Position Position::operator-(const Position& rhs)
{
    if (isNumberValid(m_x - rhs.m_x) && (isNumberValid(m_y - rhs.m_y)))
    {
        m_x -= rhs.m_x;
        m_y -= rhs.m_y;
        return *this;
    }
    else
    {
        return Position();
    }
}

bool Position::isNumberValid(int8_t numToCheck) const
{
    if (numToCheck > -1 && numToCheck < 8)
    {
        return true;
    }
    else
    {
        return false;
    }
}

