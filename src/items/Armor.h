#ifndef ARMOR_H
#define ARMOR_H

#include <iostream>
using namespace std;

class Armor {
public:
	virtual std::string getType() const = 0;
	virtual int getCost() const = 0;
	//Destructor
	~Armor() = default;
};


#endif