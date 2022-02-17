#pragma once
#ifndef FIRSTLEVELSTATE_H
#define FIRSTLEVELSTATE_H

#include "PlayingState.h"
#include "FightState.h"
#include "Enemy.h"
#include "PausedState.h"
#include "Hero.h"
#include "GameState.h"
#include "Map/TileMap.h"
#include "ObjectAnimation.h"
#include "Playable.h"
#include "SecondLevelState.h"

class PlayingState;
class SecondLevelState;

enum class MESSAGE{STATUE, TREASURE, POTION, EMPTY, ENEMY};

#define enemyPosX 1355.f
#define enemyPosY 1150.f
#define heroSecondLevelPosX 2000.f
#define heroSecondLevelPosY 1500.f

class FirstLevelState : public GameState, public Playable {
public:
	//Constructor & Destructor
	FirstLevelState(PlayingState& playingState, PausedState& pausedState);
	~FirstLevelState() = default;

	GameState* handleInput(sf::Event evnt) override;
	void render(sf::RenderTarget* target) override;
	void update() override;
	void setBackground() override;

private:
	PlayingState& playingState_;
	//Hero
	std::shared_ptr<Hero> h;
	bool canMove;
	//Enemy
	std::shared_ptr<Enemy> e;
	bool live;
	
	//View
	sf::Vector2f pos;
	//Message bubble
	short type;
	bool mex;
	sf::Text text;
	sf::Texture message;
	unsigned int character = 0;
	sf::String string_;

	//paused state
	PausedState* p;
};

#endif 