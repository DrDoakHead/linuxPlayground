/**
 * Methods for the King class
 */

#ifndef KING_H
#define KING_H

#include "Piece.h"

class King : public Piece
{
  public:
    /**
     * Construtor
     * @param color The color the queen belongs to
     */
    King(Color color);

    /**
    * Destructor
    */
    ~King();

    /**
     * Copydoc::Piece::toString
     */
    std::string toString() const;

    /**
    * Copydoc::Piece::isValidMove
    */
    bool isValidMove(const Position& initPos, const Position& finalPos) const;

    /**
    * Copydoc::Piece::getPath
    */
    std::vector<Position> getPath(const Position& initPos, const Position& finalPos) const;
};

#endif // !KING_H
