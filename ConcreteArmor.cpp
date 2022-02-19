#include "ConcreteArmor.h"
ConcreteArmor::ConcreteArmor() {
	CA = 0;
}

ConcreteArmor::ConcreteArmor(int ca, std::string t) : CA(ca), type(t) {}

std::string ConcreteArmor::getType() const  {
	return this->type;
}

void ConcreteArmor::setCA(int ca) {
	this->CA = ca;
}

int ConcreteArmor::getCA() const {
	return this->CA;
}