#include <gtest/gtest.h>
#include "../ConcreteWeapon.h"
#include "../ConcreteWeaponCreator.h"
#include "../WeaponCreator.h"

ConcreteWeaponCreator weaponFactory;
ConcreteWeapon a = weaponFactory.createWeapon(ConcreteWeaponCreator::TYPE_OF_WEAPON::AX);

TEST(ConcreteWeapon, Ax) {
	ASSERT_EQ("Ax", a.getType());
	ASSERT_EQ(10, a.getCost());
}

ConcreteWeapon ar = weaponFactory.createWeapon(ConcreteWeaponCreator::TYPE_OF_WEAPON::ARCH);

TEST(ConcreteWeapon, Arch) {
	ASSERT_EQ("Arch", ar.getType());
	ASSERT_EQ(50, ar.getCost());
}

ConcreteWeapon s = weaponFactory.createWeapon(ConcreteWeaponCreator::TYPE_OF_WEAPON::SWORD);

TEST(ConcreteWeapon, Sword) {
	ASSERT_EQ("Sword", s.getType());
	ASSERT_EQ(15, s.getCost());
}

ConcreteWeapon c = weaponFactory.createWeapon(ConcreteWeaponCreator::TYPE_OF_WEAPON::CROSSBOW);

TEST(ConcreteWeapon, Crossbow) {
	ASSERT_EQ("Crossbow", c.getType());
	ASSERT_EQ(75, c.getCost());
}