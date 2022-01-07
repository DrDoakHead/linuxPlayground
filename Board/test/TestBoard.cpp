/**
 * Unit tests for the board class
 */

#include <gtest/gtest.h>
#include "Board.h"


class TestBoard : public ::testing::Test
{
  protected:

    virtual void SetUp()
    {
    }

    virtual void TearDown()
    {
    }

    Board board;
};

TEST_F(TestBoard, validSquares)
{
    Position pos(1,4);
    Square square(pos);
    EXPECT_EQ(square, board.getSquare(pos));
}

TEST_F(TestBoard, makeMove)
{
    Position whiteP1init(1, 1), whiteP1final(1, 2);
    board.makeMove(whiteP1init, whiteP1final);
}


