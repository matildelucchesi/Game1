#ifndef SECONDLEVELSTATE_H
#define SECONDLEVELSTATE_H

#include "FirstLevelState.h"
#include "FightState.h"
#include "Enemy.h"
#include "PausedState.h"
#include "Hero.h"
#include "GameState.h"
#include "Map/TileMap.h"
#include "ObjectAnimation.h"
#include "Playable.h"
#include "ThirdLevelState.h"


using namespace std;

#define enemyPosX 1280.f
#define enemyPosY 850.f
#define TposX 1000.f
#define TposY 2000.f

class FirstLevelState;
class ThirdLevelState;

class SecondLevelState : public GameState, public Playable {
public:
	//Constructor & Destructor
	SecondLevelState(FirstLevelState& firstState, PausedState& pause);
	~SecondLevelState() = default;
	//tile map
	void setBackground() override;
	//Game State
	GameState* handleInput(sf::Event evnt) override;
	void render(sf::RenderTarget* target) override;
	void update() override;

private:
	//other states
	FirstLevelState& first;
	PausedState* p;
	//tile map
	sf::Vector2f pos;
	sf::String str;
};

#endif SECONDLEVELSTATE_H