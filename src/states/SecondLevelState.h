#ifndef SECONDLEVELSTATE_H
#define SECONDLEVELSTATE_H

#include "states/FirstLevelState.h"
#include "states/FightState.h"
#include "characters/Enemy.h"
#include "states/PausedState.h"
#include "characters/Hero.h"
#include "states/GameState.h"
#include "world/TileMap.h"
#include "animation/ObjectAnimation.h"
#include "states/Playable.h"
#include "states/ThirdLevelState.h"


using namespace std;

#define enemyPos1X 1280.f
#define enemyPos1Y 850.f
#define TposX 1000.f
#define TposY 1700.f

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

#endif 
