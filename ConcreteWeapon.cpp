#include "ConcreteWeapon.h"
ConcreteWeapon::ConcreteWeapon() {

}

ConcreteWeapon::ConcreteWeapon(int c, std::string t) {
	this->setCost(c);
	this->setType(t);
}

void ConcreteWeapon::setType(std::string t) {
	this->type = t;
}

std::string ConcreteWeapon::getType() const {
	return this->type;
}

void ConcreteWeapon::setCost(int c) {
	this->cost = c;
}

int ConcreteWeapon::getCost() const  {
	return this->cost;
}