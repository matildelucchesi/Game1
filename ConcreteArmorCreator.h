#ifndef CONCRETEARMORCREATOR_H
#define CONCRETEARMORCREATOR_H

#include "ArmorCreator.h"
#include <iostream>
using namespace std;

#define paddedArmorCost 50
#define halfArmorCost 750
#define fullArmorCost 900
#define noneCost 0
#define pCA 11
#define hCA 15
#define fCA 18
#define nCA 10


class ConcreteArmorCreator : public ArmorCreator {
public:
	//Constructor & Destructor
	ConcreteArmorCreator() = default;
	~ConcreteArmorCreator() = default;
	//Create Armor
	ConcreteArmor createArmor(TYPE_OF_ARMOR type) override;
};

#endif