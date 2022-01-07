/**
 * Unit tests for the boardManager class
 */

#include <gtest/gtest.h>
#include "BoardManager.h"


class TestBoardManager : public ::testing::Test
{
  protected:

    virtual void SetUp()
    {
    }

    virtual void TearDown()
    {
    }
};

TEST_F(TestBoardManager, toString)
{
    BoardManager bm;
    Position whiteP1init(1, 1), whiteP1final(1, 2);
    EXPECT_TRUE(bm.move(whiteP1init, whiteP1final));
    bm.getBoard().printBoard();
}


