#include "ConcreteWeaponCreator.h"

ConcreteWeapon ConcreteWeaponCreator::createWeapon(TYPE_OF_WEAPON type) {
	ConcreteWeapon weapon;

	switch (type) {
	case TYPE_OF_WEAPON::AX:
	{
		weapon = ConcreteWeapon(10, "Ax");
		break;

	}
	case TYPE_OF_WEAPON::SWORD: 
	{
		weapon = ConcreteWeapon(15, "Sword");
		break;
	}
	case TYPE_OF_WEAPON::CROSSBOW: 
	{
		weapon = ConcreteWeapon(75, "Crossbow");
		break;
	}
	case TYPE_OF_WEAPON::ARCH: 
	{
		weapon = ConcreteWeapon(50, "Arch");
		break;
	}
	}
	return weapon;
}