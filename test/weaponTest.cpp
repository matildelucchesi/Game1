#include <gtest/gtest.h>
#include "C:/Users/Matilde/source/repos/Game/ConcreteWeapon.h"
#include "C:/Users/Matilde/source/repos/Game/ConcreteWeaponCreator.h"
#include "C:/Users/Matilde/source/repos/Game/WeaponCreator.h"

ConcreteWeaponCreator* w = new ConcreteWeaponCreator();
std::unique_ptr<ConcreteWeapon> wp = w->createWeapon(WeaponCreator::TYPE_OF_WEAPON::AX);

TEST(ConcreteWeapon, AxConstructor) {
	ASSERT_EQ(10, wp->getCost());
	EXPECT_TRUE(wp->getType() == "Ax");
}

std::unique_ptr<ConcreteWeapon> wd = w->createWeapon(WeaponCreator::TYPE_OF_WEAPON::SWORD);

TEST(ConcreteWeapon, SwordConstructor) {
	ASSERT_EQ(15, wd->getCost());
	EXPECT_TRUE(wd->getType() == "Sword");
}

std::unique_ptr<ConcreteWeapon> wc = w->createWeapon(WeaponCreator::TYPE_OF_WEAPON::CROSSBOW);

TEST(ConcreteWeapon, CrossbowConstructor) {
	ASSERT_EQ(75, wc->getCost());
	EXPECT_TRUE(wc->getType() == "Crossbow");
}

std::unique_ptr<ConcreteWeapon> wa = w->createWeapon(WeaponCreator::TYPE_OF_WEAPON::ARCH);

TEST(ConcreteWeapon, ArchConstructor) {
	ASSERT_EQ(50, wa->getCost());
	EXPECT_TRUE(wa->getType() == "Arch");
}