#pragma once
#ifndef ARMORMENUSTATE_H
#define ARMORMENUSTATE_H

#include "GameState.h"
#include "PlayingState.h"

#define NUMBER_OF_ARMOR 4

class PlayingState;

class ArmorMenuState : public GameState {
public:
	//Constructor & Destructor
	ArmorMenuState(PlayingState& playingState);
	~ArmorMenuState() = default;
	
	GameState* handleInput(sf::Event evnt) override;
	void render(sf::RenderTarget* target) override;
	void update() override;
	void setBackground() override;
	void initArmorText();
	void chooseArmor();
	void initCAText();
private:

	PlayingState& play;
	//Gold Coins
	sf::Text coinsA;

	//font 
	sf::Font f1;
	//Arrows
	sf::Texture right;
	sf::Sprite rightArrow;
	sf::Texture left;
	sf::Sprite leftArrow;
	//Title
	sf::Text titleA;
	//Armor
	short a;
	sf::Text armor[NUMBER_OF_ARMOR];
	std::string aType;
	//CA
	sf::Text ca;
	//control
	bool canBuy;
};

#endif ARMORMENUSTATE_H

