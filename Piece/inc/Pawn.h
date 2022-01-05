/**
 * Methods of the Pawn class
 */

#ifndef PAWN_H
#define PAWN_H

#include "Piece.h"

class Pawn : public Piece
{
public:
    /**
     * Construtor
     * @param color - The color the pawn belongs to
     */
    Pawn(Color Color);

    /**
    * Destructor
    */
    ~Pawn();

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

#endif // PAWN_H
