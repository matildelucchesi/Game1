#include <gtest/gtest.h>
#include "../ConcreteArmor.h"
#include "../ConcreteArmorCreator.h"
#include "../ArmorCreator.h"

ConcreteArmorCreator armorFactory;
ConcreteArmor p = armorFactory.createArmor(ConcreteArmorCreator::TYPE_OF_ARMOR::PADDED_ARMOR);

TEST(ConcreteArmor, paddedArmor) {
	ASSERT_EQ("Padded Armor", p.getType());
	ASSERT_EQ(11, p.getCA());
	ASSERT_EQ(50, p.getCost());
}

ConcreteArmor h = armorFactory.createArmor(ConcreteArmorCreator::TYPE_OF_ARMOR::HALF_ARMOR);

TEST(ConcreteArmor, halfArmor) {
	ASSERT_EQ("Half Armor", h.getType());
	ASSERT_EQ(15, h.getCA());
	ASSERT_EQ(750, h.getCost());
}

ConcreteArmor f = armorFactory.createArmor(ConcreteArmorCreator::TYPE_OF_ARMOR::FULL_ARMOR);

TEST(ConcreteArmor, fullArmor) {
	ASSERT_EQ("Full Armor", f.getType());
	ASSERT_EQ(18, f.getCA());
	ASSERT_EQ(900, f.getCost());
}

ConcreteArmor n = armorFactory.createArmor(ConcreteArmorCreator::TYPE_OF_ARMOR::NONE);

TEST(ConcreteArmor, none) {
	ASSERT_EQ("None", n.getType());
	ASSERT_EQ(10, n.getCA());
	ASSERT_EQ(0, n.getCost());
}