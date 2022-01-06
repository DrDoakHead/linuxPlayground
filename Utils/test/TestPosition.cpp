/**
 * Unit tests for the position class
 */

#include <gtest/gtest.h>
#include "Position.h"


class TestPosition : public ::testing::Test
{
  protected:

    virtual void SetUp()
    {

    }

    virtual void TearDown()
    {

    }
};

TEST_F(TestPosition, constructors)
{
    Position pos(28, 42);
    EXPECT_EQ(0, pos.getX());
    EXPECT_EQ(0, pos.getY());

    Position pos2;
    EXPECT_EQ(0, pos2.getX());
    EXPECT_EQ(0, pos2.getY());

    Position pos3(2, 42);
    EXPECT_EQ(2, pos3.getX());
    EXPECT_EQ(0, pos3.getY());

    Position pos4(28, 4);
    EXPECT_EQ(0, pos4.getX());
    EXPECT_EQ(4, pos4.getY());
}

TEST_F(TestPosition, setters)
{
    Position pos;
    pos.setX(3);
    EXPECT_EQ(3, pos.getX());

    pos.setX(-2);
    EXPECT_EQ(3, pos.getX());

    pos.setY(4);
    EXPECT_EQ(4, pos.getY());

    pos.setY(23);
    EXPECT_EQ(4, pos.getY());
}

TEST_F(TestPosition, overloadedOperators)
{
    Position pos(2, 3);
    Position pos2;
    EXPECT_NE(pos, pos2);

    pos2 = pos;
    EXPECT_EQ(pos, pos2);

    Position pos3 = pos + pos2;
    EXPECT_EQ(Position(4, 6), pos3);

    Position pos4 = pos3 - pos2;
    EXPECT_EQ(Position(2, 3), pos4);
}

TEST_F(TestPosition, toString)
{
    Position pos;
    EXPECT_STREQ(pos.toString().c_str(), "x = 0, y = 0");

    Position pos2(7, 6);
    EXPECT_STREQ(pos2.toString().c_str(), "x = 7, y = 6");
}
