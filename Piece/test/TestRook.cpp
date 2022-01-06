/**
 * Unit tests for the rook class
 */

#include <gtest/gtest.h>
#include "Rook.h"


class TestRook : public ::testing::Test
{
  protected:

    virtual void SetUp()
    {
        rook.reset(new Rook(Color::BLACK));
        ASSERT_TRUE(rook);
    }

    virtual void TearDown()
    {
        rook.reset();
    }

    std::unique_ptr<Piece> rook;
};

TEST_F(TestRook, toString)
{
    EXPECT_STREQ(rook->toString().c_str(), "R");
}

TEST_F(TestRook, construtorValues)
{
    EXPECT_EQ(Color::BLACK, rook->getColor());
    EXPECT_EQ(TypeOfPiece::ROOK, rook->getType());
}

TEST_F(TestRook, isValidMove)
{
    Position pos(1, 1), pos2(1, 2);
    EXPECT_TRUE(rook->isValidMove(pos, pos2));

    Position pos3(5, 3);
    EXPECT_FALSE(rook->isValidMove(pos, pos3));

    Position pos4(3, 3), pos5(1, 3);
    EXPECT_TRUE(rook->isValidMove(pos4, pos5));
}

TEST_F(TestRook, getPath)
{
    Position pos(1, 1), pos2(1, 2);
    std::vector<Position> path;
    path.push_back(pos);
    path.push_back(pos2);
    EXPECT_EQ(path, rook->getPath(pos, pos2));

    Position pos3(1, 3), pos4(1, 4), pos5(1, 5);
    path.push_back(pos3);
    path.push_back(pos4);
    path.push_back(pos5);
    EXPECT_EQ(path, rook->getPath(pos, pos5));
}

