#pragma once
#ifndef FIRSTLEVELSTATE_H
#define FIRSTLEVELSTATE_H

#include "states/PlayingState.h"
#include "states/FightState.h"
#include "characters/Enemy.h"
#include "states/PausedState.h"
#include "characters/Hero.h"
#include "states/GameState.h"
#include "world/TileMap.h"
#include "animation/ObjectAnimation.h"
#include "states/Playable.h"
#include "states/SecondLevelState.h"

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