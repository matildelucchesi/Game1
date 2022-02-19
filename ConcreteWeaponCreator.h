#ifndef CONCRETEWEAPONCREATOR_H
#define CONCRETEWEAPONCREATOR_H

#include "WeaponCreator.h"
#include "ConcreteWeapon.h"

#define archCost 50
#define axCost 10
#define crossbowCost 75
#define swordCost 15

class ConcreteWeaponCreator : public WeaponCreator {
public:
	//Constructor & Destructor
	ConcreteWeaponCreator() = default;
	~ConcreteWeaponCreator() = default;
	//Create Weapon
	ConcreteWeapon createWeapon(TYPE_OF_WEAPON type) override;

};

#endif