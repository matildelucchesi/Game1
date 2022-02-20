#include "ConcreteWeaponCreator.h"

ConcreteWeapon ConcreteWeaponCreator::createWeapon(TYPE_OF_WEAPON type) {
	ConcreteWeapon weapon;

	switch (type) {
	case TYPE_OF_WEAPON::AX:
	{
		weapon = ConcreteWeapon(axCost, "Ax");
		break;

	}
	case TYPE_OF_WEAPON::SWORD: 
	{
		weapon = ConcreteWeapon(swordCost, "Sword");
		break;
	}
	case TYPE_OF_WEAPON::CROSSBOW: 
	{
		weapon = ConcreteWeapon(crossbowCost, "Crossbow");
		break;
	}
	case TYPE_OF_WEAPON::ARCH: 
	{
		weapon = ConcreteWeapon(archCost, "Arch");
		break;
	}
	}
	return weapon;
}