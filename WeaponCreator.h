#ifndef WEAPONCREATOR_H
#define WEAPONCREATOR_H

#include <memory>
#include <iostream>
#include "ConcreteWeapon.h"

using namespace std;

class WeaponCreator {
public:
	enum class TYPE_OF_WEAPON{AX, SWORD, CROSSBOW, ARCH};

	virtual ConcreteWeapon createWeapon(TYPE_OF_WEAPON type) = 0;

	//Virtual Destructor
	virtual ~WeaponCreator() = 0 {};
};

#endif
