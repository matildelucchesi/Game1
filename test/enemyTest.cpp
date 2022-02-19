#include "C:/Users/Matilde/source/repos/Game/Enemy.h"
#include <gtest/gtest.h>
sf::RenderWindow* w = new sf::RenderWindow(sf::VideoMode(1100, 620), "Enemy", sf::Style::Close);

Enemy* e = (new Enemy(0, 100, 0, 200.f, 300.f));

TEST(Enemy, enemyConstructor) {
	ASSERT_EQ(0, e->getRace());
	ASSERT_EQ(100, e->getLP());
	ASSERT_EQ(0, e->getLevel());
	ASSERT_EQ(200.f, e->getPosX());
	ASSERT_EQ(300.f, e->getPosY());
	ASSERT_EQ(11, e->getStrength());
	ASSERT_EQ(12, e->getDexterity());
	ASSERT_EQ(17, e->getConstitution());
	ASSERT_EQ(12, e->getIntelligence());
	ASSERT_EQ(17, e->getWisdom());
	ASSERT_EQ(19, e->getCharisma());
	ASSERT_EQ("Half Armor", e->getTypeOfArmor());
	ASSERT_EQ(750, e->getArmor().getCost());
	ASSERT_EQ(15, e->getArmor().getCA());
	ASSERT_EQ("Sword", e->getTypeOfWeapon());
	EXPECT_TRUE(e->getInitiative() > 0);
	EXPECT_TRUE(&e->getAnimation() != nullptr);
	EXPECT_TRUE(&e->getFightAnimation() != nullptr);
	EXPECT_TRUE(e->getFightAnimation().getSprite().getPosition().x == 850.f);
	EXPECT_TRUE(e->getFightAnimation().getSprite().getPosition().y == 250.f);
	EXPECT_TRUE(e->getDice() != nullptr);
}