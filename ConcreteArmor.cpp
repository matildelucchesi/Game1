#include "ConcreteArmor.h"
ConcreteArmor::ConcreteArmor() {

}

ConcreteArmor::ConcreteArmor(int ca, int c, std::string t) : CA(ca), cost(c), type(t) {}

std::string ConcreteArmor::getType() const  {
	return this->type;
}

void ConcreteArmor::setCA(int ca) {
	this->CA = ca;
}

int ConcreteArmor::getCA() const {
	return this->CA;
}

void ConcreteArmor::setCost(int c) {
	this->cost = c;
}

int ConcreteArmor::getCost() const  {
	return this->cost;
}