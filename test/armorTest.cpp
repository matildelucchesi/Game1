#include <gtest/gtest.h>
#include "C:/Users/Matilde/source/repos/Game/ConcreteArmor.h"
#include "C:/Users/Matilde/source/repos/Game/ConcreteArmorCreator.h"
#include "C:/Users/Matilde/source/repos/Game/ArmorCreator.h"


ConcreteArmorCreator* a = new ConcreteArmorCreator();
std::unique_ptr<ConcreteArmor> ar = a->createArmor(ArmorCreator::TYPE_OF_ARMOR::FULL_ARMOR);

TEST(ConcreteArmor, FullArmorConstructor) {
	ASSERT_EQ(18, ar->getCA());
	ASSERT_EQ(1500, ar->getCost());
	EXPECT_TRUE(ar->getType() == "Full Armor");
}

std::unique_ptr<ConcreteArmor> br = a->createArmor(ArmorCreator::TYPE_OF_ARMOR::HALF_ARMOR);

TEST(ConcreteArmor, HalfArmorConstructor) {
	ASSERT_EQ(15, br->getCA());
	ASSERT_EQ(750, br->getCost());
	EXPECT_TRUE(br->getType() == "Half Armor");
}

std::unique_ptr<ConcreteArmor> cr = a->createArmor(ArmorCreator::TYPE_OF_ARMOR::PADDED_ARMOR);

TEST(ConcreteArmor, PaddedArmorConstructor) {
	ASSERT_EQ(11, cr->getCA());
	ASSERT_EQ(50, cr->getCost());
	EXPECT_TRUE(cr->getType() == "Padded Armor");
}


std::unique_ptr<ConcreteArmor> dr = a->createArmor(ArmorCreator::TYPE_OF_ARMOR::NONE);

TEST(ConcreteArmor, NoneArmorConstructor) {
	ASSERT_EQ(10, dr->getCA());
	ASSERT_EQ(0, dr->getCost());
	EXPECT_TRUE(dr->getType() == "None");
}