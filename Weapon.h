#ifndef WEAPON_H
#define WEAPON_H

#include "Dice.h"
#include <iostream>
#include <string>

using namespace std;

class Weapon {
public:
	
	virtual std::string getType() const = 0;
	virtual int getCost()  const = 0;
	//Virtual Destructor
	virtual ~Weapon() = 0;
};

#endif 
