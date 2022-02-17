#pragma once
#ifndef PLAYINGSTATE_H
#define PLAYINGSTATE_H

#include "GameState.h"
#include "Hero.h"
#include "Enemy.h"
#include "WeaponMenuState.h"
#include "FirstLevelState.h"
#include "PausedState.h"
#include "Map/Tile.h"
#include "Map/TileMap.h"
#include "Playable.h"
#include <memory>
#include <string.h>
#include <iostream>
#include <sstream>

using namespace std;

class WeaponMenuState;
class ArmorMenuState;
class FirstLevelState;
class PausedState;

#define heroNewLevelPosX 1900.f
#define heroNewLevelPosY 300.f

class PlayingState : public GameState, public Playable {
public:
	//Constructor & Destructor
	PlayingState(short race, short cl);
	~PlayingState() = default;

	GameState* handleInput(sf::Event evnt) override;
	void render(sf::RenderTarget* target) override;
	void update() override;

	//Hero
	void setRace(short race);
	void setClass(short cl);

	//render stuff
	void setBackground() override;
	void openCastleMessage();
	
private:
	sf::View view;
	sf::Vector2f position;
	short hr;
	short c;
	std::string a;
	std::string w;
	
	int gc;
	//Message bubble
	sf::Text text;
	sf::Texture message;
	sf::Sprite messageBubble;
	sf::Clock timer;
	unsigned int character = 0;
	sf::String str;
	//Time
	sf::Clock gameTimer;
	//paused state
	PausedState* pause;
};

#endif