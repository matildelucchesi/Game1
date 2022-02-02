#include "C:/Users/Matilde/source/repos/Game/Statue.h"
#include <gtest/gtest.h>

Statue* s = (new Statue(true, 100.f, 300.f));

TEST(Statue, StatueConstructor) {
	EXPECT_TRUE(s->getIsEmpty() == true);
	ASSERT_EQ(0, s->getState());
	ASSERT_EQ(100.f, s->getPosX());
	ASSERT_EQ(300.f, s->getPosY());
}