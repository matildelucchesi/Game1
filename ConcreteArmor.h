#ifndef CONCRETEARMOR_H
#define CONCRETEARMOR_H

#include <iostream>
#include <string>
#include "Armor.h"
using namespace std;

class ConcreteArmor : public Armor {
public:
	//Constructor & Destructor
	ConcreteArmor(int ca, int c, std::string t);
	~ConcreteArmor() = default;

	std::string getType() const override;
	
	void setCA(int ca);
	const int getCA();

	void setCost(int c);
	int getCost() const;

private:
	int CA;
	int cost;
	std::string type;
};

#endif CONCRETEARMOR_H