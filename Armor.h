#ifndef ARMOR_H
#define ARMOR_H

#include <iostream>
using namespace std;

class Armor {
public:
	virtual std::string getType() const = 0;
	//Virtual Destructor
	virtual ~Armor() = 0;
};


#endif