#ifndef POTION_H
#define POTION_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>

using namespace std;

class Potion {
public:
	//Constructor & Destructor
	Potion();
	~Potion() = default;

	int getPotionValue() const;
	void setPotionValue(int n);

	sf::Sprite& getSprite();

	void setAnimation();

private:
	int potionValue;
	sf::Texture potionT;
	sf::Sprite potionS;
};

#endif 