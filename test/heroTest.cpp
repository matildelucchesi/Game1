#include "../Hero.h"
#include <gtest/gtest.h>

sf::RenderWindow* window = new sf::RenderWindow(sf::VideoMode(1100, 620), "Hero", sf::Style::Close);

Hero* h = (new Hero(2, 3));
TileMap* m = new TileMap("../MapXML/FLMap.xml");
InteractiveObject* o;

TEST(Hero, heroConstructor) {
	ASSERT_EQ(2, h->getRace());
	ASSERT_EQ(3, h->getClass());
	ASSERT_EQ(600.f, h->getPosX());
	ASSERT_EQ(900.f, h->getPosY());
	ASSERT_EQ(150.f, h->getFightAnimation().getSprite().getPosition().x);
	ASSERT_EQ(250.f, h->getFightAnimation().getSprite().getPosition().y);
	ASSERT_EQ(0, h->getLevel());
	ASSERT_EQ(100, h->getLP());
	ASSERT_EQ(5, h->getMovementState());
	ASSERT_EQ(0, h->getNumPotion());
	EXPECT_TRUE(h->getStrength() <= 18);
	EXPECT_TRUE(h->getDexterity() <= 18);
	EXPECT_TRUE(h->getIntelligence() <= 18);
	EXPECT_TRUE(h->getConstitution() <= 18);
	EXPECT_TRUE(h->getCharisma() <= 18);
	EXPECT_TRUE(h->getWisdom() <= 18);
	EXPECT_TRUE(h->getGoldCoins() > 0);
	EXPECT_TRUE(h->getDice() != nullptr);
	for (int i = 0; i < MAX_POTION; i++) {
		EXPECT_TRUE(h->getPotion(i) == NULL);
	}
	EXPECT_TRUE(&h->getAnimation() != nullptr);
	EXPECT_TRUE(&h->getFightAnimation() != nullptr);
}

TEST(Hero, takePotion) {
	for (int j = 0; j < m->getInteractiveObjectNumber(); j++) {
		if (m->getInteractiveObject()[j]->getIsEmpty() == false) {
			o = m->getInteractiveObject()[j];
			break;
		}
	}
	h->takePotion(o);
	EXPECT_TRUE(h->getPotion(0) != nullptr);
	ASSERT_EQ(1, h->getNumPotion());
}


TEST(Hero, usePotion) {
	h->usePotion(0);
	ASSERT_EQ(0, h->getNumPotion());
	EXPECT_TRUE(h->getLP() > 10);
}

TEST(Hero, boundCollision) {
	h->setPosX(0.f);
	h->setPosY(100.f);
	h->getAnimation().getSprite().setPosition(h->getPosX(), h->getPosY());
	h->getAnimation().updateBoundingBox();
	ASSERT_EQ(true, m->getBackgroundBoundingBox()->intersects(h->getAnimation().getBoundingBox()));
}

TEST(Hero, interactiveObjectBoundCollision) {
	o = m->getInteractiveObject()[0];
	h->setPosX(o->getPosX());
	h->setPosY(o->getPosY());
	h->getAnimation().getSprite().setPosition(h->getPosX(), h->getPosY());
	h->getAnimation().updateBoundingBox();
	ASSERT_EQ(true, o->getBoundingBox()->intersects(h->getAnimation().getBoundingBox()));
}

TEST(Hero, armor) {
	h->setTypeOfArmor("Half Armor");
	EXPECT_TRUE(&h->getArmor() != nullptr);
	ASSERT_EQ("Half Armor", h->getArmor().getType());
	ASSERT_EQ(15, h->getArmor().getCA());
}

TEST(Hero, weapon) {
	h->setTypeOfWeapon("Sword");
	EXPECT_TRUE(&h->getWeapon() != nullptr);
	ASSERT_EQ("Sword", h->getWeapon().getType());
}