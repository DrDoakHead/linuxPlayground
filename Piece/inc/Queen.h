/**
 * Methods for the Queen class
 */

#ifndef QUEEN_H
#define QUEEN_H

#include "Piece.h"

class Queen : public Piece
{
  public:

    /**
     * Create a Queen
     * @param player The player the queen belongs to
     */
    Queen(Color color);

    /**
    * Destrutor
    */
    ~Queen();

    /**
    * Copydoc::Piece::toString
    */
    std::string toString() const;

    /**
    * Copydoc::Piece::isValidMove
    */
    bool isValidMove(const Position& initPos, const Position& finalPos) const;

    /*
    * Copydoc::Piece::getPath
    */
    std::vector<Position> getPath(const Position& initPos, const Position& finalPos) const;
};

#endif // !QUEEN_H
