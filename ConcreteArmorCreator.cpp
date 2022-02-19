#include "ConcreteArmorCreator.h"

ConcreteArmor ConcreteArmorCreator::createArmor(TYPE_OF_ARMOR type) {
	ConcreteArmor armor;

	switch (type) {
	case TYPE_OF_ARMOR::FULL_ARMOR:
	{
		armor = ConcreteArmor(fCA, fullArmorCost, "Full Armor");
		break;
	}
	case TYPE_OF_ARMOR::HALF_ARMOR: 
	{
		armor = ConcreteArmor(hCA , halfArmorCost, "Half Armor");
		break;
	}
	case TYPE_OF_ARMOR::PADDED_ARMOR:
	{
		armor = ConcreteArmor(pCA , paddedArmorCost, "Padded Armor");
		break;
	}
	case TYPE_OF_ARMOR::NONE:
	{
		armor = ConcreteArmor(nCA, noneCost, "None");
		break;
	}
	}

	return armor;
}