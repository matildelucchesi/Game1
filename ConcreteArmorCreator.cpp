#include "ConcreteArmorCreator.h"

std::unique_ptr<ConcreteArmor> ConcreteArmorCreator::createArmor(TYPE_OF_ARMOR type) {
	std::unique_ptr<ConcreteArmor> armor;

	switch (type) {
	case TYPE_OF_ARMOR::FULL_ARMOR:
	{
		armor = std::unique_ptr<ConcreteArmor>(new ConcreteArmor(18, 1500, "Full Armor"));
		break;
	}
	case TYPE_OF_ARMOR::HALF_ARMOR: 
	{
		armor = std::unique_ptr<ConcreteArmor>(new ConcreteArmor(15, 750, "Half Armor"));
		break;
	}
	case TYPE_OF_ARMOR::PADDED_ARMOR:
	{
		armor = std::unique_ptr<ConcreteArmor>(new ConcreteArmor(11, 50, "Padded Armor"));
		break;
	}
	case TYPE_OF_ARMOR::NONE:
	{
		armor = std::unique_ptr<ConcreteArmor>(new ConcreteArmor(10, 0, "None"));
		break;
	}
	}

	return armor;
}