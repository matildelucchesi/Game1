#include "C:/Users/Matilde/source/repos/Game/Enemy.h"
#include <gtest/gtest.h>

Enemy* m = (new Enemy("Mindflayer", 100, 10, 200.f, 300.f));

TEST(Enemy, MindflayerConstructor) {
	ASSERT_EQ(0, m->getRace());
	ASSERT_EQ(100, m->getHP());
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
	ASSERT_EQ(18, m->getCA());
	ASSERT_EQ("Sword", m->getTypeOfWeapon());
}


Enemy* w = (new Enemy("Will O Wisp", 50, 1, 100.f, 200.f));

TEST(Enemy, WillOWispConstructor) {
	ASSERT_EQ(1, w->getRace());
	ASSERT_EQ(50, w->getHP());
	ASSERT_EQ(1, w->getLevel());
	ASSERT_EQ(100.f, w->getPosX());
	ASSERT_EQ(200.f, w->getPosY());
	ASSERT_EQ(1, w->getStrength());
	ASSERT_EQ(28, w->getDexterity());
	ASSERT_EQ(10, w->getConstitution());
	ASSERT_EQ(13, w->getIntelligence());
	ASSERT_EQ(14, w->getWisdom());
	ASSERT_EQ(11, w->getCharisma());
	ASSERT_EQ("None", w->getTypeOfArmor());
	ASSERT_EQ(10, w->getCA());
	ASSERT_EQ("Arch", w->getTypeOfWeapon());
}

Enemy* t = (new Enemy("Treant", 90, 9, 90.f, 100.f));

TEST(Enemy, TreantConstructor) {
	ASSERT_EQ(2, t->getRace());
	ASSERT_EQ(90, t->getHP());
	ASSERT_EQ(9, t->getLevel());
	ASSERT_EQ(90.f, t->getPosX());
	ASSERT_EQ(100.f, t->getPosY());
	ASSERT_EQ(23, t->getStrength());
	ASSERT_EQ(8, t->getDexterity());
	ASSERT_EQ(21, t->getConstitution());
	ASSERT_EQ(12, t->getIntelligence());
	ASSERT_EQ(16, t->getWisdom());
	ASSERT_EQ(13, t->getCharisma());
	ASSERT_EQ("Padded Armor", t->getTypeOfArmor());
	ASSERT_EQ(11, t->getCA());
	ASSERT_EQ("Ax", t->getTypeOfWeapon());
}

Enemy* b = (new Enemy("Bullywug", 70, 5, 700.f, 500.f));

TEST(Enemy, BullywugConstructor) {
	ASSERT_EQ(3, b->getRace());
	ASSERT_EQ(70, b->getHP());
	ASSERT_EQ(5, b->getLevel());
	ASSERT_EQ(700.f, b->getPosX());
	ASSERT_EQ(500.f, b->getPosY());
	ASSERT_EQ(12, b->getStrength());
	ASSERT_EQ(12, b->getDexterity());
	ASSERT_EQ(13, b->getConstitution());
	ASSERT_EQ(7, b->getIntelligence());
	ASSERT_EQ(10, b->getWisdom());
	ASSERT_EQ(7, b->getCharisma());
	ASSERT_EQ("Half Armor", b->getTypeOfArmor());
	ASSERT_EQ(15, b->getCA());
	ASSERT_EQ("Crossbow", b->getTypeOfWeapon());
}