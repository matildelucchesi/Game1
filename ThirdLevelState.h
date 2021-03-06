#ifndef  THIRDLEVELSTATE_H
#define THIRDLEVELSTATE_H

#include "SecondLevelState.h"
#include "FightState.h"
#include "Enemy.h"
#include "PausedState.h"
#include "Hero.h"
#include "GameState.h"
#include "Map/TileMap.h"
#include "ObjectAnimation.h"
#include "Playable.h"

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

