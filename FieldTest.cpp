/**
 * Unit Tests for Field class
**/

#include <gtest/gtest.h>
#include <iostream>
#include "Field.h"
 
class FieldTest : public ::testing::Test
{
	protected:
		FieldTest(){}
		virtual ~FieldTest(){}
		virtual void SetUp(){}
		virtual void TearDown(){}
};

TEST(FieldTest, placeMineInBounds)
{
	Field minefield;
	
	minefield.placeMine(4,5);
	ASSERT_EQ( MINE_HIDDEN, minefield.get(4,5) );
}

/* Test for inboundsness */
TEST(FieldTest, placeMineOutBounds)
{
   Field minefield(3);

   minefield.placeMine(-1, 4);
   ASSERT_ANY_THROW(minefield.get(-1, 4));
}

/* Tests if an exception is thrown for isSafe */
TEST(FieldTest, isSafeThrow)
{
   Field minefield(3);

   minefield.placeMine(-1, 4);
   ASSERT_ANY_THROW(minefield.isSafe(-1, 4));
}

/* Tests if isSafe shows a safe 'square' */
TEST(FieldTest, isSafeSafetyTest)
{
   Field minefield(3);

   ASSERT_TRUE(minefield.isSafe(1, 1));
}

/* Tests if isSafe tells if a square has a mine */
TEST(FieldTest, isSafeUnsafetyTest)
{
   Field minefield(3);

   minefield.placeMine(1, 1);
   ASSERT_FALSE(minefield.isSafe(1, 1));
}

/* Tests if revealAdjacent looks for out of boundsness */
/*
TEST(FieldTest, revealAdjacentOutBounds)
{
   Field minefield(3);

   ASSERT_NO_FATAL_FAILURE(minefield.revealAdjacent(12, 12));
}
*/

/* Tests is revealAdjacent operates correctly for emptyness */
TEST(FieldTest, revealAdjacentEmptySquare)
{
   Field minefield(3);

   minefield.revealAdjacent(1, 1);
   ASSERT_EQ(EMPTY_SHOWN, minefield.get(1, 1));
}
