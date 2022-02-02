#ifndef CONCRETEWEAPONCREATOR_H
#define CONCRETEWEAPONCREATOR_H

#include "WeaponCreator.h"
#include "ConcreteWeapon.h"

class ConcreteWeaponCreator : public WeaponCreator {
public:
	//Constructor & Destructor
	ConcreteWeaponCreator() = default;
	~ConcreteWeaponCreator() = default;
	//Create Weapon
	std::unique_ptr<ConcreteWeapon> createWeapon(TYPE_OF_WEAPON type) override;

};

#endif CONCRETEWEAPONCREATOR_H