/*
*	Definition of the Piece class.
*/

#include "Piece.h"

Piece::Piece() :
	m_color(Color::UNKNOWN),
	m_typeOfPiece(TypeOfPiece::PieceType::UNKNOWN)
{
}

Piece::Piece(Color color, TypeOfPiece::PieceType pieceType) :
	m_color(color),
	m_typeOfPiece(pieceType)
{
}

Piece::~Piece()
{
}

Color Piece::getColor() const
{
	return m_color;
}

void Piece::setColor(Color color)
{
	m_color = color;
}

TypeOfPiece::PieceType Piece::getType() const
{
	return m_typeOfPiece;
}
