#pragma once
#ifndef RACEMENUSTATE_H
#define RACEMENUSTATE_H

#include "GameState.h"
#include "ClassMenuState.h"

#define NUMBER_OF_RACE 5

enum class RACE { HUMAN, DRAGONBORN, TIEFLING, ELF, DWARF };

class RaceMenuState : public GameState{
public:
	//Constructor & Destructor
	RaceMenuState();
	~RaceMenuState() = default;

	GameState* handleInput(sf::Event evnt) override;
	void render(sf::RenderTarget* target) override;
	void update() override;
	void initRaceText();
	void initHeroSprite();
	void setBackground() override;

private:
	int r;
	sf::Text race;
	sf::Text text;
	sf::Texture heroTexture;
	sf::Sprite heroImage;
	sf::Texture right;
	sf::Sprite rightArrow;
	sf::Texture left;
	sf::Sprite leftArrow;
};

#endif RACEMENUSTATE_H