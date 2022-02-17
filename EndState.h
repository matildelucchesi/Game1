#pragma once
#ifndef ENDSTATE_H
#define ENDSTATE_H

#include "GameState.h"

class EndState : public GameState {
public:
	//Constructor & Destructor
	EndState();
	~EndState() = default;

	GameState* handleInput(sf::Event evnt) override;
	void render(sf::RenderTarget* target) override;
	void update() override;
	void setBackground() override;

private:
	sf::Texture background;
	sf::Sprite backgroundS;
	sf::Text endMessage;
};

#endif 