/**
 * Unit tests for the pawn class
 */

#include <gtest/gtest.h>
#include "Pawn.h"


class TestPawn : public ::testing::Test
{
  protected:

    virtual void SetUp()
    {
        pawn.reset(new Pawn(Color::WHITE));
        ASSERT_TRUE(pawn);
    }

    virtual void TearDown()
    {
        pawn.reset();
    }

    std::unique_ptr<Piece> pawn;
};

TEST_F(TestPawn, toString)
{
    EXPECT_STREQ(pawn->toString().c_str(), "P");
}

TEST_F(TestPawn, construtorValues)
{
    EXPECT_EQ(Color::WHITE, pawn->getColor());
    EXPECT_EQ(TypeOfPiece::PAWN, pawn->getType());
}

TEST_F(TestPawn, isValidMove)
{
    // white first move
    Position pos(1, 1), pos2(1, 3);
    EXPECT_TRUE(pawn->isValidMove(pos, pos2));

    // white normal move
    Position pos4(1, 2);
    EXPECT_TRUE(pawn->isValidMove(pos, pos4));

    // white invalid
    Position pos3(1, 5);
    EXPECT_FALSE(pawn->isValidMove(pos, pos3));

    pawn->setColor(Color::BLACK);

    // black first move
    Position pos5(1, 6), pos6(1, 4);
    EXPECT_TRUE(pawn->isValidMove(pos5, pos6));

    // black normal move
    Position pos7(1, 5);
    EXPECT_TRUE(pawn->isValidMove(pos5, pos7));

    // black invalid
    EXPECT_FALSE(pawn->isValidMove(pos, pos3));
}

TEST_F(TestPawn, getPath)
{
    Position pos(1, 1), pos2(1, 2), pos3(1, 3);
    std::vector<Position> path;
    path.push_back(pos);
    path.push_back(pos2);
    EXPECT_EQ(path, pawn->getPath(pos, pos2));

    path.push_back(pos3);
    EXPECT_EQ(path, pawn->getPath(pos, pos3));

    Position pos4(1, 6), pos5(1, 5), pos6(1, 4);
    path.clear();
    path.push_back(pos5);
    path.push_back(pos4);
    pawn->setColor(Color::BLACK);
    EXPECT_EQ(path, pawn->getPath(pos4, pos5));

    path.emplace(path.begin(), pos6);
    EXPECT_EQ(path, pawn->getPath(pos4, pos6));

}

