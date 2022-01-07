/**
 * Unit tests for the square class
 */

#include <gtest/gtest.h>
#include "Square.h"
#include "Rook.h"


class TestSquare : public ::testing::Test
{
  protected:

    virtual void SetUp()
    {
    }

    virtual void TearDown()
    {
    }
};

TEST_F(TestSquare, everything)
{
    Square square;
    EXPECT_EQ(Position(), square.getPosition());
    EXPECT_FALSE(square.getPiece());
    EXPECT_STREQ("x = -1, y = -1", square.getPositionString().c_str());
    EXPECT_STREQ(" ", square.getPieceString().c_str());
    EXPECT_FALSE(square.isOccupied());

    Position pos(5, 2);
    Square square2(pos);
    EXPECT_EQ(pos, square2.getPosition());
    EXPECT_FALSE(square2.getPiece());
    EXPECT_STREQ("x = 5, y = 2", square2.getPositionString().c_str());
    EXPECT_STREQ(" ", square2.getPieceString().c_str());
    EXPECT_FALSE(square2.isOccupied());

    Position pos2(3, 2);
    std::shared_ptr<Rook> rook(new Rook(BLACK));
    Square square3(pos2, rook);
    EXPECT_EQ(pos2, square3.getPosition());
    EXPECT_STREQ("x = 3, y = 2", square3.getPositionString().c_str());
    EXPECT_STREQ("R", square3.getPieceString().c_str());
    EXPECT_TRUE(square3.isOccupied());
    ASSERT_TRUE(square3.getPiece());
    std::shared_ptr<Rook> upCast = std::dynamic_pointer_cast<Rook>(square3.getPiece());
    ASSERT_TRUE(upCast);
    EXPECT_EQ(TypeOfPiece::ROOK, upCast->getType());

    square3.releasePiece();
    EXPECT_FALSE(square3.isOccupied());
    square3.setPiece(rook);
    EXPECT_TRUE(square3.isOccupied());

    EXPECT_NE(square, square3);
    square = square3;
    EXPECT_EQ(square, square3);
}


