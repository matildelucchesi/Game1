#ifndef DICE_H
#define DICE_H

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

using namespace std;

class Dice {
public:
	//Constructor & Destructor
	Dice();
	~Dice() = default;
	//Animation
	void setAnimation();
	void render(sf::RenderTarget* target);
	sf::Sprite getSprite();
	void setColor(sf::Color color);
	//Use
	int use(int f);

private:
	sf::Texture texture;
	sf::Sprite sprite;
};

#endif