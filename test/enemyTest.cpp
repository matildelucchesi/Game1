#include "C:/Users/Matilde/source/repos/Game/Enemy.h"
#include <gtest/gtest.h>
sf::RenderWindow* w = new sf::RenderWindow(sf::VideoMode(1100, 620), "Enemy", sf::Style::Close);

Enemy* m = (new Enemy(0, 100, 0, 200.f, 300.f));

TEST(Enemy, MindflayerConstructor) {
	ASSERT_EQ(0, m->getRace());
	ASSERT_EQ(100, m->getLP());
	ASSERT_EQ(10, m->getLevel());
	ASSERT_EQ(200.f, m->getPosX());
	ASSERT_EQ(300.f, m->getPosY());
	ASSERT_EQ(11, m->getStrength());
	ASSERT_EQ(12, m->getDexterity());
	ASSERT_EQ(12, m->getConstitution());
	ASSERT_EQ(19, m->getIntelligence());
	ASSERT_EQ(17, m->getWisdom());
	ASSERT_EQ(17, m->getCharisma());
	ASSERT_EQ("Full Armor", m->getTypeOfArmor());
	ASSERT_EQ(15, m->getArmor().getCA());
	ASSERT_EQ("Sword", m->getTypeOfWeapon());
}
