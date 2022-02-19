#ifndef CONCRETEARMOR_H
#define CONCRETEARMOR_H

#include <iostream>
#include <string>
#include "Armor.h"
using namespace std;

class ConcreteArmor : public Armor {
public:
	//Constructor & Destructor
	ConcreteArmor();
	ConcreteArmor(int ca, std::string t);
	~ConcreteArmor() = default;

	std::string getType() const override;
	
	void setCA(int ca);
	int getCA() const;

private:
	int CA;
	std::string type;
};

#endif