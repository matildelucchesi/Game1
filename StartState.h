#pragma once
#ifndef STARTSTATE_H
#define STARTSTATE_H

#include "GameState.h"
#include "RaceMenuState.h"

class StartState : public GameState {
public:
	//Constructor & Destructor
	StartState();
	~StartState() = default;

	GameState* handleInput(sf::Event evnt) override;
	void render(sf::RenderTarget* target) override;
	void update() override;
	void setBackground() override;
	void setTitle();
private:
	sf::Text title;
	sf::Text text;
	sf::Texture texture;
	sf::Sprite sprite;
};

#endif STARTSTATE_H