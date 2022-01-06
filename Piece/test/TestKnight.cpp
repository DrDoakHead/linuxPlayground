/**
 * Unit tests for the knight class
 */

#include <gtest/gtest.h>
#include "Knight.h"


class TestKnight : public ::testing::Test
{
  protected:

    virtual void SetUp()
    {
        knight.reset(new Knight(Color::WHITE));
        ASSERT_TRUE(knight);
    }

    virtual void TearDown()
    {
        knight.reset();
    }

    std::unique_ptr<Piece> knight;
};

TEST_F(TestKnight, toString)
{
    EXPECT_STREQ(knight->toString().c_str(), "N");
}

TEST_F(TestKnight, construtorValues)
{
    EXPECT_EQ(Color::WHITE, knight->getColor());
    EXPECT_EQ(TypeOfPiece::KNIGHT, knight->getType());
}

TEST_F(TestKnight, isValidMove)
{
    Position pos(0, 1), pos2(1, 3);
    EXPECT_TRUE(knight->isValidMove(pos, pos2));

    Position pos3(5, 3);
    EXPECT_FALSE(knight->isValidMove(pos, pos3));
}

TEST_F(TestKnight, getPath)
{
    Position pos(0, 1), pos2(1, 3);
    std::vector<Position> path;
    path.push_back(pos);
    path.push_back(pos2);
    EXPECT_EQ(path, knight->getPath(pos, pos2));
    EXPECT_NE(path, knight->getPath(pos2, pos));
}

