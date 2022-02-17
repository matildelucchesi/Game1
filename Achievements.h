#ifndef ACHIEVEMENTS_H
#define ACHIEVEMENTS_H

#include "Observer.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

using namespace std;

class Achievements : public Observer{
public:
	//Constructor & Destructor
	Achievements();
	~Achievements() = default;
	//Update Treasure
	void updateTreasure() override;
	//Update Statue
	void updateStatue() override;
	//Animation
	void setAnimation();
	void render(sf::RenderTarget* target);
	void update(sf::View v);
	bool getAchieve() const;
	void setAchieve(bool a);

private:
	int countT;
	int countS;
	sf::Texture messageBubble;
	sf::Sprite messageBubbleS;
	sf::Text text;
	sf::Font font;
	bool achieve;
	
};


#endif
