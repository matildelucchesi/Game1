#ifndef  THIRDLEVELSTATE_H
#define THIRDLEVELSTATE_H

#include "states/SecondLevelState.h"
#include "states/FightState.h"
#include "characters/Enemy.h"
#include "states/PausedState.h"
#include "characters/Hero.h"
#include "states/GameState.h"
#include "world/TileMap.h"
#include "animation/ObjectAnimation.h"
#include "states/Playable.h"

using namespace std;

class SecondLevelState;

#define ePosX 1025.f
#define ePosY 480.f

class ThirdLevelState : public GameState, public Playable {
public:
	//Constructor & Destructor
	ThirdLevelState(SecondLevelState& secondState, PausedState& pause);
	~ThirdLevelState() = default;
	//tile map
	void setBackground() override;
	//Game State
	GameState* handleInput(sf::Event evnt) override;
	void render(sf::RenderTarget * target) override;
	void update() override;

private:
	//other states
	PausedState* p;
	//tile map
	sf::Vector2f pos;
	sf::String str;
};


#endif 

