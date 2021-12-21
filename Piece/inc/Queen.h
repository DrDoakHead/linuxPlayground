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

    /*
    * Destrutor
    */
    virtual ~Queen();

    /*
    * copydoc Piece::isValidMove
    */
    bool isValidMove(const Position& initPos, const Position& finalPos) const;

    /*
    * copydoc Piece::getPath
    */
    std::vector<Position> getPath(const Position& initPos, const Position& finalPos) const;
};

#endif // !QUEEN_H
