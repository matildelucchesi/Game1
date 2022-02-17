#include "Dice.h"

Dice::Dice() {
	srand((int)time(NULL));
	setAnimation();
}

int Dice::use(int f) {
	return rand() % f + 1;
}

void Dice::setAnimation() {
	if (!texture.loadFromFile("../images/other/dice.png"))
		std::cout << "Can't load the image";
	sprite.setTexture(texture);
	sprite.setPosition(425.f, 200.f);
}

void Dice::render(sf::RenderTarget* target){
	target->draw(sprite);
}

sf::Sprite Dice::getSprite() {
	return this->sprite;
}

void Dice::setColor(sf::Color color) {
	sprite.setColor(color);
}