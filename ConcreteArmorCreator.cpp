#include "ConcreteArmorCreator.h"

ConcreteArmor ConcreteArmorCreator::createArmor(TYPE_OF_ARMOR type) {
	ConcreteArmor armor;

	switch (type) {
	case TYPE_OF_ARMOR::FULL_ARMOR:
	{
		armor = ConcreteArmor(18, "Full Armor");
		break;
	}
	case TYPE_OF_ARMOR::HALF_ARMOR: 
	{
		armor = ConcreteArmor(15, "Half Armor");
		break;
	}
	case TYPE_OF_ARMOR::PADDED_ARMOR:
	{
		armor = ConcreteArmor(11, "Padded Armor");
		break;
	}
	case TYPE_OF_ARMOR::NONE:
	{
		armor = ConcreteArmor(10, "None");
		break;
	}
	}

	return armor;
}