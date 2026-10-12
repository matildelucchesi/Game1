#ifndef WEAPON_H
#define WEAPON_H

#include "utils/Dice.h"
#include <iostream>
#include <string>

using namespace std;

class Weapon {
public:
	
	virtual std::string getType() const = 0;
	virtual int getCost()  const = 0;
	//Destructor
	~Weapon() = default;
};

#endif 
