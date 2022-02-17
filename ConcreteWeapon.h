#ifndef CONCRETEWEAPON_H
#define CONCRETEWEAPON_H

#include "Weapon.h"

class ConcreteWeapon : public Weapon {
public:
	//Constructor & Destructor
	ConcreteWeapon();
	ConcreteWeapon(int c, std::string t);
	~ConcreteWeapon() = default;
	//Weapon Stuff
	void setType(std::string t);
	std::string getType() const override;
	void setCost(int c);
	int getCost() const override;

private:
	int cost;
	std::string type;
	
};
#endif
