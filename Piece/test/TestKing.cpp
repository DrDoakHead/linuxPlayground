/**
 * Unit tests for the bishop class
 */

#include <gtest/gtest.h>
#include "King.h"


class TestKing : public ::testing::Test
{
  protected:

    virtual void SetUp()
    {
        king.reset(new King(Color::WHITE));
        ASSERT_TRUE(king);
    }

    virtual void TearDown()
    {
        king.reset();
    }

    std::unique_ptr<Piece> king;
};

TEST_F(TestKing, toString)
{
    EXPECT_STREQ(king->toString().c_str(), "K");
}

TEST_F(TestKing, construtorValues)
{
    EXPECT_EQ(Color::WHITE, king->getColor());
    EXPECT_EQ(TypeOfPiece::KING, king->getType());
}

TEST_F(TestKing, isValidMove)
{
    Position pos(1, 1), pos2(0, 1);
    EXPECT_TRUE(king->isValidMove(pos, pos2));

    Position pos3(5, 3);
    EXPECT_FALSE(king->isValidMove(pos, pos3));
}

TEST_F(TestKing, getPath)
{
    Position pos(1, 1), pos2(0, 1);
    std::vector<Position> path;
    path.push_back(pos);
    path.push_back(pos2);
    EXPECT_EQ(path, king->getPath(pos, pos2));
    EXPECT_NE(path, king->getPath(pos2, pos));
}

