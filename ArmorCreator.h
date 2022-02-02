#ifndef ARMORCREATOR_H
#define ARMORCREATOR_H

#include <iostream>
#include <memory>
#include "ConcreteArmor.h"

using namespace std;

class ArmorCreator {
public:
	enum class TYPE_OF_ARMOR { FULL_ARMOR, HALF_ARMOR, PADDED_ARMOR, NONE };
	virtual std::unique_ptr<ConcreteArmor> createArmor(TYPE_OF_ARMOR type)= 0;
	//Virtual Destructor
	virtual ~ArmorCreator() = 0;
};

#endif ARMORCREATOR_H
