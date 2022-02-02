#pragma once
#ifndef CLASSMENUSTATE_H
#define CLASSMENUSTATE_H

#include "GameState.h"
#include "PlayingState.h"

#define NUMBER_OF_CLASSES 4

enum class CLASSES{BARBARIAN, DRUID, WARRIOR, WIZARD};

class ClassMenuState : public GameState{
public:
	//Cosntructor & Destructor
	ClassMenuState(short race);
	~ClassMenuState() = default;

	GameState* handleInput(sf::Event evnt) override;
	void render(sf::RenderTarget* target) override;
	void update() override;
	void setBackground() override;
	void initClassText();

private:
	sf::Text text;
	sf::Text classes[NUMBER_OF_CLASSES];
	short cl;
	short r;
};

#endif CLASSMENUSTATE_H
