#include "ConcreteWeaponCreator.h"

std::unique_ptr<ConcreteWeapon> ConcreteWeaponCreator::createWeapon(TYPE_OF_WEAPON type) {
	std::unique_ptr<ConcreteWeapon> weapon;

	switch (type) {
	case TYPE_OF_WEAPON::AX:
	{
		weapon = std::unique_ptr<ConcreteWeapon> (new ConcreteWeapon(10, "Ax"));
		
		break;

	}
	case TYPE_OF_WEAPON::SWORD: 
	{
		weapon = std::unique_ptr<ConcreteWeapon>(new ConcreteWeapon(15, "Sword"));
		break;
	}
	case TYPE_OF_WEAPON::CROSSBOW: 
	{
		weapon = std::unique_ptr<ConcreteWeapon>(new ConcreteWeapon(75, "Crossbow"));
		break;
	}
	case TYPE_OF_WEAPON::ARCH: 
	{
		weapon = std::unique_ptr<ConcreteWeapon>(new ConcreteWeapon(50, "Arch"));
		break;
	}
	}
	return weapon;
}