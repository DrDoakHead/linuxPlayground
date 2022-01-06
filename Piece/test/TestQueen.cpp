/**
 * Unit tests for the queen class
 */

#include <gtest/gtest.h>
#include "Queen.h"


class TestQueen : public ::testing::Test
{
  protected:

    virtual void SetUp()
    {
        queen.reset(new Queen(Color::WHITE));
        ASSERT_TRUE(queen);
    }

    virtual void TearDown()
    {
        queen.reset();
    }

    std::unique_ptr<Piece> queen;
};

TEST_F(TestQueen, toString)
{
    EXPECT_STREQ(queen->toString().c_str(), "Q");
}

TEST_F(TestQueen, construtorValues)
{
    EXPECT_EQ(Color::WHITE, queen->getColor());
    EXPECT_EQ(TypeOfPiece::QUEEN, queen->getType());
}

TEST_F(TestQueen, isValidMove)
{
    // bishop move
    Position pos(1, 1), pos2(2, 2);
    EXPECT_TRUE(queen->isValidMove(pos, pos2));



    // invalid move
    Position pos3(5, 3);
    EXPECT_FALSE(queen->isValidMove(pos, pos3));
}

TEST_F(TestQueen, getPath)
{
    // bishop moves
    Position pos(1, 1), pos2(2, 2);
    std::vector<Position> path;
    path.push_back(pos);
    path.push_back(pos2);
    EXPECT_EQ(path, queen->getPath(pos, pos2));

    Position pos3(5, 5);
    path.push_back(Position(3, 3));
    path.push_back(Position(4, 4));
    path.push_back(pos3);
    EXPECT_EQ(path, queen->getPath(pos, pos3));
}

