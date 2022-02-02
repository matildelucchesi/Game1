#include "Potion.h"

Potion::Potion() {
	setAnimation();
	potionValue = rand() % 50 + 1;

}

void Potion::setPotionValue(int n) {
	this->potionValue = n;
}

int Potion::getPotionValue() const {
	return this->potionValue;
}

void Potion::setAnimation() {
	if (!potionT.loadFromFile("../images/other/potion.png"))
		std::cout << "ERROR::POTION::CAN'T LOAD TEXTURE FILE";
	potionS = sf::Sprite(potionT);
}

sf::Sprite& Potion::getSprite(){
	return this->potionS;
}