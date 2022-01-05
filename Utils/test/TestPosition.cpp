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
