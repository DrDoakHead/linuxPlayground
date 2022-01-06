/**
 * Unit tests for the bishop class
 */

#include <gtest/gtest.h>
#include "Bishop.h"


class TestBishop : public ::testing::Test
{
  protected:

    virtual void SetUp()
    {
        bishop.reset(new Bishop(Color::BLACK));
        ASSERT_TRUE(bishop);
    }

    virtual void TearDown()
    {
        bishop.reset();
    }

    std::unique_ptr<Piece> bishop;
};

TEST_F(TestBishop, toString)
{
    EXPECT_STREQ(bishop->toString().c_str(), "B");
}

TEST_F(TestBishop, construtorValues)
{
    EXPECT_EQ(Color::BLACK, bishop->getColor());
    EXPECT_EQ(TypeOfPiece::BISHOP, bishop->getType());
}

TEST_F(TestBishop, isValidMove)
{
    Position pos(1, 1), pos2(2, 2);
    EXPECT_TRUE(bishop->isValidMove(pos, pos2));

    Position pos3(5, 3);
    EXPECT_FALSE(bishop->isValidMove(pos, pos3));
}

TEST_F(TestBishop, getPath)
{
    Position pos(1, 1), pos2(2, 2);
    std::vector<Position> path;
    path.push_back(pos);
    path.push_back(pos2);
    EXPECT_EQ(path, bishop->getPath(pos, pos2));

    Position pos3(5, 5);
    path.push_back(Position(3, 3));
    path.push_back(Position(4, 4));
    path.push_back(pos3);
    EXPECT_EQ(path, bishop->getPath(pos, pos3));
}

