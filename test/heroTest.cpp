#include "../Hero.h"
#include <gtest/gtest.h>

Hero* h = (new Hero(2, 3));

TEST(Hero, heroConstructor) {
	ASSERT_EQ(2, h->getRace());
	ASSERT_EQ(3, h->getClass());
	ASSERT_EQ(600.f, h->getPosX());
	ASSERT_EQ(900.f, h->getPosY());
	EXPECT_TRUE(h->getStrength() <= 18);
	EXPECT_TRUE(h->getDexterity() <= 18);
	EXPECT_TRUE(h->getIntelligence() <= 18);
	EXPECT_TRUE(h->getConstitution() <= 18);
	EXPECT_TRUE(h->getCharisma() <= 18);
	EXPECT_TRUE(h->getWisdom() <= 18);
	ASSERT_EQ(0, h->getLevel());
	ASSERT_EQ(100, h->getLP());
	ASSERT_EQ(5, h->getMovementState());
}