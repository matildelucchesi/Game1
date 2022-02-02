#include "C:/Users/Matilde/source/repos/Game/Treasure.h"
#include <gtest/gtest.h>

Treasure* s = (new Treasure(false, 10.f, 200.f));

TEST(Treasure, TreasureConstructor) {
	EXPECT_TRUE(s->getIsEmpty() == false);
	ASSERT_EQ(0, s->getState());
	ASSERT_EQ(10.f, s->getPosX());
	ASSERT_EQ(200.f, s->getPosY());
}