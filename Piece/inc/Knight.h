/**
 * Methods for the Knight class
 */

#ifndef KNIGHT_H
#define KNIGHT_H

#include "Piece.h"

class Knight : public Piece
{
  public:
    /**
     * Create a Knight
     * @param color The color the Knight belongs to
     */
    Knight(Color color);

    /**
    * Destructor
    */
    ~Knight();

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

#endif // !KNIGHT_H
