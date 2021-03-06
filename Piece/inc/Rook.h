/**
 * This class holds the methods of the Rook piece
 *
 */
#ifndef ROOK_H
#define ROOK_H

#include "Piece.h"

class Rook : public Piece
{

  public:

    /**
     * Create a Rook
     * @param color The color the rook belongs to
     */
    Rook(Color color);

    /**
    * Destructor
    */
   ~Rook();

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

#endif // ROOK_H
