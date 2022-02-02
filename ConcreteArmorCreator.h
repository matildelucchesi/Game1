#ifndef CONCRETEARMORCREATOR_H
#define CONCRETEARMORCREATOR_H

#include "ArmorCreator.h"
#include <iostream>
using namespace std;


class ConcreteArmorCreator : public ArmorCreator {
public:
	//Constructor & Destructor
	ConcreteArmorCreator() = default;
	~ConcreteArmorCreator() = default;
	//Create Armor
	std::unique_ptr<ConcreteArmor> createArmor(TYPE_OF_ARMOR type) override;
};

#endif CONCRETEARMORCREATOR_H