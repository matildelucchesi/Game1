#pragma once

#ifndef GAME_H
#define GAME_H

#include "StartState.h"
#include <memory>
#include <vector>
#include <iostream>
#include <ctime>


using namespace std;

class Game {
public:
	//Constructor & Destructor
	Game();
	~Game();

	//Game loop
	void update();
	void render();
	void pollEvents();

	const bool running() const;

	sf::RenderWindow* getTarget();

	void handleInput(sf::Event evnt);

	//void setCurrentState(GameState* nextState);

private:
	bool endGame;
	
	void initVariables();
	void initWindow();

	int width;
	int height;

	sf::RenderWindow* window;
	sf::Event evnt;

	//Game objects
	std::string weapon;
	int damage;

	GameState* currentState;
};

#endif GAME_H
