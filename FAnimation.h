#pragma once

#ifndef FANIMATION_H
#define FANIMATION_H

#include <memory>
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

using namespace std;

class FAnimation {
public:
	//Constructor & Destructor
	FAnimation() = default;
	FAnimation(sf::Texture notYourTurnTexture, sf::Texture yourTurnTexture);
	~FAnimation() = default;
	//Turn Animation
	void setTurn(bool yourTurn);
	bool getTurn();
	void updateFightAnimation();
	sf::Sprite& getSprite();
	//LP Animation
	void setFightLPAnimation(int LP);
	void updateFightLPAnimation(int LP);
	sf::Sprite& getLPBubble();
	sf::Text& getLPText();
private:
	sf::Texture notYourTurnTexture;
	sf::Texture yourTurnTexture;
	sf::Sprite fightingSprite;
	bool yourTurn;
	sf::Texture lpBubbleTextureF;
	sf::Sprite lpBubbleSpriteF;
	sf::Font font;
	sf::Text LPText;
};


#endif